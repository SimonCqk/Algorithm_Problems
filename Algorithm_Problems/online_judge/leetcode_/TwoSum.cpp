/*
Given an array of integers, return indices of the two numbers such that 
they add up to a specific target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t size = nums.size();
        for (size_t i = 0; i < size;++i){
            for (size_t j = 0; j < size;++j){
                if(i!=j&&(nums[i]+nums[j])==target)
                    return {i, j};
            }
        }
            
    }
};