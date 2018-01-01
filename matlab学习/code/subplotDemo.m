x = -2*pi:0.1*pi:2*pi;

subplot(3, 2, 1);
plot(x, sin(x));
subplot(3, 2, 2);
plot(x, cos(x));
subplot(3, 2, 3);
plot(x, tan(x));
subplot(3, 2, 4);
plot(x, cot(x));
subplot(3, 2, 5);
plot(x, sec(x));
subplot(3, 2, 6);
plot(x, csc(x));