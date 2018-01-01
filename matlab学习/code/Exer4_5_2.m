n = input('请输入n的值: ');
A = [1 2 3;0 1 2; 0 0 1];
t = 1;
% sum初始值为0, 是为了求和
sum = 0;
i = 0;
while i <= n
    sum = sum + A^i * exp(A^i * t);
    i = i+1;
end
sum




