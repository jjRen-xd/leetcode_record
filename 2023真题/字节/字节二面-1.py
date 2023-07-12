
# w是一层卷积网络的kernel, w=[1,2]^T, valid padding,stride=1.pad=0。input x=[1,2,3,4]^T，求:
# 1.前向y的计算
# 2.假设y的梯度dy=[0.3,0.2,0.1],求dw，dx

# dy = L/y
# dw = L/w = L/y*y/w = dy* y/w
# y/w => y1= x1w1+x2*w2

# y1/w1 = x1
# y1/w2 = x2
# [[1,2],[3,4],[5,6]] = y/w
import torch
import torch.nn as nn

class ConvNet(nn.Module):
    def __init__(self):
        super(ConvNet, self).__init__()
        self.conv = nn.Conv1d(1, 1, kernel_size=2, stride=1, padding=0, bias=False)
        self.conv.weight = nn.Parameter(torch.Tensor([[1.0, 2.0]]).view(1, 1, 2))
        
    def forward(self, x):
        y = self.conv(x)
        return y

# 创建模型实例
model = ConvNet()

# 输入示例数据
x = torch.Tensor([1.0, 2.0, 3.0, 4.0])[None, None, :]
x.requires_grad = True

# 前向传播
output = model(x)

# 打印输出结果
print(output)

# 计算梯度
dy = torch.Tensor([0.3, 0.2, 0.1])[None, None, :]
output.backward(dy)

# 获取梯度dw和dx
dw = model.conv.weight.grad
dx = x.grad

# 打印梯度dw和dx
print(dw)
print(dx)