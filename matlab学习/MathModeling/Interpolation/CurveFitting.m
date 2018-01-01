x = [1,2,4,7,9,12,13,15,17]';  
F = [1.5,3.9,6.6,11.7,15.6,18.8,19.6,20.6,21.1]';
plot(x, F, '.');
% 从图像上,我们发现:前5个数据应与直线拟合,后5个数据应与二次曲线拟合。于是键入 : 
a1 = polyfit(x(1:5), F(1:5), 1);  
a2 = polyfit(x(5:9), F(5:9), 2);
