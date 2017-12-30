#include <Windows.h>
#include <iostream>

using namespace std;

// 函数声明(两个线程函数)
DWORD WINAPI Fun1Proc(LPVOID lpParameter);
DWORD WINAPI Fun2Proc(LPVOID lpParameter);
void sort(int* array);
void MergeSort(int * a, int * temp, int low, int high);
void Merge(int* a, int low, int mid, int high, int* temp);
void Merge(int* a1, int* a2);

// 全局数组
int array[] = {2, 53, 34, 43, 45, 6};
int La = sizeof(array) / sizeof(array[0]); // 数组的长度

int a[100];
int b[100];
// 新增的容器, 存放合并后的数据
int tmpArray[100];

HANDLE hMutex;

// 对数组排序
void sort(int* array) {
	int length = La / 2;
	int temp[100];
	MergeSort(array, temp, 0, length - 1);
}

//二路归并（递归实现）
void MergeSort(int * a, int * temp, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a, temp, low, mid);      //左边有序
		MergeSort(a, temp, mid + 1, high);   //右边有序
		Merge(a, low, mid, high, temp);     //再将两个有序序列合并
	}
}

//将数组 a[low,mid] 与 a(mid,high] 合并（归并）
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

// 合并序列(函数的重载)
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
	// 互斥信号量
	hMutex = CreateMutex(NULL, FALSE, NULL);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	// 之所以加这句话, 是为了让两个线程完成分组排序后, 
	// 再合并, 如果不加, 输出的结果是全部是0, 当然也有相关线程操作API可用
	// 但C++学得很水, 找不到!
	Sleep(1); 
	Merge(a, b);

	// 输出结果
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
