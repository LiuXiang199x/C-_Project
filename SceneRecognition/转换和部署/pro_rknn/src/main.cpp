#include "SceneNet.h"

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

using namespace std;

int main()
{
	printf("hello world\n");
	double tmp_Nano[13] = {1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};
	double tmp_Scene[512] = {1};

    everest::ai::SceneNet a;
    a.sceneClass(tmp_Nano, tmp_Scene);

	return 0;
} 