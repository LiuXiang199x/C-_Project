#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <string.h>
#include <uchar.h>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

#include "rknn_api.h"

using namespace std;
using namespace cv;

#define BATCH_SIZE 1
#define uchar unsigned char

#define img_width 64
#define img_height 64
#define img_channels 3

/*-------------------------------------------
                  Functions
-------------------------------------------*/

uint64_t time_tToTimestamp(const time_t &t ){
    return (((uint64_t)t) * (uint64_t)10000000) + ((uint64_t)116444736*1000000000);
}

uint64_t get_sys_time_interval(){
    timespec  tim;
    clock_gettime(CLOCK_MONOTONIC, &tim);
    return (time_tToTimestamp( tim.tv_sec ) + tim.tv_nsec/100)/10000;
}

static void printRKNNTensor(rknn_tensor_attr *attr) {
    printf("index=%d name=%s n_dims=%d dims=[%d %d %d %d] n_elems=%d size=%d fmt=%d type=%d qnt_type=%d fl=%d zp=%d scale=%f\n", 
            attr->index, attr->name, attr->n_dims, attr->dims[3], attr->dims[2], attr->dims[1], attr->dims[0], 
            attr->n_elems, attr->size, 0, attr->type, attr->qnt_type, attr->fl, attr->zp, attr->scale);
}

static unsigned char *load_model(const char *filename, int *model_size)
{
    FILE *fp = fopen(filename, "rb");
    if(fp == nullptr) {
        printf("fopen %s fail!\n", filename);
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    int model_len = ftell(fp);
    unsigned char *model = (unsigned char*)malloc(model_len);
    fseek(fp, 0, SEEK_SET);
    if(model_len != fread(model, 1, model_len, fp)) {
        printf("fread %s fail!\n", filename);
        free(model);
        return NULL;
    }
    *model_size = model_len;
    if(fp) {
        fclose(fp);
    }
    return model;
}

/*-------------------------------------------
                  Main Function
-------------------------------------------*/
int main(int argc, char** argv)
{
    // const int img_width = 224;
    // const int img_height = 224;
    // const int img_channels = 3;

    rknn_context ctx;
    int ret;
    int model_len = 0;
    unsigned char *model;

    const char *model_path = "/home/agent/C-_Project/ONNX_RKNN/scene/model/SceneResnet18_18pth.rknn";
    const char *img_path = argv[2];
    // const char *img_path2 = argv[3];
    // unsigned long start_time,end_load_model_time, stop_time;
    timeval start_time,end_load_model_time,end_init_time,end_run_time,end_process_time, stop_time;
    gettimeofday(&start_time, nullptr);
    // start_time = GetTickCount();
    long startt = get_sys_time_interval();

    // Load image
    cv::Mat img = cv::imread("/home/agent/C-_Project/ONNX_RKNN/scene/src/1.jpg");
    // img = get_net_work_img(img);

    // Load RKNN Model
    model = load_model(model_path, &model_len);
    gettimeofday(&end_load_model_time, nullptr);
    // end_load_model_time = GetTickCount();
    long end_load_model = get_sys_time_interval();
    printf("end load model time:%ldms\n",end_load_model);
    
    ret = rknn_init(&ctx, model, model_len, 0);
    gettimeofday(&end_init_time, nullptr);
    // end_load_model_time = GetTickCount();
    long end_init = get_sys_time_interval();
    printf("end init model time:%ldms\n",end_init);
    if(ret < 0) {
        printf("rknn_init fail! ret=%d\n", ret);
        return -1;
    }

    ////// Get Model Input Output Info
    rknn_input_output_num io_num;
    ret = rknn_query(ctx, RKNN_QUERY_IN_OUT_NUM, &io_num, sizeof(io_num));
    if (ret != RKNN_SUCC) {
        printf("rknn_query fail! ret=%d\n", ret);
        return -1;
    }
    printf("model input num: %d, output num: %d\n", io_num.n_input, io_num.n_output);

    printf("input tensors:\n");
    rknn_tensor_attr input_attrs[io_num.n_input];
    memset(input_attrs, 0, sizeof(input_attrs));
    for (int i = 0; i < io_num.n_input; i++) {
        input_attrs[i].index = i;
        ret = rknn_query(ctx, RKNN_QUERY_INPUT_ATTR, &(input_attrs[i]), sizeof(rknn_tensor_attr));
        if (ret != RKNN_SUCC) {
            printf("rknn_query fail! ret=%d\n", ret);
            return -1;
        }
        printRKNNTensor(&(input_attrs[i]));
    }


    printf("output tensors:\n");
    rknn_tensor_attr output_attrs[io_num.n_output];
    memset(output_attrs, 0, sizeof(output_attrs));
    for (int i = 0; i < io_num.n_output; i++) {
        output_attrs[i].index = i;
        ret = rknn_query(ctx, RKNN_QUERY_OUTPUT_ATTR, &(output_attrs[i]), sizeof(rknn_tensor_attr));
        if (ret != RKNN_SUCC) {
            printf("rknn_query fail! ret=%d\n", ret);
            return -1;
        }
        printRKNNTensor(&(output_attrs[i]));
    }

    uchar batch_img_data[img.cols*img.rows*img.channels() * BATCH_SIZE];
    memcpy(batch_img_data, img.data, img.cols*img.rows*img.channels());
    // data -> const char*

    // Set Input Data
    rknn_input inputs[1];
    memset(inputs, 0, sizeof(inputs));
    inputs[0].index = 0;
    inputs[0].type = RKNN_TENSOR_UINT8;
    inputs[0].size = img.cols*img.rows*img.channels() * BATCH_SIZE;
    // inputs[0].size = 240*240*8 * BATCH_SIZE;
    inputs[0].fmt = RKNN_TENSOR_NHWC;
    inputs[0].buf = batch_img_data;

    ret = rknn_inputs_set(ctx, io_num.n_input, inputs);
    if(ret < 0) {
        printf("rknn_input_set fail! ret=%d\n", ret);
        return -1;
    }

    // Run
    printf("rknn_run\n");
    ret = rknn_run(ctx, nullptr);
    if(ret < 0) {
        printf("rknn_run fail! ret=%d\n", ret);
        return -1;
    }

    // Get Output
    rknn_output outputs[1];
    memset(outputs, 0, sizeof(outputs));
    outputs[0].want_float = 1;
    ret = rknn_outputs_get(ctx, 1, outputs, NULL);
    if(ret < 0) {
        printf("rknn_outputs_get fail! ret=%d\n", ret);
        return -1;
    }

    long stop = get_sys_time_interval();
    // stop_time = GetTickCount();
    printf("detect spend time--------:%ldms\n",stop - end_init);
    printf("end detect time:%lds\n",stop);

    int leng = output_attrs[0].n_elems/BATCH_SIZE;
    // Post Process
    for (int i = 0; i < output_attrs[0].n_elems; i++) {

        float val = ((float*)(outputs[0].buf))[i];
        printf("----->%d - %f\n", i, val);

        // printf("size of ouput:%d\n", output.size());
    }

   
    printf("detect spend time--------:%ldms\n", stop - end_init);
    printf("end detect time: %lds\n", stop);

    // output -> output
    // Release rknn_outputs
    rknn_outputs_release(ctx, 1, outputs);

    // Release
    if(ctx >= 0) {
        rknn_destroy(ctx);
    }
    if(model) {
        free(model);
    }
    return 0;
}