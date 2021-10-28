// 560. Subarray Sum Equals K
// Medium
// https://leetcode.com/problems/subarray-sum-equals-k
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
//
// Example 1:
// Input: nums = [1, 1, 1], k = 2
// Output : 2
//
// Example 2 :
// Input : nums = [1, 2, 3], k = 3
// Output : 2
//
// 	Constraints :
// 	1 <= nums.length <= 2 * 10^4
// 	- 1000 <= nums[i] <= 1000
// 	- 10^7 <= k <= 10^7

#include "pch.h"
#include "leetcode_com__subarray_sum_equals_k.h"
#include "tools.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	int subarraySum(vector<int>& nums, int k);
};

int Solution::subarraySum(vector<int>& nums, int k) {
	int result = 0;
	multiset<int> storedSums;
	int range0i1Sum = 0;
	for (int i = 0; i < nums.size(); ++i) {
		range0i1Sum += nums[i];
		if (range0i1Sum == k) {
			++result;
		}
		result += storedSums.count(range0i1Sum - k);
		storedSums.insert(range0i1Sum);
	}
	return result;
}
} // namespace

void LeetcodeCom_Problems::CSubarraySumEqualsK::Run()
{
	result = Solution().subarraySum(nums, k);
}
