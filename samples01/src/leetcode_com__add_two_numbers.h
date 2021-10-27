#pragma once

#include "BaseSample.h"
#include <iostream>
#include <vector>
#include <string>

namespace LeetcodeCom_Problems {

class CAddTwoNumbers : public CBaseSample {
public:
	CAddTwoNumbers();
	virtual void Input( std::istream&, std::ostream& ) override;
	virtual void Run() override;
	virtual void Report( std::vector<std::string>& reportLines ) const override;
	virtual ~CAddTwoNumbers() override;
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val( 0 ), next( nullptr ) {}
		ListNode( int x) : val( x ), next( nullptr ) {}
		ListNode( int x, ListNode* next ) : val( x ), next( next ) {}
		static void clean( ListNode*& first );
	};
private:
	ListNode *l1 = nullptr, *l2 = nullptr, *result = nullptr;
	virtual void Clean() override;
};
} // namespace LeetcodeCom_Problems
