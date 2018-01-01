paifang = [13.5 15.6 16.3 17.2 17.5 18.2 18.3 18.3 18.5 19.3];
people = [34.2400 35.3470 36.3970 36.9070 37.4970 37.9470 38.5530 37.6980 38.7470 39.0457];
a = polyfit(people,paifang,1);
m = 34:0.5:40;
y = a(1)*m + a(2);
plot(people,paifang,'.',m,y,'LineWidth',2);
axis([34 40 13 25]);
xlabel('\bfx_{1}');
ylabel('\bfy_{3}');
title('\bfy_{3} = 1.09x_{1} - 23.33')