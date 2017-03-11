//	快速排序/分治法

/*
int Partiton(int A[], int p, int r) {
	int pivot = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (A[j] <= pivot) { i += 1; std::swap(A[i], A[j]); }
	}
	std::swap(A[i + 1], A[r]);
	return i + 1;
}

void Quick_Sort(int A[], int p, int r) {
	int q;
	if (p < r) {
		q = Partiton(A, p, r);
		Quick_Sort(A, p, q - 1);
		Quick_Sort(A, q + 1, r);
	}
}

*/

/*
归并排序
#define MAX 100000
#define SENTINEL 200000000

int L[MAX + 2], R[MAX + 2];
void merge_vector(vector<int>&A, int left, int mid, int right) {
int n = mid - left;
int m = right - mid;
for (int i = 0; i < n; ++i)L[i] = A[left + i];
for (int i = 0; i < m; ++i)R[i] = A[mid + i];
L[n] = R[m] = SENTINEL;
int i = 0, j = 0;
for (int k = left; k < right; ++k) {
if (L[i] <= R[j])A[k] = L[i++];
else A[k] = R[j++];
}
}

void Mergesort_Vector(vector<int>&A, int left, int right) {//right=A.size();
if (left + 1 < right) {
int mid = (left + right) / 2;
Mergesort_Vector(A, left, mid);
Mergesort_Vector(A, mid, right);
merge_vector(A, left, mid, right);
}
}
*/