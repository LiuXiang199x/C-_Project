import os
import urllib
import traceback
import time
import sys
import numpy as np
import cv2
from rknn.api import RKNN

ONNX_MODEL = "onnx/SceneResnet18_18pth.onnx"
RKNN_MODEL_OFFLINE = "rknn_sin_precompile/SceneResnet18_18pth.rknn"
RKNN_MODEL_ONLINE = "rknn_con_precompile/SceneResnet18_18pth.rknn"

def show_outputs(outputs):
    output = outputs[0][0]
    output_sorted = sorted(output, reverse=True)
    top5_str = 'resnet50v2\n-----TOP 5-----\n'
    for i in range(5):
        value = output_sorted[i]
        index = np.where(output == value)
        for j in range(len(index)):
            if (i + j) >= 5:
                break
            if value > 0:
                topi = '{}: {}\n'.format(index[j], value)
            else:
                topi = '-1: 0.0\n'
            top5_str += topi
    print(top5_str)


def readable_speed(speed):
    speed_bytes = float(speed)
    speed_kbytes = speed_bytes / 1024
    if speed_kbytes > 1024:
        speed_mbytes = speed_kbytes / 1024
        if speed_mbytes > 1024:
            speed_gbytes = speed_mbytes / 1024
            return "{:.2f} GB/s".format(speed_gbytes)
        else:
            return "{:.2f} MB/s".format(speed_mbytes)
    else:
        return "{:.2f} KB/s".format(speed_kbytes)


def show_progress(blocknum, blocksize, totalsize):
    speed = (blocknum * blocksize) / (time.time() - start_time)
    speed_str = " Speed: {}".format(readable_speed(speed))
    recv_size = blocknum * blocksize

    f = sys.stdout
    progress = (recv_size / totalsize)
    progress_str = "{:.2f}%".format(progress * 100)
    n = round(progress * 50)
    s = ('#' * n).ljust(50, '-')
    f.write(progress_str.ljust(8, ' ') + '[' + s + ']' + speed_str)
    f.flush()
    f.write('\r\n')


if __name__ == '__main__':

    # Create RKNN object
    rknn = RKNN()


    # Set inputs
    #img = cv2.imread('./dog_128.jpg')
    # img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    img = np.ones((224,224,3))
    # print(img)

    print("----> load rknn model")
    ret_online = rknn.load_rknn(RKNN_MODEL_ONLINE)
    if ret_online != 0:
        print('Load RKNN model failed!')
        exit(ret_online)
    print('done')

    # init runtime environment
    print('--> Init runtime environment')
    ret_online = rknn.init_runtime()
    if ret_online != 0:
        print('Init runtime environment failed')
        exit(ret_online)
    print('done')

    
    # Inference
    print('--> Running model')
    outputs = rknn.inference(inputs=[img])
    # x = outputs[0]
    # output = np.exp(x)/np.sum(np.exp(x))
    # outputs = [output]
    # show_outputs(outputs)
    print('done')

    rknn.release()
    
