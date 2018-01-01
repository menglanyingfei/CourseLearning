% 求阵列x的平均值和标准差
[m, n] = size(x);
if m == 1
	m = n;
end
s1 = sum(x);
s2 = sum(x.^2);
mean1 = s1 / m;
stdev = sqrt(s2 / m - mean1.^2);