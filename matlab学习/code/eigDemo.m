% 判断一个矩阵是否可以对角化
% A为矩阵
b=eig(A);  

c=size(b);  

d=c(1)*c(2);  

e=length(unique(b)); 

if(d==e)  
    fprintf('is\n');  
else  
    fprintf('is not\n');  
end  

































