from distutils import text_file
import os

img_folder = "/home/agent/C-_Project/SceneRecognition/quantization/img/"
img_folder_lt = "/home/xiang/quantization/img/"

txt_folder = "/home/agent/C-_Project/SceneRecognition/quantization/quantization.txt"
txt_folder_lt = "/home/agent/C-_Project/SceneRecognition/quantization/quantization_laptop.txt"


f1 = open(txt_folder, "w")
f2 = open(txt_folder_lt, "w")

for item in os.listdir(img_folder):
    f1.writelines(img_folder+item+"\n")
    f2.writelines(img_folder_lt+item+"\n")

f1.close()
f2.close()