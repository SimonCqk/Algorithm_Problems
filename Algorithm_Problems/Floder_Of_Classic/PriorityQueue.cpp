//Priority Queue
//利用HeapSort实现
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define INFTY (1<<30)
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

void HeapIncreaseKey(vector<int>& CBT, int N, const int key) {
	if (key < CBT[N]) { cout << "Error Inputting! \n"; return; }
	CBT[N] = key;
	while (N > 1 && CBT[parent(N)] < CBT[N]) {
		std::swap(CBT[parent(N)], CBT[N]);
		N = parent(N);
	}
}

int ExtractMax(vector<int>& CBT, int N) {
	if (N < 1) { return -INFTY; }
	int maxitem = CBT[1];
	CBT[1] = CBT[N];
	--N;
	MaxHeapify(CBT, N, 1);
	return maxitem;
}

void Insert(const int key, vector<int>& CBT, int N) {
	++N;
	CBT[N] = -INFTY;
	HeapIncreaseKey(CBT, N, key);
}
int main() {
	int key;
	string cmd;
	vector<int> CBT;
	int N;
	cout << "Input the number of CBT nodes :";
	cin >> N;
	BuildCBT(CBT, N);
	cout << "Input the commands , \'end\' to exit " << endl;
	while (true) {
		cin >> cmd;
		if (cmd == "end")break;
		if (cmd == "insert") {
			cin >> key;
			Insert(key, CBT, N);
		}
		else if (cmd == "extract") {
			cout << "Extract and delete the max element " << ExtractMax(CBT, N) << endl;
		}
		else break;
	}
	return 0;
}

