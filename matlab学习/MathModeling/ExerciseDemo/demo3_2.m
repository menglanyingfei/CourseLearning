paifang = [9.50 10.30 10.90 12.30 13.20 14.20 15.50 16.00 17.50 18.00];
lvdi = [74 76 78 79 80 80 81 82 83 85];
a = polyfit(lvdi,paifang,1);
m = 70:0.5:90;
y = a(1)*m + a(2);
plot(lvdi,paifang,'.',m,y,'g','LineWidth',2);
axis([70 90 9 18]);
xlabel('\bfx_{4}');
ylabel('\bfy_{3}');
title('\bfy_{3} = 0.89x_{4} - 57.36')