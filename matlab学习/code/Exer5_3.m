x1 = -2:0.1:2;
x2 = -2:0.1:2;
y1 = x1 .* sin(x2);
plot3(x1, x2, y1, 'dr');
hold on
y2 = x2 .* cos(x1);
plot3(x1, x2, y2, 'd');
legend('y1', 'y2', 'Location', 'NorthWest');

