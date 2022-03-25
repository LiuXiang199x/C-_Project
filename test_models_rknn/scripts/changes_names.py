f_nano = open("/home/agent/C-_Project/test_models_rknn/nano_res.txt", "r").readlines()
f_pics = open("/home/agent/C-_Project/test_models_rknn/val_pics.txt", "r").readlines()

fpic = open("/home/agent/C-_Project/test_models_rknn/val_picss.txt", "w")
fnano = open("/home/agent/C-_Project/test_models_rknn/nano_ress.txt", "w")

# for item in f_pics:
#     a = item.replace("/mnt/sdc/zhuhao/scene_dataset/data", "/home/agent/C-_Project/test_models_rknn")
#     fpic.writelines(a)

for item in f_nano:
    a = item.replace("[","").replace("]","")
    fnano.writelines(a)