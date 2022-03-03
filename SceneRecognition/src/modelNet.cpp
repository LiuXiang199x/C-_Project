#include <../include/rl_api.h>

using namespace std;
using namespace everest;
using namespace everest::ai;

SceneApi::SceneApi()
{
	visited_map = std::vector<std::vector<int>>(1440, std::vector<int>(1440, 0));
}

SceneApi::~SceneApi()
{
	
}

uint64_t SceneApi::time_tToTimestamp(const time_t &t ){
    return (((uint64_t)t) * (uint64_t)10000000) + ((uint64_t)116444736*1000000000);
}

uint64_t SceneApi::get_sys_time_interval(){
    timespec  tim;
    clock_gettime(CLOCK_MONOTONIC, &tim);
    return (time_tToTimestamp( tim.tv_sec ) + tim.tv_nsec/100)/10000;
}

void SceneApi::printRKNNTensor(rknn_tensor_attr *attr) {
    printf("index=%d name=%s n_dims=%d dims=[%d %d %d %d] n_elems=%d size=%d fmt=%d type=%d qnt_type=%d fl=%d zp=%d scale=%f\n", 
            attr->index, attr->name, attr->n_dims, attr->dims[3], attr->dims[2], attr->dims[1], attr->dims[0], 
            attr->n_elems, attr->size, 0, attr->type, attr->qnt_type, attr->fl, attr->zp, attr->scale);
}

unsigned char* SceneApi::load_model(const char *filename, int *model_size)
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


void SceneApi::release_rknn(){
	// Release rknn_outputs
	rknn_outputs_release(ctx, 1, outputs);

	// Release
	if (ctx >= 0) {
		rknn_destroy(ctx);
	}
	if (model) {
		free(model);
	}
}

int SceneApi::init_rknn(){
	// Load RKNN Model
	model = load_model(model_path, &model_len);

	// end_load_model_time = GetTickCount();

	ret = rknn_init(&ctx, model, model_len, 0);

	if (ret < 0) {
		printf("rknn_init fail! ret=%d\n", ret);
		return -1;
	}

	////// Get Model Input Output Info

	ret = rknn_query(ctx, RKNN_QUERY_IN_OUT_NUM, &io_num, sizeof(io_num));
	if (ret != RKNN_SUCC) {
		printf("rknn_query fail! ret=%d\n", ret);
		return -1;
	}
	printf("model input num: %d, output num: %d\n", io_num.n_input, io_num.n_output);


	return 0;
}



bool SceneApi::processTarget(const int &idx, const int &idy, int &res_idx, int &res_idy) {

	/////////// init_rknn ////////
	// Load RKNN Model
	model = load_model(model_path, &model_len);

	// end_load_model_time = GetTickCount();

	ret = rknn_init(&ctx, model, model_len, 0);

	if (ret < 0) {
		printf("rknn_init fail! ret=%d\n", ret);
		return -1;
	}

	////// Get Model Input Output Info
	ret = rknn_query(ctx, RKNN_QUERY_IN_OUT_NUM, &io_num, sizeof(io_num));
	if (ret != RKNN_SUCC) {
		printf("rknn_query fail! ret=%d\n", ret);
		return -1;
	}
	printf("model input num: %d, output num: %d\n", io_num.n_input, io_num.n_output);
	/////　init_rknn done ////////

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

	// Set Input Data
	rknn_input inputs[1];
	memset(inputs, 0, sizeof(inputs));
	inputs[0].index = 0;
	inputs[0].type = RKNN_TENSOR_UINT8;
	// inputs[0].size = img.cols*img.rows*img.channels() * BATCH_SIZE;
	inputs[0].size = 240 * 240 * 8 * BATCH_SIZE;
	inputs[0].fmt = RKNN_TENSOR_NHWC;
	inputs[0].buf = batch_img_data;

	ret = rknn_inputs_set(ctx, io_num.n_input, inputs);
	if (ret < 0) {
		printf("rknn_input_set fail! ret=%d\n", ret);
		return -1;
	}

	// Run
	printf("rknn_run\n");
	ret = rknn_run(ctx, nullptr);
	if (ret < 0) {
		printf("rknn_run fail! ret=%d\n", ret);
		return -1;
	}

	// Get Output

	memset(outputs, 0, sizeof(outputs));
	outputs[0].want_float = 1;
	ret = rknn_outputs_get(ctx, 1, outputs, NULL);
	if (ret < 0) {
		printf("rknn_outputs_get fail! ret=%d\n", ret);
		return -1;
	}


	vector<float> output(240 * 240);
	int leng = output_attrs[0].n_elems / BATCH_SIZE;
	// Post Process
	for (int i = 0; i < output_attrs[0].n_elems; i++) {

		float val = ((float*)(outputs[0].buf))[i];
		// printf("----->%d - %f\n", i, val);
		output[i] = val;
		// printf("size of ouput:%d\n", output.size());
	}


	printf("[1]:%f, [2]:%f, [3]:%f\n", output[0], output[1], output[2]);
	printf("======== Getting target done ========\n");
	pro_target(output, expand_type, frontier_map, res_idx, res_idy);

	/*
	int flag_end = 0;

	for (int i = 0; i < 240; i++) {
		for (int j = 0; j < 240; j++) {
			if (Frontier_crop[i][j] == 1) {
				flag_end = flag_end + 1;
			}
		}
	}

	if (flag_end == 0) {
		printf("There is no frontier left on the map\n");
	}
	*/

	return true;
}




import resnet_net
import torch
import torch.nn as nn

class Object_Linear(nn.Module):
    def __init__(self):
        super(Object_Linear, self).__init__()
        self.fc = nn.Linear(13, 512)
    def forward(self, x):
        out = self.fc(x)
        return out

class LinClassifier(nn.Module):
    def __init__(self, num_classes):
        super(LinClassifier, self).__init__()
        self.num_classes = num_classes
        self.fc = nn.Linear(1024, num_classes)
    def forward(self, conv, idt):
        out = torch.cat((conv, idt), 1)
        out = self.fc(out)
        return out

class AllModel(nn.Module):
    def __init__(self, num_classes):
        super(AllModel, self).__init__()
        self.num_classes = num_classes
        self.classifier = LinClassifier(num_classes)
        self.object_idt = Object_Linear()
        model = resnet_net.resnet18(num_classes=num_classes) # to be commented
        self.model = model

    def forward(self, x_rgb, x_onehot):
        output_conv = self.model(x_rgb)  # 1*512
        output_idt1 = self.object_idt(x_onehot)  # 1*512
        output_idt2 = output_idt1.unsqueeze(0)
        output = self.classifier(output_conv, output_idt2)
        return output