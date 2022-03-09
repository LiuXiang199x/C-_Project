from rknn.api import RKNN

ONNX_MODEL = "/home/agent/C-_Project/PTH_ONNX_RKNN/models/onnx/SceneResnet18_18pth.onnx"
RKNN_MODEL = "/home/agent/C-_Project/PTH_ONNX_RKNN/models/rknn_sin_precompile/SceneResnet18_18pth_1126.rknn"
 
if __name__ == '__main__':

    # Create RKNN object
	rknn = RKNN()

	# pre-process config
	print("---> condig model")

	# 1806-regnet，reorder_channel='0 1 2 3 4 5 6 7', mean_values=[[123.675, 116.28, 103.53,1,1,1,1,1]], std_values=[[58.395, 57.12, 57.375,1,1,1,1,1]]
	rknn.config(batch_size=1, reorder_channel='0 1 2', mean_values=[[123.675, 116.28, 103.53]], std_values=[[58.395, 57.12, 57.375]], target_platform=['rv1109','rv1126']) # , target_platform=['rv1109','rv1126']

	# Load models	
	print("---> Loading model")
	ret_RL = rknn.load_onnx(model=ONNX_MODEL)
	if ret_RL != 0:
		print("<======= Load RL model failed! =======>") 
		exit(ret_RL)
	print("========= Loading Done =========")

	# Build models
	print("<======== Building RL model =========>")
	ret_RL = rknn.build(do_quantization=True, dataset="/home/agent/C-_Project/PTH_ONNX_RKNN/quantization/quantization_.txt", pre_compile=True)
	if ret_RL != 0:
		print("<======= Build RL model failed! =======>")
		exit(ret_RL)
	print("========= Building Done =========")

	# Export rknn model
	print("<========= Export RKNN model =========>")
	ret_RL = rknn.export_rknn(RKNN_MODEL)
	if ret_RL != 0:
		print("<======= Build RL model failed! =======>") 
		exit(ret_RL)
	print("========= Export Done =========")
	
	# Release RKNN Context
	rknn.release()