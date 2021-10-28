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
private:
	std::vector<int> numbers;
	int target;
	std::vector<int> result;
};
} // namespace LeetcodeCom_Problems