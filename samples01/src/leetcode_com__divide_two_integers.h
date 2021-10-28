#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CDivideTwoIntegers : public CBaseSample {
public:
	CDivideTwoIntegers();
	virtual ~CDivideTwoIntegers() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
private:
	// https://leetcode.com/problems/divide-two-integers/
	// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
	// Return the quotient after dividing dividend by divisor.
	int dividend;
	int divisor;
	int result;
};
} // namespace LeetcodeCom_Problems