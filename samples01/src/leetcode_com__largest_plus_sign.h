#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CLargestPlusSign : public CBaseSample {
public:
	CLargestPlusSign();
	virtual ~CLargestPlusSign() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
private:
	int n;
	std::vector<std::vector<int>> mines;
	int result;
};
} // namespace LeetcodeCom_Problems