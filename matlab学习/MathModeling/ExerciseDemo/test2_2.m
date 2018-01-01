invest = [0.18 0.19 0.2 0.2 0.21 0.24 0.24 0.26 0.26 0.27];
bokuan = [4.3 4.7 5.2 6 6.1 6.4 7.3 7.9 8.3 8.5];
a = polyfit(bokuan,invest,1);
m = 4:0.5:9;
y = a(1)*m + a(2);
plot(bokuan,invest,'.',m,y,'LineWidth',2);
axis([4 9 0.15 0.4]);
xlabel('\bfx_{3}');
ylabel('\bfy_{2}');
title('\bfy_{2} = 0.02x_{3} - 0.09')











