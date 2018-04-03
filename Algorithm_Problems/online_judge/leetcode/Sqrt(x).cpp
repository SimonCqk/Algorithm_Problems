/*
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
*/

class Solution {
public:
	int mySqrt(int x) {
		long cur = 0;
		int ans = 0;
		while (cur*cur < x) {
			++cur; ++ans;
		}
		return (ans > 0 && cur*cur != x) ? ans - 1 : ans;
	}
};