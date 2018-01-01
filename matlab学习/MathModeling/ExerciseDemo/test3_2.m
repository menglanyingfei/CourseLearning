paifang = [13.5 15.6 16.3 17.2 17.5 18.2 18.3 18.3 18.5 19.3];
lvdi = [60 61 62 64 68 68 69 70 71 73];
a = polyfit(lvdi,paifang,1);
m = 60:1:75;
y = a(1)*m + a(2);
plot(lvdi,paifang,'.',m,y,'LineWidth',2);
axis([60 75 13 20]);
xlabel('\bfx_{4}');
ylabel('\bfy_{3}');
title('\bfy_{3} = 0.35x_{4} - 6.16')