/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12)
			return {};
		vector<string> ans;
		dfs(s, 0, 0, "", ans);
		return ans;
	}

	void dfs(const string& s, int index, int step, string ip, vector<string>& ans) {
		if (index == s.size() && step == 4) {
			ip.erase(ip.end() - 1);  // remove extra '.'
			ans.push_back(ip);
			return;
		}
		if (s.size() - index > (4 - step) * 3)
			return;
		if (s.size() - index < (4 - step))
			return;
		for (int num = 0, i = index; i < i + 3 && i < s.size(); ++i) {
			num = num * 10 + (s[i] - '0');
			if (num <= 255) {
				ip += s[i];
				dfs(s, i + 1, step + 1, ip + '.', ans);
			}
			if (num == 0) // '0' is allowed to appear once
				break;
		}
	}
};

int main() {
	Solution s;
	auto ans = s.restoreIpAddresses("25525511135");
	for (auto each : ans) {
		printf("%s\n", each.c_str());
	}
	return 0;
}