#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CSubarraySum : public CBaseSample {
public:
	CSubarraySum();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
	virtual ~CSubarraySum() override;
private:
	std::vector<int> nums;
	int sum;
	int result;
};

} // namespace LeetcodeCom_Problems