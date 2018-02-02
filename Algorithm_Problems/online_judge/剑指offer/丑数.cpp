/*
  我们把只包含因子2,3,5的数称为丑数，求按从小到大顺序的第1500个丑数。
  我们在习惯上把1当成第一个丑数。
*/
#include<vector>
#include<algorithm>

using namespace std;

/*
bool IsUgly(int number) {
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	return (number == 1) ? true : false;
}
*/

/*
  顺序边查找边计算是非常耗时的。
  直接从已有的丑数推出下一个丑数，跳过中间的非丑数。下一个丑数一定是现有某个丑数的2/3/5倍，
  那么从现有丑数的2/3/5倍中找出第一个大于现有最大丑数的数。
  为了避免重复计算，维护3个下标分别指向现有某丑数的2/3/5倍数小于等于当前最大丑数的最大下标，
  下一次直接从这些下表里面找。
*/
long long GetUglyNumber(const int& index) {
	if (index <= 0)
		return 0;
	vector<long long> ugly_numbers(index, 0);
	ugly_numbers[0] = 1;
	int next = 1;
	int mul2_idx, mul3_idx, mul5_idx;
	mul2_idx = mul3_idx = mul5_idx = 0;
	while (next < index) {
		long long min = std::min(std::min(ugly_numbers[mul2_idx] * 2, ugly_numbers[mul3_idx] * 3), ugly_numbers[mul5_idx] * 5);
		ugly_numbers[next] = min;
		while (ugly_numbers[mul2_idx] * 2 <= ugly_numbers[next])
			++mul2_idx;
		while (ugly_numbers[mul3_idx] * 3 <= ugly_numbers[next])
			++mul3_idx;
		while (ugly_numbers[mul5_idx] * 5 <= ugly_numbers[next])
			++mul5_idx;
		++next;
	}
	return ugly_numbers[index - 1];
}


int main() {
	std::printf("%d\n", GetUglyNumber(1500));
	return 0;
}