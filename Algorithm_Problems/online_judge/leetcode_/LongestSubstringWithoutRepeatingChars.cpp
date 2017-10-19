/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()){
            return 0;
        }
        int size = s.size();
        int ans =0, start=-1;
        std::vector<int> char_idxs(256, -1);
        for (int i = 0; i < size;++i){
            if(char_idxs[s[i]]>start)
                start=char_idxs[s[i]];
            if((i-start)>ans)
                ans = i - start;
            char_idxs[s[i]] = i;
        }
        return ans;
    }

};