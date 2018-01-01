invest = [0.19 0.20 0.21 0.23 0.25 0.25 0.26 0.31 0.32 0.37];
bokuan = [7.7 7.2 7.9 8 8.8 9.2 10.2 10.8 10.9 11.7];
a = polyfit(bokuan,invest,1);
m = 7:0.5:12;
y = a(1)*m + a(2);
plot(bokuan,invest,'.',m,y,'g','LineWidth',2);
axis([7 12 0.19 0.37]);
xlabel('\bfx_{3}');
ylabel('\bfy_{2}');
title('\bfy_{2} = 0.04x_{3} - 0.07')