from locale import DAY_1
from tabnanny import check
from PIL import Image
from CombinedModel import AllModel
import torch
import numpy as np
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms

torch.manual_seed(1)    # reproducible

fake_img = torch.rand(1, 3, 224, 224)
img2 = torch.tensor([0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        1.0, 0.0, 0.0, 0.0])
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


class Mydataset(Dataset):
    def __init__(self, img_txt):
        self.img_info = self.get_imgs(img_txt)
        self.img2tensor = transforms.Compose([
            transforms.Resize(224),
            transforms.ToTensor()
        ])

    def get_imgs(self, img_txt):
        f=open(img_txt, "r", encoding="utf-8").readlines()
        datasets = list(map(lambda x:x.strip().split(" "), f))
        
        return datasets

    def __getitem__(self, index):
        url, label = self.img_info[index]
        img = Image.open(url)
        img = img.convert("RGB")
        
        img = self.img2tensor(img)
        
        return img, label

    def __len__(self):
        return len(self.img_info)

# print(all_model(fake_img, img2).shape)
# print("prediction pth model：", all_model(fake_img, img2))

train_datas = Mydataset("/home/agent/C-_Project/SceneRecognition/转换和部署/src/pth2onnx/img.txt")
for i in train_datas:
    xxx = i[0]
print(xxx.size())
qq = torch.unsqueeze(xxx, 0)

# train_loader = DataLoader(batch_size=1, dataset=train_datas,shuffle=True)
#print(train_loader)
all_model(qq, img2)

print(all_model(qq, img2))
q = all_model(qq, img2)
a = 0
for n in q[0]:
    a += torch.exp(n)

for n in q[0]:
    print(torch.exp(n)/a)