#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__divide_two_integers, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"-2147483648",
			"1"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: -2147483648"
		} );
}
