#ifndef LIQUID_H
#define LIQUID_H
//#include "commdef.h"
// matrix_cal1.cpp
#include <iostream>
#include "Eigen/Dense"
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sys/time.h>
#include <string.h>
#include <uchar.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

#include <aa.h>   // everest/ai.h
#include "rknn_api.h"

#include <vector>
#include <string>
#include <math.h>


namespace everest{
    namespace ai{
        class SceneNet{
            public:
                TAIObjectClass roomType;

                SceneNet();
                ~SceneNet();
                // rknn_context m_ctx;
                unsigned char *m_model;

                void sceneClass(double *Nanodet_res, double *Scene_res);
                void load_params();
                int init_rknn();
            
            private:
                Eigen::Matrix<double, 5, 1> class_fc_bias;
                Eigen::Matrix<double, 512, 1> obj_fc_bias;
                Eigen::Matrix<double, 5, 1024> class_fc_weight;
                Eigen::Matrix<double, 512, 13> obj_fc_weight;
        };
    }
}
#endif // LIQUID_H