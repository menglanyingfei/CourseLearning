a = input('������a��ֵ: ');
b = input('������b��ֵ: ');
c = input('������c��ֵ: ');
d = input('������d��ֵ: ');

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
    disp('�������!');
end
    




        