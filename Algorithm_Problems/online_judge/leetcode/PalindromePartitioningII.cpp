/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example:

Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		int size = s.size();
		vector<int> dp(size + 1, 0);
		dp[0] = -1;
		// matrix isPalindrome[][] stands for the result whether str[i...j] is 
		// a palindrome or not.
		vector<vector<bool>> isPalindrome(size, vector<bool>(size, false));
		// calculate isPalindrome matrix
		for (int i = 0; i < size; ++i) {
			isPalindrome[i][i] = true;
			if (i + 1 < size)
				isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
		}
		for (int i = size - 1; i >= 0; --i)
			for (int j = i + 2; j < size; ++j) {
				isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && (s[i] == s[j]);
			}
		for (int i = 1; i <= size; ++i) {
			dp[i] = i - 1;
			for (int j = 0; j < i; ++j) {
				if (isPalindrome[j][i - 1])
					dp[i] = std::min(dp[i], dp[j] + 1);
			}
		}
		return dp[size];
	}
};