// 34. Find First and Last Position of Element in Sorted Array
// Medium
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Given an array of integers nums sorted in ascending order, find the startingand ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
//
// Example 1:
// Input: nums = [5, 7, 7, 8, 8, 10], target = 8
// Output : [3, 4]
//
// Example 2 :
// 	Input : nums = [5, 7, 7, 8, 8, 10], target = 6
// 	Output : [-1, -1]
//
// 	Example 3 :
// 	Input : nums = [], target = 0
// 	Output : [-1, -1]
//
// 	Constraints :
// 	0 <= nums.length <= 10^5
// 	- 10^9 <= nums[i] <= 10^9
// 	nums is a non - decreasing array.
// 	- 10^9 <= target <= 10^9

#include "pch.h"
#include "leetcode_com__find_first_and_last_position_of_element_in_sorted_array.h"
#include <vector>

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	vector<int> searchRange( vector<int>& nums, int target );
};

// Time:  O(log n)
// Space: O(1)
vector<int> Solution::searchRange( vector<int>& nums, int target )
{
	const vector<int> noResult = { -1, -1 };
	if( nums.size() == 0 ) {
		return noResult;
	}
	vector<int> result;
	int leftPos = 0;
	int rightPos = nums.size() - 1;
	int prevRightPos = rightPos;
	while( leftPos < rightPos && nums[leftPos] < target && target <= nums[rightPos] ) {
		int middlePos = leftPos + ( rightPos - leftPos ) / 2;
		if( nums[middlePos] < target ) {
			if( middlePos == leftPos ) {
				break;
			}
			leftPos = middlePos;
		} else if( target < nums[middlePos] ) {
			prevRightPos = rightPos = middlePos;
		} else {
			rightPos = middlePos;
		}
	}
	if( nums[leftPos] < target && target < nums[rightPos] || target < nums[leftPos] || nums[rightPos] < target ) {
		return noResult;
	} 
	result.push_back( nums[leftPos] == target ? leftPos : rightPos );
	
	leftPos = result.front();
	rightPos = prevRightPos;
	while( leftPos < rightPos && nums[leftPos] == target && target < nums[rightPos] ) {
		int middlePos = leftPos + ( rightPos - leftPos ) / 2;
		if( target < nums[middlePos] ) {
			rightPos = middlePos;
		} else {
			if( middlePos == leftPos ) {
				break;
			}
			leftPos = middlePos;
		}
	}
	result.push_back( nums[rightPos] == target ? rightPos : leftPos );
	return result;
}
} // namespace

void LeetcodeCom_Problems::CFindFirstAndLastPositionOfElementInSortedArray::Run()
{
	result = Solution().searchRange( nums, target );
}
