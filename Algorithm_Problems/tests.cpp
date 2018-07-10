#include <iostream>
#include <string>
#include<limits>
#include<cmath>

using namespace std;

static unsigned long rev(unsigned long v) {
	unsigned long s = 8 * sizeof(v); // bit size; must be power of 2
	unsigned long mask = ~0;
	while ((s >>= 1) > 0) {
		mask ^= (mask << s);
		v = ((v >> s) & mask) | ((v << s) & ~mask);
	}
	return v;
}

int main() {
	cout << std::numeric_limits<int>::min() << endl;
	cout << std::numeric_limits<int>::max() << endl;
	return 0;
}