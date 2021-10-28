// 4. Median of Two Sorted Arrays
// Hard
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
//
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3) / 2 = 2.5
//
// Example 3:
// Input: nums1 = [0, 0], nums2 = [0, 0]
// Output : 0.00000
//
// Example 4 :
// 	Input : nums1 = [], nums2 = [1]
// 	Output : 1.00000
//
// 	Example 5 :
// 	Input : nums1 = [2], nums2 = []
// 	Output : 2.00000
//
// 	Constraints :
// 	nums1.length == m
// 	nums2.length == n
// 	0 <= m <= 1000
// 	0 <= n <= 1000
// 	1 <= m + n <= 2000
// 	- 10^6 <= nums1[i], nums2[i] <= 10^6

#include "pch.h"
#include "leetcode_com__median_of_two_sorted_arrays.h"
#include "myAssert.h"
#include <vector>
#include <tuple>

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	double findMedianSortedArrays( vector<int>& nums1, vector<int>& nums2 );
private:
	int findMostLeftGreaterOrEqualInRange( vector<int>& nums, int l, int r, double value );
	double getMedianFromRestRange( vector<int>& nums, int l, int r, int lCounter, int rCounter );
	tuple<bool, double> findMedianSortedRanges( vector<int>& nums1, vector<int>& nums2,
		int l1, int r1, int l2, int r2 );

	static const tuple<bool, double> NoResult;
};

const tuple<bool, double> Solution::NoResult = make_tuple( false, .0 );

double Solution::findMedianSortedArrays( vector<int>& nums1, vector<int>& nums2 )
{
	assert( 0 < nums1.size() || 0 < nums2.size() );
	auto result = findMedianSortedRanges( nums1, nums2, 0, nums1.size(), 0, nums2.size() );
	assert( get<0>( result ) );
	return get<1>( result );
}

int Solution::findMostLeftGreaterOrEqualInRange( vector<int>& nums, int l, int r, double value )
{
	const int noResult = -1;
	if( l < 0 || r <= l || static_cast<double>( nums[r-1] ) < value ) {
		return noResult;
	}
	if( value <= static_cast<double>( nums[l] ) ) {
		return l;
	}
	while( true ) {
		int m = l + ( r - l ) / 2;
		if( m+1 == r ) {
			return m;
		}
		if( value <= static_cast<double>( nums[m] ) ) {
			r = m+1;
		} else {
			l = m;
		}
	}
}

double Solution::getMedianFromRestRange( vector<int>& nums, int l, int r, int lCounter, int rCounter )
{
	assert( l < nums.size() && l <= r && r <= nums.size() );
	lCounter += l;
	rCounter += nums.size() - r;
	assert( abs( rCounter - lCounter ) < r - l );
	if( lCounter < rCounter ) {
		l += rCounter - lCounter;
		lCounter = rCounter;
	} else {
		r -= lCounter - rCounter;
		rCounter = lCounter;
	}
	int half = ( r - l ) / 2;
	lCounter += half;
	rCounter -= half;
	l += half;
	r -= half;
	return l == r
		? static_cast<double>( nums[l-1] + nums[l] ) / 2.
		: static_cast<double>( nums[l] );
}

tuple<bool, double> Solution::findMedianSortedRanges( vector<int>& nums1, vector<int>& nums2,
	int l1, int r1, int l2, int r2 )
{
	assert( 0 <= l1 && 0 <= r1 && 0 <= l2 && 0 <= r2 );
	assert( l1 < nums1.size() || l2 < nums2.size() );
	int lCounter = l1 + l2;
	int rCounter = nums1.size() - r1 + nums2.size() - r2;
	int mCounter = r1 - l1 + r2 - l2;
	if( mCounter == 0 && lCounter == rCounter ) {
		if( 0 < l1 && l1 < nums1.size() && 0 < l2 && l2 < nums2.size() ) {
			return make_tuple( true, static_cast<double>( max( nums1[l1-1], nums2[l2-1] ) + min( nums1[l1], nums2[l2] ) ) / 2. );
		}
		if( 0 < l1 && l1 == nums1.size() && 0 < l2 && l2 < nums2.size() ) {
			return make_tuple( true, static_cast<double>( max( nums1[l1-1], nums2[l2-1] ) + nums2[l2] ) / 2. );
		}
		if( 0 < l1 && l1 < nums1.size() && 0 < l2 && l2 == nums2.size() ) {
			return make_tuple( true, static_cast<double>( max( nums1[l1-1], nums2[l2-1] ) + nums1[l1] ) / 2. );
		}
		if( 0 == l1 && l1 < nums1.size() && 0 < l2 && l2 < nums2.size() ) {
			return make_tuple( true, static_cast<double>( nums2[l2-1] + min( nums1[l1], nums2[l2] ) ) / 2. );
		}
		if( 0 < l1 && l1 < nums1.size() && 0 == l2 && l2 < nums2.size() ) {
			return make_tuple( true, static_cast<double>( nums1[l1-1] + min( nums1[l1], nums2[l2] ) ) / 2. );
		}
		if( 0 == l1 && l1 < nums1.size() && 0 < l2 && l2 == nums2.size() ) {
			return make_tuple( true, static_cast<double>( nums2[l2-1] + nums1[l1] ) / 2. );
		}
		if( 0 < l1 && l1 == nums1.size() && 0 == l2 && l2 < nums2.size() ) {
			return make_tuple( true, static_cast<double>( nums1[l1-1] + nums2[l2] ) / 2. );
		}
	}
	if( mCounter <= abs( rCounter - lCounter ) ) {
		return NoResult;
	}
	if( l1 == r1 && l2 < r2 ) {
		return make_tuple( true, getMedianFromRestRange( nums2, l2, r2, l1, nums1.size() - r1 ) );
	}
	if( l2 == r2 && l1 < r1 ) {
		return make_tuple( true, getMedianFromRestRange( nums1, l1, r1, l2, nums2.size() - r2 ) );
	}
	double leftValue = min( nums1[l1], nums2[l2] );
	double rightValue = max( nums1[r1-1], nums2[r2-1] );
	if( leftValue == rightValue ) {
		return make_tuple( true, leftValue );
	}
	double medianValue = ( leftValue + rightValue ) / 2.;
	int m1 = findMostLeftGreaterOrEqualInRange( nums1, l1, r1, medianValue );
	int m2 = findMostLeftGreaterOrEqualInRange( nums2, l2, r2, medianValue );
	auto result = findMedianSortedRanges( nums1, nums2, 0 <= m1 ? m1 : r1, 0 <= m1 ? m1 : r1, 0 <= m2 ? m2 : r2, 0 <= m2 ? m2 : r2 );
	if( get<0>( result ) ) {
		return result;
	}
	result = findMedianSortedRanges( nums1, nums2, l1, 0 <= m1 ? m1 : r1, l2, 0 <= m2 ? m2 : r2 );
	if( get<0>( result ) ) {
		return result;
	}
	return findMedianSortedRanges( nums1, nums2, 0 <= m1 ? m1 : r1, r1, 0 <= m2 ? m2 : r2, r2 );
}
} // namespace

void LeetcodeCom_Problems::CMedianOfTwoSortedArrays::Run()
{
	result = Solution().findMedianSortedArrays( nums1, nums2 );
}
