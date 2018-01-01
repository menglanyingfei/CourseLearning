x = linspace(0,2*pi,100); % 100个点的x坐标
y = sin(x);						  % 对应的y坐标
% plot(x,y)
plot(x,y,'co',x,cos(x),'g*')


