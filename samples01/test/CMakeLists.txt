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
    "tests.cpp"
    "pch.cpp"
    "pch.h"
)

set(src
    "../src/leetcode_com__fourSum.cpp"
    "../src/leetcode_com__fourSum.h"
    "../src/leetcode_com__addTwoNumbers.cpp"
    "../src/leetcode_com__addTwoNumbers.h"
    "../src/leetcode_com__divide.cpp"
    "../src/leetcode_com__divide.h"
    "../src/leetcode_com__searchRange.cpp"
    "../src/leetcode_com__searchRange.h"
    "../src/leetcode_com__firstMissingPositive.cpp"
    "../src/leetcode_com__firstMissingPositive.h"
    "../src/leetcode_com__findMedianSortedArrays.cpp"
    "../src/leetcode_com__findMedianSortedArrays.h"
    "../src/leetcode_com__orderOfLargestPlusSign.cpp"
    "../src/leetcode_com__orderOfLargestPlusSign.h"
    "../src/leetcode_com__numDistinct.cpp"
    "../src/leetcode_com__numDistinct.h"
    "../src/leetcode_com__shortestPath.cpp"
    "../src/leetcode_com__shortestPath.h"
    "../src/leetcode_com__numIslands.cpp"
    "../src/leetcode_com__numIslands.h"
    "../src/leetcode_com__palindromic_substrings.cpp"
    "../src/leetcode_com__palindromic_substrings.h"
    "../src/leetcode_com__subarraySum.cpp"
    "../src/leetcode_com__subarraySum.h"
    "../src/leetcode_com__findMin.cpp"
    "../src/leetcode_com__findMin.h"
)

set(ALL_FILES
    ${no_group_source_files}
    ${src}
)

enable_testing()
add_executable(${PROJECT_NAME} ${ALL_FILES})
if( WIN32 )
    file(TO_CMAKE_PATH "$ENV{APPDATA}" APPDATA)
    target_link_libraries(${PROJECT_NAME} PRIVATE "${APPDATA}/NuGet/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.3/build/native/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.targets")
else()
    find_package(GTest REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE GTest::GTest GTest::Main)
endif()
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/..;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../src;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../test;"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../common;"
    "${GTEST_INCLUDE_DIRS}"
)
set_target_properties(
	${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
add_precompiled_header(${PROJECT_NAME} "pch.h" "pch.cpp")

add_test( NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} --gtest_color=yes )
