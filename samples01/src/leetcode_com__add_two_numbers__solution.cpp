// 2. Add Two Numbers
// Medium
// https://leetcode.com/problems/add-two-numbers/
// You are given two non - empty linked lists representing two non - negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output : 7 -> 0 -> 8
// Explanation : 342 + 465 = 807.
// 
// Example 2:
// Input: l1 = [0], l2 = [0]
// Output : [0]
// 
// Example 3 :
// Input : l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
// Output : [8, 9, 9, 9, 0, 0, 0, 1]
// 
// Constraints :
// The number of nodes in each linked list is in the range[1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

#include "pch.h"
#include "leetcode_com__add_two_numbers.h"

using ListNode = LeetcodeCom_Problems::CAddTwoNumbers::ListNode;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 );
};

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
} // namespace

void ListNode::clean( ListNode*& first ) {
	while( first != nullptr ) {
		auto node = first;
		first = first->next;
		delete node;
	}
}

void LeetcodeCom_Problems::CAddTwoNumbers::Run()
{
	result = Solution().addTwoNumbers( l1, l2 );
}
