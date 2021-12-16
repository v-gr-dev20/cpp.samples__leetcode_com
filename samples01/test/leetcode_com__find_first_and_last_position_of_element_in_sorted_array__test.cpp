#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__find_first_and_last_position_of_element_in_sorted_array, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1 2 3 3 3 3 4",
			"3" 
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: { 2, 5 }"
		} );
}
