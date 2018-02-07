/*
  一个整形数组里除两个数字外，其他数字都出现了两次。
  请找出这两个只出现一次的数字，要求时间复杂度为O(n)，空间复杂度为O(1).
*/
#include<vector>
#include<tuple>

using namespace std;

/*
  如果只是找出一个只出现一次的数字，那么利用异或的性质，从头到尾异或一遍，结果便是
  要找的数字了。现在有两个这样的数字，那么全部异或一遍得到的是这两个数字相异或的结果。
  这两个数字一定不相同，那么异或结果的二进制表示里面，必定有某位是1，把第一位为1的位数
  作为划分标准，把原数组划分成两个子数组，然后对子数组分别异或一遍就OK了。
*/
size_t IndexOfFirstBitOne(int num) {
	size_t index = 0, upper = 8 * sizeof(int);
	while ((num & 0x1) == 0 && (index < upper)) {
		++index;
		num >>= 1;
	}
	return index;
}

bool IsIndexBitOne(int num, const size_t& index) {
	num >>= index;
	return num & 0x1;
}

tuple<int,int> NumsAppearOnce(const vector<int>& nums) {
	if (nums.size() < 2)
		throw std::exception("Invalid nums passed in");
	int xor_ans = 0;
	for (const int& num : nums)
		xor_ans ^= num;
	size_t index = IndexOfFirstBitOne(xor_ans);
	int num_one = 0, num_two = 0;
	for (const int& num : nums) {
		if (IsIndexBitOne(num, index))
			num_one ^= num;
		else
			num_two ^= num;
	}
	return make_tuple(num_one, num_two);
}

int main() {
	vector<int> nums{ 2,4,3,6,3,2,5,5 };
	auto ans = NumsAppearOnce(nums);
	std::printf("%d\n", get<0>(ans));
	std::printf("%d\n", get<1>(ans));
	return 0;
}