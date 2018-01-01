x = linspace(0, 2 * pi, 100);
y = sin(x);
plot(x, y, 'co', x, cos(x), 'g*');
xlabel('Input Value');                              % x轴注解
ylabel('Function Value');                         % y轴注解
title('Two Trigonometric Functions');       % 图形标题
legend('y = sin(x)', 'y = cos(x)');               % 图形注解
grid on                                                   % 显示格线