#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__median_of_two_sorted_arrays, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 3",
			"2"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2,000000"
		} );
}

TEST( leetcode_com__median_of_two_sorted_arrays, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 2",
			"3 4"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2,500000"
		} );
}

TEST( leetcode_com__median_of_two_sorted_arrays, EXPECT_EQ03 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"0 0",
			"0 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 0,000000"
		} );
}

TEST( leetcode_com__median_of_two_sorted_arrays, EXPECT_EQ04 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 2",
			"3"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2,000000"
		} );
}

TEST( leetcode_com__median_of_two_sorted_arrays, EXPECT_EQ05 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 2",
			"1 2"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 1,500000"
		} );
}

TEST( leetcode_com__median_of_two_sorted_arrays, EXPECT_EQ06 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"2",
			"1 3 4"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2,500000"
		} );
}

TEST( leetcode_com__median_of_two_sorted_arrays, EXPECT_EQ07 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1",
			"2 3 4"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2,500000"
		} );
}
