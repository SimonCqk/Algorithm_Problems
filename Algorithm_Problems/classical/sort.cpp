#include<algorithm>
#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::cin;


//快速排序/分治法
int partiton(int A[], int p, int r) {
	int pivot = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (A[j] <= pivot) {
			i += 1;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);
	return i + 1;
}

void quick_sort(int A[], int p, int r) {
	int q;
	if (p < r) {
		q = partiton(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}




//归并排序
const int INFTY = (1 << 20);
const int MAX_SIZE = 1000;

vector<int> left_vec(MAX_SIZE, 0);
vector<int> right_vec(MAX_SIZE, 0);

void merge(vector<int>&vec, const int& left_child, const int& mid, const int& right_child) {
	int n = mid - left_child;
	int m = right_child - mid;
	for (int i = 0; i < n; ++i)
		left_vec[i] = vec[left_child + i];
	for (int i = 0; i < m; ++i)
		right_vec[i] = vec[mid + i];
	left_vec[n] = right_vec[m] = INFTY;
	int i = 0, j = 0;
	for (int k = left_child; k < right_child; ++k) {
		if (left_vec[i] <= right_vec[j])
			vec[k] = left_vec[i++];
		else
			vec[k] = right_vec[j++];
	}
}

void mergesort(vector<int>&vec, const int& left_child, const int& right_child) { //right_child=vec.size();
	if (left_child + 1 < right_child) {
		int mid = (left_child + right_child) / 2;
		mergesort(vec, left_child, mid);
		mergesort(vec, mid, right_child);
		merge(vec, left_child, mid, right_child);
	}
}

//堆排序

//确定亲/左/右结点的下标
int left_child(const int& i) { return 2 * i; }
int right_child(const int& i) { return 2 * i + 1; }

void maxheapify(vector<int>& vec,const int& num,const int& index) {
	int l = left_child(index); int r = right_child(index);
	int largest;
	//从左/自身/右子结点中选出最大的结点
	if (l <= num && vec[l] > vec[index])
		largest = l;
	else
		largest = index;
	if (r <= num && vec[r] > vec[largest])
		largest = r;
	if (largest != index) {//index的子结点值更大
		std::swap(vec[index], vec[largest]);
		maxheapify(vec, num, largest);
	}
}

void build_maxheap(vector<int>& vec,const int& num) {
	for (int i = num / 2; i >= 0; --i) {
		maxheapify(vec, num, i);
	}
}

int main() {
	cout << "Input the number of samples." << std::endl;
	int num;
	cin >> num;
	cout << "Input the samples." << std::endl;
	vector<int> samples;
	int s;
	for (int i = 0; i < num; ++i) {
		cin >> s;
		samples.push_back(s);
	}
	mergesort(samples, 0, num);
	cout << "[merge sort] The result :" << std::endl;
	for (int i = 0; i < num; ++i) {
		cout << i << " ";
	}
	cout << std::endl;
	samples.resize(2 * num + 1, 0); // 避免越界，堆排序时要索引下标 2*index+1.
	build_maxheap(samples, num);
	cout << "[max heap sort] The result :" << std::endl;
	for (int i = 0; i < num;++i) {
		cout << samples[i] << " ";
	}
	cout << std::endl;
	return 0;
}