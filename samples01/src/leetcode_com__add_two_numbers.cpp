#include "pch.h"
#include "leetcode_com__add_two_numbers.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CAddTwoNumbers problem;
} // namespace

LeetcodeCom_Problems::CAddTwoNumbers::CAddTwoNumbers()
	: CBaseSample( "leetcode_com__add_two_numbers" )
{
}

void LeetcodeCom_Problems::CAddTwoNumbers::Clean()
{
	ListNode::clean( result );
	ListNode::clean( l1 );
	ListNode::clean( l2 );
}

LeetcodeCom_Problems::CAddTwoNumbers::~CAddTwoNumbers()
{
	Clean();
}

void LeetcodeCom_Problems::CAddTwoNumbers::Input( std::istream& iStream, std::ostream& oStream )
{
	Clean();
	std::vector<int> v;
	oStream << "Input numbers: ";
	v = Tools::InputNumbers( iStream );
	for_each( v.rbegin(), v.rend(), [&]( const auto& item ) { l1 = new ListNode( item, l1 ); assert( 0 <= item && item < 10 ); } );
	oStream << "Input numbers: ";
	v = Tools::InputNumbers( iStream );
	for_each( v.rbegin(), v.rend(), [&]( const auto& item ) { l2 = new ListNode( item, l2 ); assert( 0 <= item && item < 10 ); } );
}

void LeetcodeCom_Problems::CAddTwoNumbers::Report(std::vector<std::string>& reportLines ) const
{
	reportLines.clear();
	std::string resultStr;
	for ( ListNode* node = result; node != nullptr; node = node->next ) {
		resultStr += ( 0 < resultStr.length() ? " " : "" ) + std::to_string( node->val );
	}
	reportLines.push_back( "Result: " + resultStr );
}
