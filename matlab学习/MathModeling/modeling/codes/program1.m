% �˳����Ӧ����2, ʹ��matlab�е�iradon�����Ը���3���л�ͼ

% ������ʼ��
d = 0.2774;
nhalf = 512/2;
% �������̵���ת����
x0 = -33*d;  y0 = 21*d;   

% �����ļ�����
data = load('3.dat');
% ��չ����
data = [zeros(100,180); data; zeros(100,180)];

imagesc(data)
figure

img = iradon(data, [0:179]-90-150);
% ��img��������ֵ������n
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
