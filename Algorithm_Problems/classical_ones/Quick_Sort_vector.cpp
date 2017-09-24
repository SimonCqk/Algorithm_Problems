#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& A, int left, int right, int who) {
	for (int i = left; i<right; ++i) {
		if (A[i] <= who) {
			swap(A[i], A[left]);
			left++;
		}
	}
	return left - 1;
}

void qsort(vector<int>& A, int left, int right) {
	if (left >= right) return;

	int middle = left + (right - left) / 2;
	swap(A[middle], A[left]);
	int midpoint = partition(A, left + 1, right, A[left]);
	swap(A[left], A[midpoint]);
	qsort(A, left, midpoint);
	qsort(A, midpoint + 1, right);
}

inline void printVector(vector<int>& A) {
	int size = A.size();
	for (int i = 0; i<size; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
}

int main()
{
	cout << "Quick Sort for vector" <<endl
         <<" "Ctrl+Z" end inputing <------    "
         << endl;
	vector<int>A;
    int mem;
    while(cin>>mem)A.push_back(mem);
    qsort(A,0,A.size());
    printVector(A);
	return 0;
}