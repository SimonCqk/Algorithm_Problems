/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
*/

/*
---- ^ bit operation ----
1^1=0;
1^0=0^1=1;
0^0=0;

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        auto v_size=nums.size();
        int result=nums[0];
        for(int i=1;i<v_size;++i){
            result^=nums[i];
        }
        return result;
    }
};