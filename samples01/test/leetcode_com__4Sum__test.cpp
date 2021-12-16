#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__4Sum, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 0 -1 0 -2 2",
			"0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: [ [ -2 -1 1 2 ] [ -2 0 0 2 ] [ -1 0 0 1 ] ]"
	} );
}

TEST( leetcode_com__4Sum, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2",
			"8"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: [ [ 2 2 2 2 ] ]"
		} );
}
