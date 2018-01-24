/*
  8x8国际象棋上摆放8个皇后，使其不能互相攻击，即任意两个皇后不得处在
  同一行，同一列，或者同一条对角线上。总共有多少种排法？
*/

/*
  实际是 全排列 问题，可以参考<字符串的排列>的解法。
  用array[8]代表行，array[]中的值即列
  问题就转换成了array[8]中的数 0,1,2...7的全排列问题
  只要再判断对角线是否有相同元素
*/
#include<array>

constexpr int kChessBoard = 8;

bool IsValid(const std::array<int, kChessBoard>& arr) {
	for (int i = 0; i < arr.size(); ++i) {  // i&j 都不能用size_t，会隐式转换 & 向下溢出.
		int j = (i - arr[i]) >= 0 ? (i - arr[i]) : 0;
		for (; j < arr.size(); ++j) {  // 检查左上-右下对角线
			if (arr[j] == (j + arr[i] - i) && j != i)
				return false;
		}
		j = (i + arr[i]) >= arr.size() ? arr.size() - 1 : (i + arr[i]);
		for (; j >= 0; --j) {  // 检查左下-右上对角线
			if ((j + arr[j]) == i + arr[i] && j != i)
				return false;
		}
	}
	return true;
}

int QueenPermutation(const int& count = kChessBoard) {
	std::array<int, kChessBoard> queen;
	for (int i = 0; i < kChessBoard; ++i)
		queen[i] = i;  // 初始化queen数组，使其最小升序排列。
	int ans = 0;
	if (IsValid(queen))
		++ans;
	int end = kChessBoard - 1;
	int pos = end;
	int next, min;
	while (pos > 0) {
		next = pos;
		--pos;
		if (queen[pos] < queen[next]) {
			min = end;
			while (queen[min] <= queen[pos])
				--min;
			std::swap(queen[pos], queen[min]);
			std::reverse(queen.begin() + next, queen.end());
			if (IsValid(queen))
				++ans;
			pos = end;
		}
	}
	return ans;
}

int main() {
	std::printf("%d\n", QueenPermutation());
	return 0;
}