invest = [0.19 0.20 0.21 0.23 0.25 0.25 0.26 0.31 0.32 0.37];
people = [43.8483 44.0982 44.5306 44.7584 45.3439 45.7628 46.3919 46.6918 47.0512 47.6006];
a = polyfit(people,invest,1);
m = 43:0.5:48;
y = a(1)*m + a(2);
plot(people,invest,'.',m,y,'g','LineWidth',2);
axis([43 48 0.19 0.37]);
xlabel('\bfx_{1}');
ylabel('\bfy_{2}');
title('\bfy_{2} = 0.09x_{1} - 0.37')