#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CDistinctSubsequences : public CBaseSample {
public:
	CDistinctSubsequences();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual ~CDistinctSubsequences() override;
private:
private:
	std::string s;
	std::string t;
	int result;
};

} // namespace LeetcodeCom_Problems