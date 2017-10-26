/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		auto res = mergeSort(nums1, nums2);
		int size = res.size();
		if (size % 2)
			return res[size / 2];
		else
			return (res[size / 2] + res[size / 2 - 1]) / 2.0;
	}
	vector<int> mergeSort(const vector<int>& nums1, const vector<int>& nums2) {
		int size1 = nums1.size(), size2 = nums2.size();
		vector<int> res;
		int i = 0, j = 0;
		while (i < size1 || j < size2) {
			if (i == size1) {
				for (; j < size2; ++j)
					res.push_back(nums2[j]);
				break;
			}
			else if (j == size2) {
				for (; i < size1; ++i)
					res.push_back(nums1[i]);
				break;
			}
			if (nums1[i] > nums2[j])
				res.push_back(nums2[j++]);
			else
				res.push_back(nums1[i++]);
		}
		return res;
	}
};