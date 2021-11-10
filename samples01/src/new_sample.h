#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace demo {

class CNewProblem : public CBaseSample {
public:
	CNewProblem();
	virtual ~CNewProblem() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
private:
	std::string input;
	std::string result;
};
} // namespace demo