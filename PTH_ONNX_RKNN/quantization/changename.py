import os

f = open("/home/agent/C-_Project/PTH_ONNX_RKNN/quantization/quantization.txt").readlines()
f2 = open("/home/agent/C-_Project/PTH_ONNX_RKNN/quantization/quantization_.txt", "w")
for i in f:
    i = i.split("/")[-1]
    f2.writelines("/home/agent/C-_Project/PTH_ONNX_RKNN/quantization/img/" + i)