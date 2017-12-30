#include <iostream>

using namespace std;

bool judge(int a[])
{
	int i, j, k;
	int b[4][4];
	k = 1;
	for (i = 1; i<4; i++)
	for (j = 1; j<4; j++)
	{
		b[i][j] = a[k];
		k++;
	}
	for (int i = 1; i<4; i++)
	{
		if (b[i][1] == b[i][2] && b[i][1] == b[i][3])
			return true;
		if (b[1][i] == b[2][i] && b[1][i] == b[3][i])
			return true;
		if (b[1][1] == b[2][2] && b[1][1] == b[3][3])
			return true;
		if (b[1][3] == b[2][2] && b[1][3] == b[3][1])
			return true;
	}
	return false;
}
void display(int a[])
{
	int i, j, k;
	int b[4][4];
	k = 1;
	for (i = 1; i<4; i++)
	for (j = 1; j<4; j++)
	{
		b[i][j] = a[k];
		k++;
	}
	cout << "=================" << endl;
	for (i = 1; i<4; i++)
	{
		cout << "    ";
		for (j = 1; j<4; j++)
		{
			if (b[i][j] == 1)
				cout << "O";
			else if (b[i][j] == -1)
				cout << "X";
			else
				cout << "-";
			cout << "   ";
		}
		cout << endl;
	}
	cout << "=================" << endl;
}
bool limit(int i, int data[])
{
	if (data[i] == 1 || data[i] == -1)
		return true;
	else
		return false;
}