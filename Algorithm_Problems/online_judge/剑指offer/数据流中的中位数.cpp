/*
  如何得到一个数据流中的中位数？
*/
#include<functional>
#include<vector>
#include<algorithm>

using namespace std;

/*
  用两个堆来维护，左半部分用最大堆，右半部分用最小堆，中位数可以从两个堆的堆顶得出。
*/
template <typename T>
class DynamicArray {
public:
	size_t size() {
		return left.size() + right.size();
	}
	void insert(T data) {
		if (this->size() & 1) { // 奇数
			if (left.size() > 0 && data < left[0]) {
				left.push_back(data);
				std::push_heap(left.begin(), left.end(), less<T>()); // 插入最大堆中
				data = left[0];  // 更新为最大堆中的最大值，将要插入最小堆中
				std::pop_heap(left.begin(), left.end(), less<T>());
				left.pop_back();
			}
			right.push_back(data);
			std::push_heap(right.begin(), right.end(), greater<T>()); 
		}
		else {
			if (right.size() > 0 && data > right[0]) {
				right.push_back(data);
				std::push_heap(right.begin(), right.end(), greater<T>());
				data = right[0];
				std::pop_heap(right.begin(), right.end(), less<T>());
				right.pop_back();
			}
			left.push_back(data);
			std::push_heap(left.begin(), left.end(), less<T>());
		}
	}

	T getMedian() {
		if (this->size() == 0) {
			std::printf("No numbers avaliable");
			throw std::exception("No numbers avaliable");
		}
		if (this->size() & 1) // 奇数
			return left[0];
		else
			return (left[0] + right[0]) / 2;
	}

private:
	vector<T> left;
	vector<T> right;
};

int main() {
	vector<int> arr{ 0,1,4,7,8,5,2,3,6,10 };
	DynamicArray<int> da;
	for (auto i : arr) {
		da.insert(i);
	}
	std::printf("%d\n", da.getMedian());
	return 0;
}