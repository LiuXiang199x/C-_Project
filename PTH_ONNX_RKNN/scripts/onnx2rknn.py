import os
import urllib
import traceback
import time
import sys
import numpy as np
# import cv2
from rknn.api import RKNN

ONNX_MODEL = '/home/agent/C-_Project/PTH_ONNX_RKNN/models/onnx/SceneResnet18_18pth_352.onnx'
RKNN_MODEL = '/home/agent/C-_Project/PTH_ONNX_RKNN/models/rknn/SceneResnet18_1126_352.rknn'


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

    # If resnet50v2 does not exist, download it.
    # Download address:
    # https://s3.amazonaws.com/onnx-model-zoo/resnet/resnet50v2/resnet50v2.onnx
    # if not os.path.exists(ONNX_MODEL):
    #     print('--> Download {}'.format(ONNX_MODEL))
    #     url = 'https://s3.amazonaws.com/onnx-model-zoo/resnet/resnet50v2/resnet50v2.onnx'
    #     download_file = ONNX_MODEL
    #     try:
    #         start_time = time.time()
    #         urllib.request.urlretrieve(url, download_file, show_progress)
    #     except:
    #         print('Download {} failed.'.format(download_file))
    #         print(traceback.format_exc())
    #         exit(-1)
    #     print('done')

    # pre-process config
    print('--> config model')

    #1126-regnet
    rknn.config(mean_values=[[123.675, 116.28, 103.53]], std_values=[[58.395, 57.12, 57.375]], reorder_channel='0 1 2', target_platform=['rv1126', 'rv1109'])
    # rknn.config(batch_size=1, mean_values=[[123.675, 116.28, 103.53]], std_values=[[58.395, 57.12, 57.375]], reorder_channel='0 1 2', target_platform=['rv1109','rv1126'])
    
    #1806-efficinet
    # rknn.config(batch_size=1, mean_values=[[123.675, 116.28, 103.53]], std_values=[[58.395, 57.12, 57.375]], reorder_channel='0 1 2')
    #vgg16-gem [0.485, 0.456, 0.406]
    #1126-efficientet
    #rknn.config(batch_size=1, mean_values=[[127.5, 127.5, 127.5]], std_values=[[127.5, 127.5, 127.5]], reorder_channel='0 1 2', target_platform=['rv1109','rv1126'])
    #rknn.config(batch_size=1, mean_values=[[127.5, 127.5, 127.5]], std_values=[[127.5, 127.5, 127.5]], reorder_channel='0 1 2')
    print('done')
    # Load tensorflow model
    print('--> Loading model')
    ret = rknn.load_onnx(model=ONNX_MODEL)
    if ret != 0:
        print('Load resnet50v2 failed!')
        exit(ret)
    print('done')
    # Build models
    print('--> Building model')
    #ret = rknn.build(do_quantization=False, dataset='./dataset_model_64.txt',pre_compile=True)
    # ret = rknn.build(do_quantization=True, dataset='./dataset_model_224.txt',pre_compile=True)
    ret = rknn.build(do_quantization=True, dataset="/home/agent/C-_Project/PTH_ONNX_RKNN/quantization/quantization_.txt",pre_compile=True)
    # ret = rknn.build(do_quantization=True, dataset='./regenty_004_64_qualify-2000.txt',pre_compile=True)
    if ret != 0:
        print('Build resnet50 failed!')
        exit(ret)
    print('done')
    # Export rknn model
    print('--> Export RKNN model')
    ret = rknn.export_rknn(RKNN_MODEL)
    if ret != 0:
        print('Export resnet50v2.rknn failed!')
        exit(ret)
    print('done')


    rknn.release()