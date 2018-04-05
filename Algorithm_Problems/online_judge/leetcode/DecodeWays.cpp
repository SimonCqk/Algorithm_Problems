/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

*/
#include<vector>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		int size = s.size();
		vector<int> dp(size + 1, 0);
		dp[0] = 1;
		dp[1] = s[0] != '0' ? 1 : 0;
		for (int i = 2, fir, sec; i <= size; ++i) {
			fir = s[i - 1] - '0', sec = 10 * (s[i - 2] - '0') + fir;
			if (fir >= 1 && fir <= 9)
				dp[i] += dp[i - 1];
			if (sec >= 10 && sec <= 26)
				dp[i] += dp[i - 2];
		}
		return dp[size];
	}
};