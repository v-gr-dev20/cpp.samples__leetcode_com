#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CDistinctSubsequences : public CBaseSample {
public:
	CDistinctSubsequences();
	virtual ~CDistinctSubsequences() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	// https://leetcode.com/problems/distinct-subsequences/
	// Given two strings s and t, return the number of distinct subsequences of s which equals t.
	std::string s;
	std::string t;
	int result;
};
} // namespace LeetcodeCom_Problems