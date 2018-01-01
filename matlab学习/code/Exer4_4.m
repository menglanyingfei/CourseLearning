y = input('ÇëÊäÈëyµÄÖµ: (1, 2, 3) ');
x = 0:0.1*pi:2*pi;
if y == 1
    z = sin(x);
elseif y == 2
    z = cos(x);
else 
    z = sin(x) .* cos(x);
end
