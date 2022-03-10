from tabnanny import check
from CombinedModel import AllModel
import torch
import numpy as np


torch.manual_seed(1)    # reproducible

fake_img = torch.rand(1, 3, 224, 224)
img2 = torch.rand((0,0,0,0,0,0,0,0,0,1,0,0,0))
print("img2:", img2)

all_model = AllModel(num_classes=5)

#'''
checkpoint = torch.load('/home/agent/C-_Project/SceneRecognition/转换和部署/src/pth2onnx/resnet18_latest_combined_v9.pth.tar', map_location=lambda storage, loc: storage)
#print(checkpoint)
model_state_dict = {str.replace(k,'module.',''): v for k,v in checkpoint['model_state_dict'].items()}
obj_state_dict = {str.replace(k,'module.',''): v for k,v in checkpoint['obj_state_dict'].items()}
classifier_state_dict = {str.replace(k,'module.',''): v for k,v in checkpoint['classifier_state_dict'].items()}
all_model.model.load_state_dict(model_state_dict)
all_model.object_idt.load_state_dict(obj_state_dict)
all_model.classifier.load_state_dict(classifier_state_dict)
print("====== weight loaded")

all_model.eval()

print(all_model(fake_img, img2).shape)
print("prediction pth model：", all_model(fake_img, img2))
