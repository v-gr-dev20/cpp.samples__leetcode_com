project(samples01-test CXX)

set(no_group_source_files
    "../../common/nullostream.h"
    "../../common/myAssert.h"
    "../../common/output.h"
    "../../common/testcout.h"
    "../../common/tools.cpp"
    "../../common/tools.h"
    "../../common/BaseSample.cpp"
    "../../common/BaseSample.h"
    "main.cpp"
    "pch.cpp"
    "pch.h"
)

set(src
    "../src/leetcode_com__4Sum.cpp"
    "../src/leetcode_com__4Sum.h"
    "../src/leetcode_com__4Sum__solution.cpp"
    "../src/leetcode_com__add_two_numbers.cpp"
    "../src/leetcode_com__add_two_numbers.h"
    "../src/leetcode_com__add_two_numbers__solution.cpp"
    "../src/leetcode_com__distinct_subsequences.cpp"
    "../src/leetcode_com__distinct_subsequences.h"
    "../src/leetcode_com__distinct_subsequences__solution.cpp"
    "../src/leetcode_com__divide_two_integers.cpp"
    "../src/leetcode_com__divide_two_integers.h"
    "../src/leetcode_com__divide_two_integers__solution.cpp"
    "../src/leetcode_com__find_first_and_last_position_of_element_in_sorted_array.cpp"
    "../src/leetcode_com__find_first_and_last_position_of_element_in_sorted_array.h"
    "../src/leetcode_com__find_first_and_last_position_of_element_in_sorted_array__solution.cpp"
    "../src/leetcode_com__find_minimum_in_rotated_sorted_array_ii.cpp"
    "../src/leetcode_com__find_minimum_in_rotated_sorted_array_ii.h"
    "../src/leetcode_com__find_minimum_in_rotated_sorted_array_ii__solution.cpp"
    "../src/leetcode_com__first_missing_positive.cpp"
    "../src/leetcode_com__first_missing_positive.h"
    "../src/leetcode_com__first_missing_positive__solution.cpp"
    "../src/leetcode_com__largest_plus_sign.cpp"
    "../src/leetcode_com__largest_plus_sign.h"
    "../src/leetcode_com__largest_plus_sign__solution.cpp"
    "../src/leetcode_com__median_of_two_sorted_arrays.cpp"
    "../src/leetcode_com__median_of_two_sorted_arrays.h"
    "../src/leetcode_com__median_of_two_sorted_arrays__solution.cpp"
    "../src/leetcode_com__number_of_islands.cpp"
    "../src/leetcode_com__number_of_islands.h"
    "../src/leetcode_com__number_of_islands__solution.cpp"
    "../src/leetcode_com__palindromic_substrings.cpp"
    "../src/leetcode_com__palindromic_substrings.h"
    "../src/leetcode_com__palindromic_substrings__solution.cpp"
    "../src/leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination.cpp"
    "../src/leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination.h"
    "../src/leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination__solution.cpp"
    "../src/leetcode_com__subarray_sum_equals_k.cpp"
    "../src/leetcode_com__subarray_sum_equals_k.h"
    "../src/leetcode_com__subarray_sum_equals_k__solution.cpp"
    "../src/new_sample.cpp"
    "../src/new_sample.h"
    "../src/new_sample_solution.cpp"
)

set(test
    "../test/leetcode_com__4Sum__test.cpp"
    "../test/leetcode_com__add_two_numbers__test.cpp"
    "../test/leetcode_com__distinct_subsequences__test.cpp"
    "../test/leetcode_com__divide_two_integers__test.cpp"
    "../test/leetcode_com__find_first_and_last_position_of_element_in_sorted_array__test.cpp"
    "../test/leetcode_com__find_minimum_in_rotated_sorted_array_ii__test.cpp"
    "../test/leetcode_com__first_missing_positive__test.cpp"
    "../test/leetcode_com__largest_plus_sign__test.cpp"
    "../test/leetcode_com__median_of_two_sorted_arrays__test.cpp"
    "../test/leetcode_com__number_of_islands__test.cpp"
    "../test/leetcode_com__palindromic_substrings__test.cpp"
    "../test/leetcode_com__shortest_path_in_a_grid_with_obstacles_elimination__test.cpp"
    "../test/leetcode_com__subarray_sum_equals_k__test.cpp"
    "../test/new_sample_test.cpp"
    "../test/test.h"
    "../test/test.cpp"
)

set(ALL_FILES
    ${no_group_source_files}
    ${src}
    ${test}
)

enable_testing()
add_executable(${PROJECT_NAME} ${ALL_FILES})
if( WIN32 )
    file(TO_CMAKE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../external" EXTERNAL)
    target_link_libraries(${PROJECT_NAME} PRIVATE "${EXTERNAL}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.5/build/native/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.targets")
    target_link_libraries(${PROJECT_NAME} PRIVATE "${EXTERNAL}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn/1.8.1.5/build/native/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.targets")
else()
    find_package(GTest REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE GTest::GTest GTest::Main)
endif()
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/..;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../test;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../common;"
)
set_target_properties(
	${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
add_precompiled_header(${PROJECT_NAME} "pch.h" "pch.cpp")

add_test( NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} --gtest_color=yes )
