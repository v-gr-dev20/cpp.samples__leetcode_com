#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CMedianOfTwoSortedArrays : public CBaseSample {
public:
	CMedianOfTwoSortedArrays();
	virtual ~CMedianOfTwoSortedArrays() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
private:
	// https://leetcode.com/problems/median-of-two-sorted-arrays/
	// There are two sorted arrays nums1 and nums2 of size m and n respectively.
	// Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
	std::vector<int> nums1;
	std::vector<int> nums2;
	double result;
};
} // namespace LeetcodeCom_Problems