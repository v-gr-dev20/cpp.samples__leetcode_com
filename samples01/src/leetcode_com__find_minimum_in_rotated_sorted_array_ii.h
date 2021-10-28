#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CFindMinimumInRotatedSortedArrayII : public CBaseSample {
public:
	CFindMinimumInRotatedSortedArrayII();
	virtual ~CFindMinimumInRotatedSortedArrayII() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	std::vector<int> nums;
	int result;
};
} // namespace LeetcodeCom_Problems