#include<vector>
#include<iostream>
#include<string>

using std::string;
using std::vector;


vector<int> GenerateNext(const string& pattern) {
	int len = pattern.size();
	vector<int> next(len + 1, 0);
	next[0] = -1;
	int i = 0, j = -1;
	while (i < len) {
		if (j == -1 || pattern[i] == pattern[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
	return std::move(next);
}

// return the matched times.
int KMP(const string& str, const string& pattern) {
	auto next = GenerateNext(pattern);
	int s_len = str.size(), p_len = pattern.size();
	int i = 0, j = 0, count = 0;
	while (i < s_len) {
		if (j == -1 || str[i] == pattern[j]) {
			if (j == p_len - 1) {  // matched
				++count; j = next[j];
				continue;
			}
			++i; ++j;
		}
		else
			j = next[j];
	}
	return count;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> ans;
	while (n--) {
	string str, pattern;
	std::cin >> pattern >> str;
	ans.push_back(KMP(str, pattern));
	}
	for (auto each : ans)
		std::cout << each << std::endl;
	return 0;
}