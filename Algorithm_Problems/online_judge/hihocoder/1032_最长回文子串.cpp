#include<string>
#include<iostream>

using std::string;

size_t LongestPalindromicSubstring(const string& str) {
	size_t size = str.size();
	if (size <= 1)
		return size;
	int start = 0, max_len = 1;
	int left, right;
	for (size_t i = 0; i < size && (size - i > max_len / 2);) {
		left = right = i;
		while (right < size - 1 && str[right + 1] == str[right])  // skip duplications
			++right;
		i = right + 1;
		while (left > 0 && right < size - 1 && str[right + 1] == str[left - 1]) {
			--left;
			++right;
		}
		if (max_len < right - left + 1) {
			max_len = right - left + 1;
			start = left;
		}
	}
	return max_len;
}

int main() {
	int n;
	std::cin >> n;
	string str;
	while (n--) {
		std::cin >> str;
		std::cout << LongestPalindromicSubstring(str) << std::endl;
	}
	return 0;
}