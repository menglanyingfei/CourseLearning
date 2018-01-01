x= [0.15, 0.45, 0.75];
y=exp(x);
xi=0:0.1:5;
yi_nearst=interp1(x,y,xi,'nearset');
yi_linear=interp1(x,y,xi);
yi_spline=interp1(x,y,xi,'spline');
figure;
hold on
subplot(1,3,1);
plot(x,y,'ro', xi,yi_nearst,'b-');
title('最邻近插值');
subplot(1,3,2);
plot(x,y,'ro',xi,yi_linear,'b-');
title('线性插值');
subplot(1,3,3);
plot(x,y,'ro',xi,yi_spline,'b-');
title('三次样条插值');