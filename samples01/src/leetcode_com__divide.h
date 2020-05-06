#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CDivideTwoIntegers : public CBaseSample {
public:
	CDivideTwoIntegers();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual ~CDivideTwoIntegers() override;
private:
	int dividend;
	int divisor;
	int result;
};

} // namespace LeetcodeCom_Problems