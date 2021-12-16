#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__find_minimum_in_rotated_sorted_array_ii, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 3 5"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 1"
		} );
}

TEST( leetcode_com__find_minimum_in_rotated_sorted_array_ii, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"2 2 2 0 1"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 0"
		} );
}

TEST( leetcode_com__find_minimum_in_rotated_sorted_array_ii, EXPECT_EQ03 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"0 0 0 0 0 0 0 0 1 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 0"
		} );
}
