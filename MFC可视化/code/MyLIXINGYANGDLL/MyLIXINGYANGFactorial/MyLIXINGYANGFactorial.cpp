// MyLIXINGYANGFactorial.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "MyLIXINGYANGFactorial.h"

double factorial(int n)
{
	int i;
	double r = 1.0;

	for (i = 2; i <= n; i++)
		r *= i;

	return r;
}

void sort(double* a, double len) {
	int i, j;
	double temp;
	int flag = 0;

	for (i = 0; i < len - 1; i++) {
		flag = 0;
		for (j = 0; j < len - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				flag = 1;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}
