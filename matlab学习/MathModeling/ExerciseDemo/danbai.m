function xdot = danbai(x)
xdot = zeros(2,1);
xdot(1) = x(2);
xdot(2) = -9.8/25*sin(x(1));
