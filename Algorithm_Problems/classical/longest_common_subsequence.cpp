//The Longest Common Subsequence
//Take string X and string Y as examples
//#include<map>
#include<iostream>
#include<algorithm>
#include<string>
//#include<vector>
//#include<ctype.h>
//#include<sstream>
//#include<numeric>
//#include<cmath>
//#include<set>

using namespace std;
string X, Y;
const int MAX_LEN = 1001;
int record[MAX_LEN][MAX_LEN];
//record[i][j]stands for the LCS length of X(i),Y(j)
int LCS(const string& X, const string& Y) {
	int x_size = X.size(), y_size = Y.size();
	int max_LCS = 0;

	for (int i = 0; i < x_size; ++i)record[i][0] = 0;
	for (int i = 0; i < y_size; ++i)record[0][i] = 0;

	for (int i = 0; i < x_size; ++i) {
		for (int j = 0; j < y_size; ++j) {
			if (X[i] == Y[j]) {
				if (!(i&&j)) {
					record[i][j] = 1; continue;//i or j ==0 , LCS=1
				}
				record[i][j] = record[i - 1][j - 1] + 1;
			}
			else {
				if (!(i&&j)) {
					record[i][j] = 0; continue;//i or j ==0 , LCS=0
				}
				record[i][j] = max(record[i][j - 1], record[i - 1][j]);
			}
			max_LCS = max(max_LCS, record[i][j]);
		}
	}
	return max_LCS;
}

int main() {
	int n;
	cin >> n;
	int result;
	for (int i = 0; i < n; ++i) {
		cin >> X >> Y;
		result = LCS(X, Y);
		cout << result << endl;
	}
	return 0;
}
