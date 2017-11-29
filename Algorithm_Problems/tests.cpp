#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void GetNum() {
	static int i = 0;
	++i;
	cout<<i<<endl;
}


int main() {
	(GetNum(), GetNum());
	return 0;
}