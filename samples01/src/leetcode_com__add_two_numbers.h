#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CAddTwoNumbers : public CBaseSample {
public:
	CAddTwoNumbers();
	virtual ~CAddTwoNumbers() override;
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual void Clean() override;
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val( 0 ), next( nullptr ) {}
		ListNode( int x ) : val( x ), next( nullptr ) {}
		ListNode( int x, ListNode* next ) : val( x ), next( next ) {}
		static void clean( ListNode*& first );
	};
private:
	// https://leetcode.com/problems/add-two-numbers/
	// You are given two non - empty linked lists representing two non - negative integers.
	// The digits are stored in reverse order and each of their nodes contain a single digit.
	// Add the two numbers and return it as a linked list.
	ListNode* l1 = nullptr, * l2 = nullptr, * result = nullptr;
};
} // namespace LeetcodeCom_Problems
