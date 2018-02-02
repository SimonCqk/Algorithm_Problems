/*
  字符串中第一个只出现一次的字符。
*/

/*
  ASIIC字符串只有256个字符，所以可以直接空间换时间，维护一个简单的hash table
  来保存字符出现的次数。
*/
#include<string>
#include<vector>

using namespace std;

char FirstNonRepeating(const string& str) {
	constexpr int table_size = 256;
	vector<int> hash(table_size, 0);
	for (const char& ch : str)
		hash[ch]++;
	for (const char& ch : str)
		if (hash[ch] == 1)
			return ch;
	return '\0';
}

int main() {
	string s = "abaccdeff";
	std::printf("%c\n", FirstNonRepeating(s));
	return 0;
}