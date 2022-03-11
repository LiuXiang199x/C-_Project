import torch
from torch.utils.data import Dataset

print(torch.tensor((1,2,3)))


class MyDataset(Dataset):
    def __init__(self, txt_path, train_flag=True):
        self.imgs_info = self.get_images(txt_path)
        
        
        
    def get_images(self, txt_path):
        txtfile = open(txt_path, "r", encoding="utf-8")
        data_txt = txtfile.readlines()
        
    
    
    def __getitem__(self, index):
        index += 1
    
    def __len__(self):
        return 0
    
a = lambda a,b,c:a+b+c

print(list(map(a, [1],[2],[3])))