x = 0:0.5:2 * pi;
y1 = sin(x);
y2 = cos(x);
plot(x,y1,'-r',x,y2,'o-b')
legend('正弦曲线','余弦曲线')
xlabel('自变量')
ylabel('因变量')
grid on
axis([0 2*pi -1 1])

