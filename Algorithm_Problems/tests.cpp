#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main() {
	set<vector<int>> vec;
	vec.insert({ 1,2,3 });
	vec.insert({ 2,3,4 });
	vec.insert({ 1,2,3 });
	for (auto& v : vec) {
		for (auto& item : v) {
			cout << item << " ";
		}
		cout << endl;
	}
	return 0;
}

