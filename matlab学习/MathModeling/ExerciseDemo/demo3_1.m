paifang = [9.50 10.30 10.90 12.30 13.20 14.20 15.50 16.00 17.50 18.00];
people = [43.8483 44.0982 44.5306 44.7584 45.3439 45.7628 46.3919 46.6918 47.0512 47.6006];
a = polyfit(people,paifang,1);
m = 43:0.5:48;
y = a(1)*m + a(2);
plot(people,paifang,'.',m,y,'g','LineWidth',2);
axis([43 48 9 18]);
xlabel('\bfx_{1}');
ylabel('\bfy_{3}');
title('\bfy_{3} = 2.30x_{1} - 91.00')