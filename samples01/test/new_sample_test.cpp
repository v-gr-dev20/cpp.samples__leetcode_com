#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( new_sample, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"Hello"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: Hello, " + testing::CaseName()
		} );
}
