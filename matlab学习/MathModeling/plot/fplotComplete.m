x = linspace(0, 2 * pi, 100);
y = sin(x);
plot(x, y, 'co', x, cos(x), 'g*');
xlabel('Input Value');                              % x��ע��
ylabel('Function Value');                         % y��ע��
title('Two Trigonometric Functions');       % ͼ�α���
legend('y = sin(x)', 'y = cos(x)');               % ͼ��ע��
grid on                                                   % ��ʾ����