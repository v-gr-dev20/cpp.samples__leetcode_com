// Прототип модуля с решением какой-либо задачи
// Для создания нового модуля требуется выполнить ключевые замены-подстановки вместо demo, CNewProblem, new_sample, new_sample.h

#include "pch.h"
#include "new_sample.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>

namespace {
demo::CNewProblem problem;
} // namespace

demo::CNewProblem::CNewProblem()
	: CBaseSample( "new_sample" )
{
}

demo::CNewProblem::~CNewProblem()
{
}

void demo::CNewProblem::Input( std::istream& iStream, std::ostream& oStream )
{
	oStream << "Input hello: ";
	iStream >> input;
}

void demo::CNewProblem::Report( std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + result );
}

void demo::CNewProblem::Clean()
{
	input.clear();
	result.clear();
}
