K = 0:.20:200;
m=6;
n=200;
V = log(n./K).*m;
plot(K,V);
xlabel('密度');
ylabel('速度V （km/h)');
% title('速度密度对数曲线（大密度）');
title('\bf{B}_{\itS}')
