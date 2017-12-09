/*
  把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
  输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
*/

int FindMin(const std::vector<int>& arr) {
	if (arr.empty())
		throw std::exception("Invalid array.");
	if (arr.size() == 1)
		return arr[0];
	int begin = 0, end = arr.size();
	while (begin < end) {
		int mid = (begin + end) / 2;
		if (arr[mid] > arr[begin])
			begin = mid + 1;
		else if (arr[mid] < arr[begin])
			end = mid;
		else
			--end;  // 缩小范围，相当于顺序查找
	}
	return arr[begin];
}