// Matrix Chain Multiplication solution
#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;

const int INFTY = (1 << 20);
int num;
vector<int> matrixs;

int solve(const vector< int>& mats) {
	/* mul_res[i,j] = Minimum number of scalar multiplications needed
	to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
	dimension of A[i] is p[i-1] x p[i] */
	array<array<int, 500>, 500> mul_res;
	for (auto &item : mul_res) {
		item.fill(0);
	}
	for (int n = 2; n <= num; ++n) //n is the number of matrix under multiplication
		for (int i = 1; i <= num - n + 1; ++i) {
			int j = i + n - 1;
			mul_res[i][j] = INFTY;
			for (int k = i; k < j; ++k)
				mul_res[i][j] = min(mul_res[i][j], mul_res[i][k] + mul_res[k + 1][j] + mats[i - 1] * mats[k] * mats[j]);
		}
	return mul_res[1][num];
}

/*
Mi = p(i-1) x p(i)
Mj = p(i) x p(i+)
number of multiplication of Mi x Mj = p(i-1)*p(i)*p(i+1)
*/

int main() {
	cin >> num;
	int c;
	for (int i = 0; i <= num; ++i) {
		cin >> c;
		matrixs.push_back(c);
	}
	cout << solve(matrixs) << endl;
	return 0;
}