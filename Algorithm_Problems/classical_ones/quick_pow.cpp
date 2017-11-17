#include<iostream>
using namespace std;

long long int fast_pow(int x, int n) {

	long long int ans = 1;
	while (n > 0) {
		if (n % 2)
			ans *= x;
		x *= x;
		n >>= 1;
	}
	return ans;
}

int main() {
	std::cout << fast_pow(2, 50) << std::endl;
	return 0;
}