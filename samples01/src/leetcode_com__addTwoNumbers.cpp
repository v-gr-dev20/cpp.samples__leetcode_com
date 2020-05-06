//You are given two non - empty linked lists representing two non - negative integers.
//	The digits are stored in reverse order and each of their nodes contain a single digit.
//	Add the two numbers and return it as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//Example:
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output : 7 -> 0 -> 8
//Explanation : 342 + 465 = 807.
// https://leetcode.com/problems/add-two-numbers/

#include "pch.h"
#include "leetcode_com__addTwoNumbers.h"
#include "tools.h"
#include "myAssert.h"
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>

namespace {
LeetcodeCom_Problems::CAddTwoNumbers problem;

using namespace std;
using ListNode = LeetcodeCom_Problems::CAddTwoNumbers::ListNode;

class Solution {
public:
	ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 );
};
} // namespace

ListNode* Solution::addTwoNumbers( ListNode* l1, ListNode* l2 )
{
	auto rFirst = new ListNode();
	auto current = rFirst;
	while( true ) {
		if( l1 != nullptr ) {
			current->val += l1->val;
			l1 = l1->next;
		}
		if( l2 != nullptr ) {
			current->val += l2->val;
			l2 = l2->next;
		}
		if( l1 == nullptr && l2 == nullptr && current->val < 10 ) {
			return rFirst;
		}
		current->next = new ListNode( current->val / 10 );
		current->val %= 10;
		current = current->next;
	}
}

void LeetcodeCom_Problems::CAddTwoNumbers::ListNode::clean( ListNode*& first ) {
	while( first != nullptr ) {
		auto node = first;
		first = first->next;
		delete node;
	}
}

LeetcodeCom_Problems::CAddTwoNumbers::CAddTwoNumbers()
	: CBaseSample( "leetcode_com__addTwoNumbers" )
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

void LeetcodeCom_Problems::CAddTwoNumbers::Input( istream& iStream, ostream& oStream )
{
	Clean();
	vector<int> v;
	oStream << "Input numbers: ";
	v = Tools::InputNumbers( iStream );
	for_each( v.rbegin(), v.rend(), [&]( const auto& item ) { l1 = new ListNode( item, l1 ); assert( 0 <= item && item < 10 ); } );
	oStream << "Input numbers: ";
	v = Tools::InputNumbers( iStream );
	for_each( v.rbegin(), v.rend(), [&]( const auto& item ) { l2 = new ListNode( item, l2 ); assert( 0 <= item && item < 10 ); } );
}

void LeetcodeCom_Problems::CAddTwoNumbers::Run()
{
	result = Solution().addTwoNumbers( l1, l2 );
}

void LeetcodeCom_Problems::CAddTwoNumbers::Report( vector<string>& reportLines ) const
{
	reportLines.clear();
	string resultStr;
	for ( ListNode* node = result; node != nullptr; node = node->next ) {
		resultStr += ( 0 < resultStr.length() ? " " : "" ) + to_string( node->val );
	}
	reportLines.push_back( "Result: " + resultStr );
}
