x = linspace(0,2*pi,100);
y = sin(x);
plot(x,y,'co',x,cos(x),'g*');
axis([0, 6, -1.2, 1.2])