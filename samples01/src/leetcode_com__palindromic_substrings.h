#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CPalindromicSubstrings : public CBaseSample {
public:
	CPalindromicSubstrings();
	virtual ~CPalindromicSubstrings() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	// https://leetcode.com/problems/palindromic-substrings/
	// Given a string s, return the number of palindromic substrings in it.
	std::string s;
	int result;
};
} // namespace LeetcodeCom_Problems