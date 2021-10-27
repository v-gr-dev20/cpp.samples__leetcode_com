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
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <iterator>
#include <vector>
#include <tuple>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CMedianOfTwoSortedArrays problem;

using namespace std;

class Solution {
public:
	double findMedianSortedArrays( vector<int>& v1, vector<int>& v2 );
private:
	int findMostLeftGreaterOrEqualInRange( vector<int>& v, int l, int r, double value );
	double getMedianFromRestRange( vector<int>& v, int l, int r, int lCounter, int rCounter );
	tuple<bool, double> findMedianSortedRanges( vector<int>& v1, vector<int>& v2,
		int l1, int r1, int l2, int r2 );

	static const tuple<bool, double> NoResult;
};
} // namespace

const tuple<bool, double> Solution::NoResult = make_tuple( false, .0 );

double Solution::findMedianSortedArrays( vector<int>& v1, vector<int>& v2 )
{
	assert( 0 < v1.size() || 0 < v2.size() );
	auto result = findMedianSortedRanges( v1, v2, 0, v1.size(), 0, v2.size() );
	assert( get<0>( result ) );
	return get<1>( result );
}

int Solution::findMostLeftGreaterOrEqualInRange( vector<int>& v, int l, int r, double value )
{
	const int noResult = -1;
	if( l < 0 || r <= l || static_cast<double>( v[r-1] ) < value ) {
		return noResult;
	}
	if( value <= static_cast<double>( v[l] ) ) {
		return l;
	}
	while( true ) {
		int m = l + ( r - l ) / 2;
		if( m+1 == r ) {
			return m;
		}
		if( value <= static_cast<double>( v[m] ) ) {
			r = m+1;
		} else {
			l = m;
		}
	}
}

double Solution::getMedianFromRestRange( vector<int>& v, int l, int r, int lCounter, int rCounter )
{
	assert( l < v.size() && l <= r && r <= v.size() );
	lCounter += l;
	rCounter += v.size() - r;
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
		? static_cast<double>( v[l-1] + v[l] ) / 2.
		: static_cast<double>( v[l] );
}

tuple<bool, double> Solution::findMedianSortedRanges( vector<int>& v1, vector<int>& v2,
	int l1, int r1, int l2, int r2 )
{
	assert( 0 <= l1 && 0 <= r1 && 0 <= l2 && 0 <= r2 );
	assert( l1 < v1.size() || l2 < v2.size() );
	int lCounter = l1 + l2;
	int rCounter = v1.size() - r1 + v2.size() - r2;
	int mCounter = r1 - l1 + r2 - l2;
	if( mCounter == 0 && lCounter == rCounter ) {
		if( 0 < l1 && l1 < v1.size() && 0 < l2 && l2 < v2.size() ) {
			return make_tuple( true, static_cast<double>( max( v1[l1-1], v2[l2-1] ) + min( v1[l1], v2[l2] ) ) / 2. );
		}
		if( 0 < l1 && l1 == v1.size() && 0 < l2 && l2 < v2.size() ) {
			return make_tuple( true, static_cast<double>( max( v1[l1-1], v2[l2-1] ) + v2[l2] ) / 2. );
		}
		if( 0 < l1 && l1 < v1.size() && 0 < l2 && l2 == v2.size() ) {
			return make_tuple( true, static_cast<double>( max( v1[l1-1], v2[l2-1] ) + v1[l1] ) / 2. );
		}
		if( 0 == l1 && l1 < v1.size() && 0 < l2 && l2 < v2.size() ) {
			return make_tuple( true, static_cast<double>( v2[l2-1] + min( v1[l1], v2[l2] ) ) / 2. );
		}
		if( 0 < l1 && l1 < v1.size() && 0 == l2 && l2 < v2.size() ) {
			return make_tuple( true, static_cast<double>( v1[l1-1] + min( v1[l1], v2[l2] ) ) / 2. );
		}
		if( 0 == l1 && l1 < v1.size() && 0 < l2 && l2 == v2.size() ) {
			return make_tuple( true, static_cast<double>( v2[l2-1] + v1[l1] ) / 2. );
		}
		if( 0 < l1 && l1 == v1.size() && 0 == l2 && l2 < v2.size() ) {
			return make_tuple( true, static_cast<double>( v1[l1-1] + v2[l2] ) / 2. );
		}
	}
	if( mCounter <= abs( rCounter - lCounter ) ) {
		return NoResult;
	}
	if( l1 == r1 && l2 < r2 ) {
		return make_tuple( true, getMedianFromRestRange( v2, l2, r2, l1, v1.size() - r1 ) );
	}
	if( l2 == r2 && l1 < r1 ) {
		return make_tuple( true, getMedianFromRestRange( v1, l1, r1, l2, v2.size() - r2 ) );
	}
	double leftValue = min( v1[l1], v2[l2] );
	double rightValue = max( v1[r1-1], v2[r2-1] );
	if( leftValue == rightValue ) {
		return make_tuple( true, leftValue );
	}
	double medianValue = ( leftValue + rightValue ) / 2.;
	int m1 = findMostLeftGreaterOrEqualInRange( v1, l1, r1, medianValue );
	int m2 = findMostLeftGreaterOrEqualInRange( v2, l2, r2, medianValue );
	auto result = findMedianSortedRanges( v1, v2, 0 <= m1 ? m1 : r1, 0 <= m1 ? m1 : r1, 0 <= m2 ? m2 : r2, 0 <= m2 ? m2 : r2 );
	if( get<0>( result ) ) {
		return result;
	}
	result = findMedianSortedRanges( v1, v2, l1, 0 <= m1 ? m1 : r1, l2, 0 <= m2 ? m2 : r2 );
	if( get<0>( result ) ) {
		return result;
	}
	return findMedianSortedRanges( v1, v2, 0 <= m1 ? m1 : r1, r1, 0 <= m2 ? m2 : r2, r2 );
}

LeetcodeCom_Problems::CMedianOfTwoSortedArrays::CMedianOfTwoSortedArrays()
	: CBaseSample( "leetcode_com__median_of_two_sorted_arrays" )
{
}

LeetcodeCom_Problems::CMedianOfTwoSortedArrays::~CMedianOfTwoSortedArrays()
{
}

void LeetcodeCom_Problems::CMedianOfTwoSortedArrays::Input( istream& iStream, ostream& oStream )
{
	oStream << "Input vector1: ";
	v1 = Tools::InputNumbers( iStream );
	
	oStream << "Input vector2: ";
	v2 = Tools::InputNumbers( iStream );
}

void LeetcodeCom_Problems::CMedianOfTwoSortedArrays::Run()
{
	result = Solution().findMedianSortedArrays( v1, v2 );
}

void LeetcodeCom_Problems::CMedianOfTwoSortedArrays::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	reportLines.push_back( "Result: " + to_string( result ) );
}
