#include "pch.h"
#include "BaseSample.h"
#include "test.h"
#include <gtest/gtest.h>
#include <string>

TEST( leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination, EXPECT_EQ01 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1",
			"0 0 0",
			"1 1 0",
			"0 0 0",
			"0 1 1",
			"0 0 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 6"
		} );
}

TEST( leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination, EXPECT_EQ02 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"1",
			"0 1 1",
			"1 1 1",
			"1 0 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: -1"
		} );
}

TEST( leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination, EXPECT_EQ03 ) {
	const auto report {
		::Run( GetSample( testing::CaseName() ), {
			"4",
			"0 1 1 1 1 1 1 1 1 1 1",
			"0 0 0 0 0 0 0 0 0 0 0",
			"1 1 1 1 1 1 1 1 1 1 1",
			"0 0 0 0 0 0 0 0 0 0 0",
			"1 1 1 1 1 1 1 1 1 1 1",
			"0 0 0 0 0 0 0 0 0 0 0",
			"1 1 1 1 1 1 1 1 1 1 1",
			"0 0 0 0 0 0 0 0 0 0 0",
			"1 1 1 1 1 1 1 1 1 1 1",
			"0 0 0 0 0 0 0 0 0 0 0"
			} )
	};
	EXPECT_EQ( report, decltype( report ) {
		"Result: 19"
		} );
}
