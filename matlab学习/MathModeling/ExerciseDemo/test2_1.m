invest = [0.18 0.19 0.2 0.2 0.21 0.24 0.24 0.26 0.26 0.27];
people = [34.2400 35.3470 36.3970 36.9070 37.4970 37.9470 38.5530 37.6980 38.7470 39.0457];
a = polyfit(people,invest,1);
m = 34:0.5:40;
y = a(1)*m + a(2);
plot(people,invest,'.',m,y,'LineWidth',2);
axis([34 40 0.15 0.3]);
xlabel('\bfx_{1}');
ylabel('\bfy_{2}');
title('\bfy_{2} = 0.02x_{1} - 0.48')
