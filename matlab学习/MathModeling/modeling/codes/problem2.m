% 此程序对应问题3, 使用matlab中的iradon函数对附件5进行绘图
d = 0.2774;
nhalf = 512/2;
x0 = -33*d;        y0 = 21*d;       

p = load('5.dat');
p = [zeros(100,180); p; zeros(100,180)];

imagesc(p)
figure
img = iradon(p,[0:179]-90-150);

n = size(img,1);

[x, y] = meshgrid([-n/2:n/2]*d);
imagesc(x(1,:), y(:,1), img)

hold on
plot(y0,x0,'or')

xp = [-50  50 50 -50 -50]';

yp = [-50 -50 50  50 -50]';
[x0, y0] = rotxy(xp, yp, -y0, -x0, 0); 

plot(xp,yp,'-w')

axis image