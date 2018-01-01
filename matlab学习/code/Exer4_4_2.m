a = input('请输入a的值: ');
b = input('请输入b的值: ');
c = input('请输入c的值: ');
d = input('请输入d的值: ');

if x <= a
    y = 0
elseif a < x <= b
    y = 1/(b-a)*(x-a)
elseif b < x <= c
    y = 1
elseif c < x <= d
    y = 1/(c-d)*(x-d)
elseif x > d
    y = 0
else
    disp('输入错误!');
end
    




        