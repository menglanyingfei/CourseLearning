[x, y]=meshgrid([0.15, 0.45, 0.75]);
z=exp(x .* y);
[xi,yi]=meshgrid(0:0.1:5);

zi_nearst=interp2(x,y,z,xi,yi,'nearset');
zi_linear=interp2(x,y,z,xi,yi);
zi_spline=interp2(x,y,z,xi,yi,'spline');
figure;
hold on;
subplot(2,2,1);meshc(x,y,z);
title('原始数据');
subplot(2,2,2);meshc(xi,yi,zi_nearst);
title('最邻近插值');
subplot(2,2,3);meshc(xi,yi,zi_linear);
title('线性插值');
subplot(2,2,4);meshc(xi,yi,zi_spline);
title('三次样条插值');
