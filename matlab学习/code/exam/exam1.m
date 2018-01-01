f=@(t, x, mu)[x(2);-mu*(x(1)^2-3)*x(2) - 2*x(1)];
x0=[-2, -1];
mu = 1;
[t1, y1] = ode45(f, [0, 10], x0, odeset, mu);
plot(t1, y1)
