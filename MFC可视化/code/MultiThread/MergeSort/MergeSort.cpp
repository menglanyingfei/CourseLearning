#include <Windows.h>
#include <iostream>

using namespace std;

// ��������(�����̺߳���)
DWORD WINAPI Fun1Proc(LPVOID lpParameter);
DWORD WINAPI Fun2Proc(LPVOID lpParameter);
void sort(int* array);
void MergeSort(int * a, int * temp, int low, int high);
void Merge(int* a, int low, int mid, int high, int* temp);
void Merge(int* a1, int* a2);

// ȫ������
int array[] = {2, 53, 34, 43, 45, 6};
int La = sizeof(array) / sizeof(array[0]); // ����ĳ���

int a[100];
int b[100];
// ����������, ��źϲ��������
int tmpArray[100];

HANDLE hMutex;

// ����������
void sort(int* array) {
	int length = La / 2;
	int temp[100];
	MergeSort(array, temp, 0, length - 1);
}

//��·�鲢���ݹ�ʵ�֣�
void MergeSort(int * a, int * temp, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a, temp, low, mid);      //�������
		MergeSort(a, temp, mid + 1, high);   //�ұ�����
		Merge(a, low, mid, high, temp);     //�ٽ������������кϲ�
	}
}

//������ a[low,mid] �� a(mid,high] �ϲ����鲢��
void Merge(int* a, int low, int mid, int high, int* temp)
{
	int i, j, k;
	i = low;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= high)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[low + i] = temp[i];
}

// �ϲ�����(����������)
void Merge(int* a1, int* a2) {
	int length1 = La/2;
	int length2 = La/2;

	int left = 0;
	int right = 0;
	int pos = 0;

	while (left < length1 && right < length2) {
		if (a1[left] <= a2[right]) {
			tmpArray[pos] = a1[left];
			left++;
		}
		else {
			tmpArray[pos] = a2[right];
			right++;
		}
		pos++;
	}

	while (left < length1) {
		tmpArray[pos++] = a1[left++];
	}

	while (right < length2) {
		tmpArray[pos++] = a2[right++];
	}
}

int main() {
	HANDLE hThread1;
	HANDLE hThread2;

	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	// �����ź���
	hMutex = CreateMutex(NULL, FALSE, NULL);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	// ֮���Լ���仰, ��Ϊ���������߳���ɷ��������, 
	// �ٺϲ�, �������, ����Ľ����ȫ����0, ��ȻҲ������̲߳���API����
	// ��C++ѧ�ú�ˮ, �Ҳ���!
	Sleep(1); 
	Merge(a, b);

	// ������
	for (int i = 0; i < La; i++)
	{
		cout << tmpArray[i] << ' ';
	}
	cout << endl;
	return 0;
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
	WaitForSingleObject(hMutex, INFINITE);
	int begin = 0;
	int end = La - 1;
	int mid = (begin + end) / 2;
	for (int i = 0; i <= mid; i++)
	{
		a[i] = array[i];
	}
	sort(a);	
	ReleaseMutex(hMutex);
	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter)
{
	
	WaitForSingleObject(hMutex, INFINITE);
	int begin = 0;
	int end = La - 1;
	int mid = (begin + end) / 2;
	for (int i = mid+1, j = 0; i <= end; i++, j++)
	{
		b[j] = array[i];
	}
	sort(b);
	ReleaseMutex(hMutex);			
	return 0;
}
