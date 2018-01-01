% ��Ӧ������������������ʾ��ͼ�Ļ�ͼ
d = 0.2774;
nhalf = 512/2;
xc = -33*d;        yc = 21*d;        

p = load('5.dat');
p = [zeros(100,180); p; zeros(100,180)];

figure
img = iradon(p, [0:179]-90-150);
surf(img);
rotate3d

n = size(img,1);
[x, y] = meshgrid([-n/2:n/2]*d);

imagesc(x(1,:), y(:,1), img);

c = zeros(size(img)); %���o���С��x��ͬ
for i=1:1:length(c(1,:))
    for j=1:1:length(c(:,1))
        c(i,j,1)=1;
        c(i,j,2)=0;
        c(i,j,3)=0; %��ɫ
    end
end
surf(img, c);
rotate3d

hold on

xp = [-50  50 50 -50 -50]';
yp = [-50 -50 50  50 -50]';
[xp, yp] = rotxy(xp, yp, -yc, -xc, 0); 

plot(xp,yp,'-w');
axis image;

plot(10,18,'o')
