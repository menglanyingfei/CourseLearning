function y = functionDemo(num)
    A = normrnd(3, 3, 1, num);
    y = sort(A, 'descend')
end
