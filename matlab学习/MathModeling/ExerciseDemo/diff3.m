for i = 1 : length(x)
    if i == 1
        r(1) = (-3*x(1)+4*x(1+1)-x(1+2))/(20*x(1));
    elseif i ~= length(x)
        r(i) = (x(i+1)-x(i-1))/(20*x(i));
    else
        r(length(x))=(x(length(x)-2)-4*x(length(x)-1)+3*x(length(x)))/(20*x(length(x)));
    end
end

