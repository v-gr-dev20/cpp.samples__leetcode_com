#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__add_two_numbers, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"2 4 3",
			"5 6 4"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 7 0 8"
		} );
}
