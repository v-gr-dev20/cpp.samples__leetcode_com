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
#include "leetcode_com__subarraySum.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

namespace {
LeetcodeCom_Problems::CSubarraySum problem;

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k);
};
} // namespace

int Solution::subarraySum(std::vector<int>& nums, int k) {
	int result = 0;
	std::multiset<int> storedSums;
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

LeetcodeCom_Problems::CSubarraySum::CSubarraySum()
	: CBaseSample( "leetcode_com__subarraySum" )
{
}

LeetcodeCom_Problems::CSubarraySum::~CSubarraySum()
{
}

void LeetcodeCom_Problems::CSubarraySum::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input numbers: ";
	nums = Tools::InputNumbers(iStream);

	oStream << "Input sum: ";
	iStream >> sum;
}

void LeetcodeCom_Problems::CSubarraySum::Run()
{
	result = Solution().subarraySum(nums, sum);
}

void LeetcodeCom_Problems::CSubarraySum::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}

void LeetcodeCom_Problems::CSubarraySum::Clean()
{
	nums.clear();
	sum = 0;
	result = 0;
}
