% �˳����Ӧ����2, ��Ӧ����1 ����������ʾ��ͼ
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
c = zeros(size(I)); %���o���С��x��ͬ
for i=1:1:length(c(1,:))
    for j=1:1:length(c(:,1))
        c(i,j,1)=1;
        c(i,j,2)=0;
        c(i,j,3)=0; %��ɫ
    end
end

surf(I, c);
rotate3d



