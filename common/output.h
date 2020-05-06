#pragma once

#include "nullostream.h"
#include "testcout.h"
#include <iostream>
#include <memory>

inline std::shared_ptr<std::ostream> GetOutputStream()
{
#if ! defined _DEBUG && defined NDEBUG
	static
	std::shared_ptr<std::ostream> null {
		new MyTools::nullostream()
	};
	return null;
#else
	return std::shared_ptr<std::ostream>( new MyTest::CTestCout( std::move( std::cout ) ) );
#endif
}
