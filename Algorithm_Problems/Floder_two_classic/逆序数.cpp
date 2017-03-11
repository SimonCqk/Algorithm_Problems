//利用归并排序实现逆序数处理
//逆序数与冒泡排序交换次数相同，但是时间复杂度太大
#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX 100000
#define SENTINEL 200000000
typedef long long llong;

using namespace std;

int L[MAX + 2], R[MAX + 2];
llong merge_vector(int A[], int left, int mid, int right) {
	int n = mid - left;
	int m = right - mid;
	llong count_ = 0;
	for (int i = 0; i < n; ++i)L[i] = A[left + i];
	for (int i = 0; i < m; ++i)R[i] = A[mid + i];
	L[n] = R[m] = SENTINEL;
	int i = 0, j = 0;
	for (int k = left; k < right; ++k) {
		if (L[i] <= R[j])A[k] = L[i++];
		else {
			A[k] = R[j++]; count_ += n - i;
		}
	}
	return count_;
}

llong Mergesort_Sort(int A[], int left, int right) {
	int mid;
	llong c1, c2, c3;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		c1=Mergesort_Sort(A, left, mid);
		c2=Mergesort_Sort(A, mid, right);
		c3=merge_vector(A, left, mid, right);
		return c1 + c2 + c3;
	}
	else return 0;
}

int main() {
	int A[] = { 5,3,6,2,1,4 };
	llong answer = Mergesort_Sort(A, 0, 6);
	cout << answer;
	return 0;
}