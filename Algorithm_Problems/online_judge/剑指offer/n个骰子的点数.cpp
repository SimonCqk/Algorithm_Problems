/*
  把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出所有可能的值的概率。
*/
#include<vector>

using namespace std;

constexpr int kMaxDiceValue = 6;

void PrintProbability(int number) {
	if (number < 1)
		return;
	vector<vector<int>> probability(2, vector<int>(kMaxDiceValue*number + 1, 0));
	int flag = 0;
	std::fill(probability[0].begin(), probability[0].begin() + kMaxDiceValue, 1); // 第一次0...6都出现一次
	for (int k = 2; k <= number; ++k) {
		std::fill(probability[1 - flag].begin(), probability[1 - flag].begin() + k, 0);  // 初始化
		for (int i = k; i < k*kMaxDiceValue; ++i) {
			probability[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= kMaxDiceValue; ++j) {
				// 当前的和为n，则出现的次数应为之前和为n-1,n-2...n-6的次数的总和
				// 因为当前的和为n，可能是最新加入的骰子出现1，则n=1+(n-1),若最新
				// 出现2，则n=2+(n-1)...以此类推
				probability[1 - flag][i] += probability[flag][i - j];
			}
		}
		flag = 1 - flag;
	}
	double total = std::pow(kMaxDiceValue, number);
	for (auto beg = probability[flag].begin() + kMaxDiceValue; beg + kMaxDiceValue != probability[flag].end(); ++beg) {
		std::printf("%.6f\n", static_cast<double>(*beg) / total);
	}
}

int main() {
	PrintProbability(6);
	return 0;
}