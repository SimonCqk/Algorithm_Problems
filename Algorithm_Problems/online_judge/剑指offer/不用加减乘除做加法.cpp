/*
  写一个函数，求两个整数之和，要求在函数体内不得使用 '+','-','*','/'四则运算符号
*/
#include<iostream>

/*
 1. 不考虑进位，对各位相加减，1+1->0 0+1=1+0=1 0+0=0, 与异或运算相同
 2. 考虑进位，只有1+1相加才会有进位：因此先做与运算，再向左移动一位，若
	无进位，结果为0.
 3. 重复1和2，直至没有进位

*/

int Add(int lhs, int rhs) {
	int sum, carry;
	do {
		sum = lhs ^ rhs;
		carry = (lhs&rhs) << 1;
		lhs = sum;
		rhs = carry;
	} while (rhs);
	return lhs;
}
