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
private:
	std::string s;
	std::string t;
	int result;
};
} // namespace LeetcodeCom_Problems