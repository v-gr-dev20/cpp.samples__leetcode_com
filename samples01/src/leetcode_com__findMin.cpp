// 154. Find Minimum in Rotated Sorted Array II
// Hard
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
//
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

#include "pch.h"
#include "leetcode_com__findMin.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <string>
#include <vector>

namespace {
LeetcodeCom_Problems::CFindMin problem;

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums);
private:
	pair<int,bool> doFindMinAndAreAllEq(vector<int>::const_iterator first, vector<int>::const_iterator last);
};
} // namespace

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

int Solution::findMin(vector<int>& nums)
{
	assert(!nums.empty());
	return doFindMinAndAreAllEq(nums.begin(), nums.end() - 1).first;
}

LeetcodeCom_Problems::CFindMin::CFindMin()
	: CBaseSample( "leetcode_com__findMin" )
{
}

LeetcodeCom_Problems::CFindMin::~CFindMin()
{
}

void LeetcodeCom_Problems::CFindMin::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input vector: ";
	nums = Tools::InputNumbers(iStream);
}

void LeetcodeCom_Problems::CFindMin::Run()
{
	result = Solution().findMin(nums);
}

void LeetcodeCom_Problems::CFindMin::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}

void LeetcodeCom_Problems::CFindMin::Clean()
{
	nums.clear();
}
