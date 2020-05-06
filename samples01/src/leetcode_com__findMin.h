#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CFindMin : public CBaseSample {
public:
	CFindMin();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
	virtual ~CFindMin() override;
private:
	std::vector<int> nums;
	int result;
};

} // namespace LeetcodeCom_Problems