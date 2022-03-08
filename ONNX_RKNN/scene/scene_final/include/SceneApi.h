#ifndef LIQUID_H
#define LIQUID_H
//#include "commdef.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <everest/ai.h>
#include "rknn_api.h"
#include <everest/ai/CTofParameters.h>

#include <vector>
#include <string>
#include <math.h>



namespace everest
{
    namespace ai
    {
        class SceneApi
        {
            public:
                int input_size[2] = {416, 416}; // input height and width
                int num_class = 3; // number of classes. 80 for COCO
                int reg_max = 7; // `reg_max` set in the training config. Default: 7.
                int m_init_success=0;
                std::vector<int> strides = { 8, 16, 32, 64 }; // strides of the multi-level feature.
            public:
                SceneApi();
                ~SceneApi();
                rknn_context m_ctx;
                unsigned char *m_model;

                bool NanoInitOk(){ return m_init_success>=0;}
            public:
                int ini();
                void printRKNNTensor(rknn_tensor_attr *attr);
                unsigned char *load_model(const char *filename, int *model_size);
                int SceneApi::predScene(const cv::Mat& bgr);

                int getScene();
        };
    }
}
#endif // LIQUID_H
