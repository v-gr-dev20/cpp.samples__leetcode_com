#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CSubarraySumEqualsK : public CBaseSample {
public:
	CSubarraySumEqualsK();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
	virtual ~CSubarraySumEqualsK() override;
private:
	std::vector<int> nums;
	int sum;
	int result;
};

} // namespace LeetcodeCom_Problems