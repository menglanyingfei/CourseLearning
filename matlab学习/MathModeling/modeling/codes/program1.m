% 此程序对应问题2, 使用matlab中的iradon函数对附件3进行绘图

% 变量初始化
d = 0.2774;
nhalf = 512/2;
% 方形托盘的旋转中心
x0 = -33*d;  y0 = 21*d;   

% 加载文件数据
data = load('3.dat');
% 扩展矩阵
data = [zeros(100,180); data; zeros(100,180)];

imagesc(data)
figure

img = iradon(data, [0:179]-90-150);
% 将img的行数赋值给变量n
n = size(img,1);
[x, y] = meshgrid([-n/2:n/2]*d); 

imagesc(x(1,:),y(:,1),img)

hold on

plot(y0, x0, 'ok')
xp = [-50  50 50 -50 -50]';
yp = [-50 -50 50  50 -50]';
[x, y] = rotxy(xp, yp, -y0, -x0, 0); 
plot(x,y,'-r')

axis image
