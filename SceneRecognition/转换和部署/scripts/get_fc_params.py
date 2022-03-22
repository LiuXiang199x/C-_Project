from tabnanny import check
import resnet_net
import torch
# import onnxruntime
import numpy as np

pth_model = "/home/agent/C-_Project/SceneRecognition/Final/models/352x352/resnet18_latest_combined_v83.pth.tar"

# checkpoint = torch.load("/home/agent/C-_Project/SceneRecognition/Final/models/352x352/resnet18_latest_combined_v83.pth.tar", map_location=lambda storage, loc: storage)
checkpoint = torch.load(pth_model)
print(type(checkpoint))
print(checkpoint.keys())
print(checkpoint["obj_state_dict"].keys())
print(checkpoint["classifier_state_dict"].keys())
print(checkpoint["classifier_state_dict"]["module.fc.bias"])

print(checkpoint["obj_state_dict"]["module.fc.weight"].size())


f = open("/home/agent/C-_Project/SceneRecognition/转换和部署/scripts/1.txt", "w")
for item in checkpoint["obj_state_dict"]["module.fc.weight"].tolist():
    f.writelines(str(item).replace("[","").replace("]","")+","+"\n")
    
f.close()