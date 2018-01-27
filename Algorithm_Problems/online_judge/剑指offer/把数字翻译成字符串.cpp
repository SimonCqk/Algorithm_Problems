/*
  给定一个数字，按照如下规则翻译成字符串：
  0翻译成'a'，1翻译成'b'...25翻译成'z'。
  一个数字可能有多少种翻译？例如12258可以翻译成:
  "bccfi","bwfi","bczi","mcfi","mzi"
*/
#include<string>
#include<vector>

using namespace std;

// 递归自上而下，会有重复子问题
// 所以利用动态规划，从末尾开始，自下而上
int GetTranslationCount(const int& num) {
	if (num < 0)
		return 0;
	string num_str = to_string(num);
	int size = num_str.size();
	vector<int> dp(size, 0);
	dp[size - 1] = 1;
	int count;
	for (int i = size - 2; i >= 0; --i) {
		count = dp[i + 1];
		int digit1 = num_str[i] - '0';
		int digit2 = num_str[i + 1] - '0';
		int converted = 10 * digit1 + digit2;
		if (converted >= 10 && converted <= 25)
			count += (i < size - 2) ? dp[i + 2] : 1;
		dp[i] = count;
	}
	return dp[0];
}

int main() {
	std::printf("%d\n", GetTranslationCount(12258));
	return 0;
}


