#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__distinct_subsequences, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"rabbbit",
			"rabbit"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 3"
		} );
}

TEST( leetcode_com__distinct_subsequences, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"babgbag",
			"bag"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 5"
		} );
}

TEST( leetcode_com__distinct_subsequences, EXPECT_EQ03 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc"
			"bcddceeeebecbc"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 0"
		} );
}

TEST( leetcode_com__distinct_subsequences, EXPECT_EQ04 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"abc",
			"abc"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 1"
		} );
}

TEST( leetcode_com__distinct_subsequences, EXPECT_EQ05 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"aaabbaaaabbbaaaaba",
			"abba"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 249"
		} );
}

TEST( leetcode_com__distinct_subsequences, EXPECT_EQ06 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"aabcd",
			"abcd"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 2"
		} );
}

TEST( leetcode_com__distinct_subsequences, EXPECT_EQ07 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"aaa",
			"a"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 3"
		} );
}
