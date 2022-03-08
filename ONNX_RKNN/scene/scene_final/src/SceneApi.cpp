#include <everest/ai/SceneApi.h>



int SceneApi::ini()
{
    const int img_width = 224;
    const int img_height = 224;
    const int img_channels = 3;

    int ret=0;
    int model_len = 0;

    const char *model_path = "..";

    // Load RKNN Model
    printf("Loading model ...\n");
    m_model = load_model(model_path, &model_len);
    ret = rknn_init(&m_ctx, m_model, model_len, 0);
    if(ret < 0) {
        printf("rknn_init fail! ret=%d\n", ret);
        return -1;
    }

}

SceneApi::~SceneApi()
{
    // Release
    if(m_ctx >= 0) {
        rknn_destroy(m_ctx);
    }
    if(m_model) {
        free(m_model);
    }

}





int SceneApi::predScene(const cv::Mat& bgr){

    cv::Mat img = bgr.clone();

    int ret=0;
    int img_w = bgr.cols;
    int img_h = bgr.rows;
    int img_width=224;
    int img_height=224;


    cv::Mat resized_img;
    object_rect effect_roi;
    resize_uniform(img, resized_img, cv::Size(img_width, img_height), effect_roi);

    if(!bgr.data) {
        printf("cv::imread fail!\n");
        return -1;
    }
//     img=resized_img;
//     if(img.cols != img_height || img.rows != img_height) {
//         printf("resize %d %d to %d %d\n", img.cols, img.rows, img_width, img_height);
//         cv::resize(img, img, cv::Size(img_width, img_height), (0, 0), (0, 0), cv::INTER_CUBIC);
//     }
//  //    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);

    // Get Model Input Output Info
    rknn_input_output_num io_num;
    ret = rknn_query(m_ctx, RKNN_QUERY_IN_OUT_NUM, &io_num, sizeof(io_num));
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
        ret = rknn_query(m_ctx, RKNN_QUERY_INPUT_ATTR, &(input_attrs[i]), sizeof(rknn_tensor_attr));
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
        ret = rknn_query(m_ctx, RKNN_QUERY_OUTPUT_ATTR, &(output_attrs[i]), sizeof(rknn_tensor_attr));
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
    inputs[0].size = img.cols*img.rows*img.channels();
    inputs[0].fmt = RKNN_TENSOR_NHWC;
    inputs[0].buf = img.data;

    ret = rknn_inputs_set(m_ctx, io_num.n_input, inputs);
    if(ret < 0) {
        printf("rknn_input_set fail! ret=%d\n", ret);
        return -1;
    }

    // Run
    printf("rknn_run\n");

    int64 t1=getCurrentLocalTimeStamp();
    ret = rknn_run(m_ctx, nullptr);
    if(ret < 0) {
        printf("rknn_run fail! ret=%d\n", ret);
        return -1;
    }

    // Get Output
    rknn_output outputs[1];
    memset(outputs, 0, sizeof(outputs));
    outputs[0].want_float = 1;
 //   outputs[1].want_float = 1;
    ret = rknn_outputs_get(m_ctx, io_num.n_output, outputs, NULL);
    if(ret < 0) {
        printf("rknn_outputs_get fail! ret=%d\n", ret);
        return -1;
    }


}