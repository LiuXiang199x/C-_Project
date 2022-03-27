// #include "SceneNet.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include "rknn_api.h"
/*
    one_hot_selected_objects[0] = one_hot_all_objects[0]
    one_hot_selected_objects[1] = one_hot_all_objects[2]
    one_hot_selected_objects[2] = one_hot_all_objects[4]
    one_hot_selected_objects[3] = one_hot_all_objects[5]
    one_hot_selected_objects[4] = one_hot_all_objects[6]
    one_hot_selected_objects[5] = one_hot_all_objects[9]
    one_hot_selected_objects[6] = one_hot_all_objects[11]
    one_hot_selected_objects[7] = one_hot_all_objects[15]
    one_hot_selected_objects[8] = one_hot_all_objects[16]
    one_hot_selected_objects[9] = one_hot_all_objects[17]
    one_hot_selected_objects[10] = one_hot_all_objects[18]
    one_hot_selected_objects[11] = one_hot_all_objects[21]
    one_hot_selected_objects[12] = one_hot_all_objects[23]

    ['bed_room', 'dining_room', 'drawing_room', 'others', 'toilet']
*/

/*
["bed"-0, "cabinet"-1, "chair_base"-2, "cupboard"-3, "dining_table"-4, 
"door_anno"-5, "refrigerator"-6, "sofa"-7, "tea_table"-8, "toilet"-9, 
"TV_stand"-10, "metal_chair_foot"-11, "washing_machine"-12]
*/

using namespace std;

int main()
{
	printf("hello world\n");
    
    cv::Mat img = cv::imread("/home/agent/C-_Project/test_models_rknn/val/bed_room/RGB100W_542500000083_116445085381751238.jpg");
    if(img.empty()) return -1;
    
    // cout << img.type() << endl;    // 16

    // 一个像素占 8/16/32位
    cout << img.depth() << endl;   // 0  获取图像位深度，(即矩阵元素的存储方式,存储每个像素所用的位数)
    // cout << img.rows() << endl;
    cout << img.channels() << endl;  // 3
    cout << img.rows << endl;   // 360
    cout << img.cols << endl;   // 640
    cout << img(0) << endl;
    cv::imshow("aaa", img);
    // 

	return 0;
} 
