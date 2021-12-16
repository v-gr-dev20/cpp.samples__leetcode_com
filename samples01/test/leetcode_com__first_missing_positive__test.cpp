#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__first_missing_positive, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 1"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2"
		} );
}

TEST( leetcode_com__first_missing_positive, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 2 0" 
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 3"
		} );
}

TEST( leetcode_com__first_missing_positive, EXPECT_EQ03 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 2 3 4 5 -3 7 8 -1"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 6"
		} );
}
