/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        stringstream s;
        s<<x;
        string str;
        s>>str;
        int end=str.size()-1;
        for (int i = 0, j = end; i < j; ++i, --j) {
			if (str[i] != str[j])
				return false;
		}
		return true;
    }
};