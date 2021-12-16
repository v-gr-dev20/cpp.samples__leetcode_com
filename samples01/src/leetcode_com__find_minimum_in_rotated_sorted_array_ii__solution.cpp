// 154. Find Minimum in Rotated Sorted Array II
// Hard
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii
// Suppose an array of length n sorted in ascending order is rotated between 1 and n times.For example, the array nums = [0, 1, 4, 4, 5, 6, 7] might become :
// [4, 5, 6, 7, 0, 1, 4] if it was rotated 4 times.
// [0, 1, 4, 4, 5, 6, 7] if it was rotated 7 times.
// Notice that rotating an array[a[0], a[1], a[2], ..., a[n - 1]] 1 time results in the array[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]].
// Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
// You must decrease the overall operation steps as much as possible.
// 
// Example 1:
// Input: nums = [1, 3, 5]
// Output : 1
//
// Example 2 :
// 	Input : nums = [2, 2, 2, 0, 1]
// 	Output : 0
// 
// 	Constraints :
// 	n == nums.length
// 	1 <= n <= 5000
// 	- 5000 <= nums[i] <= 5000
// 	nums is sorted and rotated between 1 and n times.
// 
// 	Follow up : This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates.Would this affect the runtime complexity ? How and why ?

#include "pch.h"
#include "leetcode_com__find_minimum_in_rotated_sorted_array_ii.h"
#include "myAssert.h"
#include <string>
#include <vector>
#include <utility>

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	int findMin(vector<int>& nums);
private:
	pair<int,bool> doFindMinAndAreAllEq(vector<int>::const_iterator first, vector<int>::const_iterator last);
};

int Solution::findMin(vector<int>& nums)
{
	assert(!nums.empty());
	return doFindMinAndAreAllEq(nums.begin(), nums.end() - 1).first;
}

// Time:  O(n*log n)
// Space: O(log n)
pair<int, bool>  Solution::doFindMinAndAreAllEq(vector<int>::const_iterator first, vector<int>::const_iterator last)
{
	bool areAllEq = true;
	while (true) {
		if (*first < *last) {
			return make_pair(*first, false);
		}
		auto median = first + (last - first) / 2;
		if (*last < *median) {
			if (first == median) {
				return make_pair(*last, false);
			}
			areAllEq = false;
			first = median + 1;
		} else if (*median < *first) {
			areAllEq = false;
			last = median;
			++first;
		} else {
			if (first == median) {
				return make_pair(*first, areAllEq);
			}
			auto rightSearch = doFindMinAndAreAllEq(median + 1, last);
			if (rightSearch.first < *median) {
				return make_pair(rightSearch.first, false);
			}
			if (*median < rightSearch.first) {
				areAllEq = false;
			} else if (!rightSearch.second) {
				return make_pair(*median, false);
			}
			last = median - 1;
		}
	}
}
} // namespace

void LeetcodeCom_Problems::CFindMinimumInRotatedSortedArrayII::Run()
{
	result = Solution().findMin(nums);
}
