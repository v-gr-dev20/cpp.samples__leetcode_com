#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CMedianOfTwoSortedArrays : public CBaseSample {
public:
	CMedianOfTwoSortedArrays();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual ~CMedianOfTwoSortedArrays() override;
private:
	std::vector<int> v1;
	std::vector<int> v2;
	double result;
};
} // namespace LeetcodeCom_Problems