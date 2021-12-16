#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__palindromic_substrings, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"qaaaqz"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 10"
		} );
}
