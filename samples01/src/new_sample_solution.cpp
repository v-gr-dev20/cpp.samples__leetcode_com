// Прототип модуля с решением какой-либо задачи
// Для создания нового модуля требуется выполнить ключевые замены-подстановки вместо demo, CNewProblem, new_sample, new_sample.h

#include "pch.h"
#include "new_sample.h"

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	std::string new_sample( std::string hello, std::string name );
};

std::string Solution::new_sample( std::string hello, std::string name )
{
	return hello + ", " + name;
}
} // namespace

void demo::CNewProblem::Run()
{
	result = Solution().new_sample( input, Name() );
}
