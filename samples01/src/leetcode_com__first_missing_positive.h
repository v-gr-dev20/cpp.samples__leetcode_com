#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CFirstMissingPositive : public CBaseSample {
public:
	CFirstMissingPositive();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual ~CFirstMissingPositive() override;
private:
	std::vector<int> v;
	int result;
};
} // namespace LeetcodeCom_Problems