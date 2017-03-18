//MAX_HEAP    MIN_HEAP
#include<iostream>
#include<algorithm>
//#include<string>
#include<vector>
using namespace std;

//确定亲/左/右结点的下标
int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

// *REMARK:从下标i=1开始存储
void BuildCBT(vector<int>& CBT, int N) {
	CBT.resize(2 * N + 2);
	cout << "Input the nodes : " << endl;
	for (int i = 1; i <= N; ++i) { cin >> CBT[i]; }
}

void MaxHeapify(vector<int>& CBT, int N, int i) {
	int L = left(i); int R = right(i);
	int largest;
	//从左/自身/右子结点中选出最大的结点
	if (L <= N&&CBT[L] > CBT[i])largest = L;
	else largest = i;
	if (R <= N&&CBT[R] > CBT[largest])largest = R;
	if (largest != i) {//i的子结点值更大
		std::swap(CBT[i], CBT[largest]);
		MaxHeapify(CBT, N, largest);
	}
}

void BuildMaxHeap(vector<int>& BCT, int N) {
	for (int i = N / 2; i >= 1; --i) {
		MaxHeapify(BCT, N, i);
	}
}

void PrintHeap(const vector<int> CBT, int N) {
	for (int i = 1; i <= N; ++i)cout << CBT[i] << " ";
	cout << endl;
}
int main() {
	int N;
	cout << "Input the number of CBT nodes :";
	cin >> N;
	vector<int> CBT;
	BuildCBT(CBT, N);
	BuildMaxHeap(CBT, N);
	PrintHeap(CBT, N);
	return 0;
}
