#include "pch.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

namespace testing {
	::std::string CaseName() { return ::std::string( testing::UnitTest::GetInstance()->current_test_info()->test_case_name() ); };
}
