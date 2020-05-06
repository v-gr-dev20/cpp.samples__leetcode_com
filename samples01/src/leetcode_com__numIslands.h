#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CNumberOfIslands : public CBaseSample {
public:
	CNumberOfIslands();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual ~CNumberOfIslands() override;
private:
	std::vector<std::vector<char>> grid;
	int result;
};

} // namespace LeetcodeCom_Problems