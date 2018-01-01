n = input('ÇëÊäÈënµÄÖµ: ');
x = pi/3;
i = 1;
sum = 0;
while n > 0
    if rem(i, 2) == 0
        sum = sum + sin(i*x) + cos(i*x);
    else
        sum = sum + sin(i*x) - cos(i*x);
    end
    n = n - 1;
    i = i + 1;
end
sum




