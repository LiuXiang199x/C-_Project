from tabnanny import check
from CombinedModel import AllModel
import torch
import onnx
import onnxruntime
import numpy as np


torch.manual_seed(1)    # reproducible

fake_img = torch.rand(1, 3, 224, 224)
img2 = torch.rand(13)
print("img2:", img2)
net = AllModel(num_classes=6)
net.eval()

print(net(fake_img, img2).shape)
print("prediction pth model：", net(fake_img, img2))

def test():
    M = 224
    batch_size = 1
    input_shape = (3, M, M)
    model = net
    # Initialize model with the pretrained weights
    # map_location = 'gpu' if torch.cuda.is_available() else 'cpu'
    # loaded_model = torch.load(pthfile, map_location="cpu")
    # model.actor.load_state_dict(loaded_model, strict=False)
    
    # set the model to inference mode
    model.eval()
    
    # data type nchw
    # x = torch.rand(batch_size, *input_shape)

    # # Export the model
    torch.onnx.export(model, (fake_img, img2),
                      "/home/agent/C-_Project/SceneRecognition/转换和部署/models/onnx_model/SceneCombined.onnx", 
                      opset_version=10)
                      #keep_initializers_as_inputs=True, 
                      # verbose=True
    '''
    torch.onnx.export(model,               # model being run
                    x,                         # model input (or a tuple for multiple inputs)
                    onnxpath,   # where to save the model (can be a file or file-like object)
                    export_params=True,        # store the trained parameter weights inside the model file
                    opset_version=10,          # the ONNX version to export the model to
                    do_constant_folding=True,  # whether to execute constant folding for optimization
                    input_names = ['input'],   # the model's input names
                    output_names = ['output'], # the model's output names
                    dynamic_axes={'input' : {0 : 'batch_size'},    # variable lenght axes
                                  'output' : {0 : 'batch_size'}}
                     )
    '''
    print("=============Successful==========")
    
def check_pth_onnx():
    # print("torch.__version__:", torch.__version__) # torch.__version__: 1.7.1
    # print("onnx.__version__:", onnx.__version__) # onnx.__version__: 1.11.0
    # print("onnxruntime.__version__:", onnxruntime.__version__) # onnxruntime.__version__: 1.10.0
    
    onnx_path = "/home/agent/C-_Project/SceneRecognition/转换和部署/models/onnx_model/SceneCombined.onnx"
    # onnx_model = onnx.load(onnx_path)
    # print(onnx.checker.check_model(onnx_model))

    ort_session = onnxruntime.InferenceSession(onnx_path)

    # compute ONNX Runtime output prediction
    ort_outs = ort_session.run(None, {ort_session.get_inputs()[0].name: fake_img.cpu().numpy().astype(np.float32),
                                      ort_session.get_inputs()[1].name: img2.cpu().numpy().astype(np.float32)})

    # compare ONNX Runtime and PyTorch results

    print("onnx model output:", ort_outs)

test()
check_pth_onnx()