//Fibonacci Number
#include<iostream>
#include<algorithm>
//#include<string>
//#include<vector>
#define INFTY (1<<30)
#define MAXSIZE 100
using namespace std;

int Fib_recursion(int n) {
	if (n == 0 || n == 1)return 1;
	return Fib_recursion(n - 1) + Fib_recursion(n - 2);
}

int Fib_MEM(int *F, int n) {
	if (n == 0 || n == 1)return *(F + n) = 1;
	if (*(F + n) != -INFTY)return *(F + n);  //F is initialized by F[0]...F[n]=-INFTY;
	return *(F + n) = Fib_MEM(F, n - 1) + Fib_MEM(F, n - 2);
}

int* makeFib_DP(int *F, int n) {
	*F = 1; *(F + 1) = 1;
	for (int i = 2; i <= n; ++i) {
		*(F + i) = *(F + i - 2) + *(F + i - 1);
	}
	return F;
}

int main() {
	int *FIB = new int[MAXSIZE];
	int fib, n;
	cin >> n;
	fib = Fib_recursion(n);
	cout << fib << endl;
	FIB = makeFib_DP(FIB, n);
	cout << FIB[n] << endl;
	for (int i = 0; i < n; ++i)FIB[i] = -INFTY;
	fib = Fib_MEM(FIB, n);
	cout << fib << endl;
	delete FIB;
	return 0;
}

