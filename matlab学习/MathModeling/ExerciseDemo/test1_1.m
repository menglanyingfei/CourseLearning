GDP = [3.224 3.311 3.4 3.415 3.5 3.51 3.54 3.671 3.723 3.831];
people = [34.2400 35.3470 36.3970 36.9070 37.4970 37.9470 38.5530 37.6980 38.7470 39.0457];
a = polyfit(people,GDP,1);
m = 34:0.5:40;
y = a(1)*m + a(2);
plot(people,GDP,'.',m,y,'LineWidth',2);
axis([34 40 3 4]);
xlabel('\bfx_{1}');
ylabel('\bfy_{1}');
title('\bfy_{1} = 0.11x_{1} - 0.61')
