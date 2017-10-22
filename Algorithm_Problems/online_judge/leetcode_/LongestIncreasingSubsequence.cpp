/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

// dp + binary search  ------> O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size<=1)
            return size;
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 0; i < size;++i){
            if(*(lis.end()-1)<nums[i])  // compare nums[i] between last element of lis[].
                lis.push_back(nums[i]);
            else
                *(std::lower_bound(lis.begin(), list.end(), nums[i])) = nums[i];
        }
        return lis.size();
    }
};