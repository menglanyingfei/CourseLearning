% �˳���2��Ӧ������һ, ��Matlab��ⷽ��, �ó�б�ʶ�Ӧ����б��
[data]=xlsread('data', 1);
syms param;
for m = data   
    param = m;
    t = solve(strcat(num2str(param), '^2*(1/225+t/1600) - 4*(1+t) = 0'), 't');
    A = atan(1*t^0.5);
    degree=(180/pi)*A;
   
    degree
end
