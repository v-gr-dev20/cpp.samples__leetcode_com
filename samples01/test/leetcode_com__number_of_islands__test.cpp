#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__number_of_islands, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"0 1 1",
			"0 1 1",
			"1 0 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2"
		} );
}

TEST( leetcode_com__number_of_islands, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 1 1 1 0",
			"1 1 0 1 0",
			"1 1 0 0 0",
			"0 0 0 0 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 1"
		} );
}

TEST( leetcode_com__number_of_islands, EXPECT_EQ03 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
			"1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
			"1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0",
			"1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0",
			"1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0",
			"1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0 1 0",
			"1 0 0 0 1 0 0 0 1 0 0 0 1 0 1 0 1 0 1 0",
			"1 0 0 0 1 0 0 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 0 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0 1 1 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0",
			"1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 1"
		} );
}

TEST( leetcode_com__number_of_islands, EXPECT_EQ04 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 0"
		} );
}

TEST( leetcode_com__number_of_islands, EXPECT_EQ05 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 1"
		} );
}

TEST( leetcode_com__number_of_islands, EXPECT_EQ06 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 0 1 0 1"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 3"
		} );
}

TEST( leetcode_com__number_of_islands, EXPECT_EQ07 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 0",
			"0 1",
			"1 0",
			"0 1",
			"1 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 5"
		} );
}
