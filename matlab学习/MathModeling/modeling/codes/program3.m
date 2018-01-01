% 此程序对应问题2, 对应附件1 数据吸收率示意图
p0 = load('1.dat');
Eabsorb = load('2.dat');

% subplot(1,3,1);  
% imagesc(p0); 
% subplot(1,3,2); 
R = radon(p0, 0:2:358); 
%imagesc(R);
%subplot(1,3,3); 
I = iradon(R, 0:2:358); 
imagesc(I);
c = zeros(size(I)); %获得o阵大小和x相同
for i=1:1:length(c(1,:))
    for j=1:1:length(c(:,1))
        c(i,j,1)=1;
        c(i,j,2)=0;
        c(i,j,3)=0; %红色
    end
end

surf(I, c);
rotate3d



