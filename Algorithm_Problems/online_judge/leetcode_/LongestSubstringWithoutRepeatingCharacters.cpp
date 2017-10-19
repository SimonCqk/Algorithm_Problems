/*
Given a string, find the length of the longest substring without repeating
characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a
substring.
*/

// hash + dp
/*
对于每个当前的元素，我们“回头”去查询是否有与之重复的，如没有，则最长不重复子串长度+1，
如有，则是与第一个重复的字符之后的串构成新的最长不重复子串，新串的长度便是当前元素下标
与重复元素下标之差。
*/
class Solution {
public:
	int lengthOfLongestSubstring(const string& s) {
		if (s.size() <= 1)
			return s.size();
		size_t size = s.size();
		std::vector<int> hash(256, -1);
		std::vector<int> dp(size, 0);
		int max_len = 1;
		int start = 0;
		hash[s[0]] = 0;
		dp[0] = 1;
		for (int i = 1; i < size; ++i) {
			if (hash[s[i]] == -1 || start > hash[s[i]]) { // start > hash[s[i]] is important!!!
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = i - hash[s[i]];
				start = hash[s[i]] + 1;  // start index of new substr.
			}
			hash[s[i]] = i;
			if (dp[i] > max_len)
				max_len = dp[i];
		}
		return max_len;
	}
};

/*
// hashtable-like solution

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
	if (!s.size()) {
	  return 0;
	}
	int size = s.size();
	int ans = 0, start = -1;
	std::vector<int> char_idxs(256, -1);
	for (int i = 0; i < size; ++i) {
	  if (char_idxs[s[i]] > start)
		start = char_idxs[s[i]];
	  if ((i - start) > ans)
		ans = i - start;
	  char_idxs[s[i]] = i;
	}
	return ans;
  }
};

*/