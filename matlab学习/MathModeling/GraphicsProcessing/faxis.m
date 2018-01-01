x = 0:.025:pi/2;
plot(x, exp(x).*sin(2 * x), '-m<');
axis([0 pi/2 0 5])