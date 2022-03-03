from asyncio import transports
import torch

a = torch.rand(1,2)
print(a)
b = torch.rand(1,4)
print(b)
print(torch.cat((a,b), 1))