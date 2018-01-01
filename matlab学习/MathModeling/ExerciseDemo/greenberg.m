k=0:.50:250;
Q = 28*k.*log(142./k);
plot(k,Q,'-','LineWidth',3);
axis([0 250 0 1500]);
xlabel('k (veh/km)');
ylabel('Q (veh/h)');
title('Greenberg Modeling')
