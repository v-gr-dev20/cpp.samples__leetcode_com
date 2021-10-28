#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CFindFirstAndLastPositionOfElementInSortedArray : public CBaseSample {
public:
	CFindFirstAndLastPositionOfElementInSortedArray();
	virtual ~CFindFirstAndLastPositionOfElementInSortedArray() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
	// Given an array of integers nums sorted in ascending order, find the startingand ending position of a given target value.
	std::vector<int> nums;
	int target;
	std::vector<int> result;
};
} // namespace LeetcodeCom_Problems