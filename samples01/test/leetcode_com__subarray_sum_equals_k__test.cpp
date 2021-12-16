#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__subarray_sum_equals_k, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"0 0 0 0 0 0 0 0 0 0",
			"0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 55"
		} );
}

TEST( leetcode_com__subarray_sum_equals_k, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 1 1",
			"2"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2"
		} );
}

TEST( leetcode_com__subarray_sum_equals_k, EXPECT_EQ03 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 2 3",
			"3"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2"
		} );
}
