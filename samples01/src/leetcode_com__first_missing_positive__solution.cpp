// 41. First Missing Positive
// Hard
// https://leetcode.com/problems/first-missing-positive/
// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
// Input: [1, 2, 0]
// Output : 3
//
// Example 2:
// 	Input : [3, 4, -1, 1]
// 	Output : 2
//
// Example 3:
// Input: nums = [7, 8, 9, 11, 12]
// Output : 1
//
// Constraints:
// 	1 <= nums.length <= 5 * 10^5
// 	- 2^31 <= nums[i] <= 2^31 - 1

#include "pch.h"
#include "leetcode_com__first_missing_positive.h"
#include "tools.h"
#include <vector>

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	int firstMissingPositive( vector<int>& nums );
private:
	int splitByMedian( vector<int>& nums, int left, int right, int medianValue );
	int findFirstMissed( vector<int>& nums, int left, int right, int beginValue );
};

// Time:  O(n*log n)
// Space: O(log n)
int Solution::firstMissingPositive( vector<int>& nums )
{
	int firstPositivePos = splitByMedian( nums, 0, nums.size() - 1, 1 );
	return firstPositivePos < 0 ? 1 : findFirstMissed( nums, firstPositivePos, nums.size() - 1, 1 );
}

int Solution::splitByMedian( vector<int>& nums, int left, int right, int medianValue )
{
	if( right < left ) {
		return -1;
	}
	while( true ) {
		while( left < right && nums[left] < medianValue ) {
			++left;
		}
		while( left < right && medianValue <= nums[right] ) {
			--right;
		}
		if( left == right ) {
			return nums[right] < medianValue ? -1 : right;
		}
		swap( nums[left], nums[right] );
		++left;
	}
}

int Solution::findFirstMissed( vector<int>& nums, int left, int right, int beginValue )
{
	if( right < left ) {
		return beginValue;
	}
	if( left == right ) {
		return nums[right] == beginValue ? beginValue + 1 : beginValue;
	}
	int medianShift = ( right - left + 1 ) / 2;
	int medianValue = max( beginValue + 1, min( beginValue + medianShift, nums[right] ) );
	int medianPos = splitByMedian( nums, left, right, medianValue );
	if( medianPos < 0 && beginValue + 1 == medianValue ) {
		return beginValue + 1;
	}
	int probablyMissed = findFirstMissed( nums, left, medianPos - 1, beginValue );
	return probablyMissed < medianValue
		? probablyMissed
		: findFirstMissed( nums, medianPos, right, probablyMissed );
}
} // namespace

void LeetcodeCom_Problems::CFirstMissingPositive::Run()
{
	result = Solution().firstMissingPositive( nums );
}
