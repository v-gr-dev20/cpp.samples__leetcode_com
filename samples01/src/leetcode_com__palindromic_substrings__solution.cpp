// 647. Palindromic Substrings
// Medium
// https://leetcode.com/problems/palindromic-substrings/
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.
//
// Example 1:
// Input: s = "abc"
// Output : 3
// Explanation : Three palindromic strings : "a", "b", "c".
//
// Example 2 :
// 	Input : s = "aaa"
// 	Output : 6
// 	Explanation : Six palindromic strings : "a", "a", "a", "aa", "aa", "aaa".
//
// 	Constraints :
// 	1 <= s.length <= 1000
// 	s consists of lowercase English letters.

#include "pch.h"
#include "leetcode_com__palindromic_substrings.h"
#include <string>
#include <vector>

using namespace std;

namespace {
// Solution public: as on the leetcode.com
class Solution {
public:
	int countSubstrings(string s);
};

int Solution::countSubstrings(string s)
{
	int count = s.size();
	vector<int> storage(s.size() - 1);
	auto centersQueueEnd = begin(storage);
	for (int i = 1; i < s.size() - 1; ++i) {
		if (s[i-1] == s[i+1]) {
			*centersQueueEnd = i;
			++centersQueueEnd;
		}
	}
	count += centersQueueEnd - begin(storage);
	for (int palindromHalfSize = 2; centersQueueEnd != begin(storage); palindromHalfSize += 1) {
		auto nextQueueEnd = begin(storage);
		for (auto current = begin(storage); current != centersQueueEnd; ++current) {
			if (palindromHalfSize <= *current
				&& palindromHalfSize <= s.size() - 1 - *current
				&& s[*current - palindromHalfSize] == s[*current + palindromHalfSize])
			{
				*nextQueueEnd = *current;
				++nextQueueEnd;
			}
		}
		centersQueueEnd = nextQueueEnd;
		count += centersQueueEnd - begin(storage);
	}
	centersQueueEnd = begin(storage);
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] == s[i + 1]) {
			*centersQueueEnd = i;
			++centersQueueEnd;
		}
	}
	count += centersQueueEnd - begin(storage);
	for (int palindromHalfSize = 2; centersQueueEnd != begin(storage); palindromHalfSize += 1) {
		auto nextQueueEnd = begin(storage);
		for (auto current = begin(storage); current != centersQueueEnd; ++current) {
			if (palindromHalfSize <= *current + 1
				&& palindromHalfSize <= s.size() - 1 - *current
				&& s[*current + 1 - palindromHalfSize] == s[*current + palindromHalfSize])
			{
				*nextQueueEnd = *current;
				++nextQueueEnd;
			}
		}
		centersQueueEnd = nextQueueEnd;
		count += centersQueueEnd - begin(storage);
	}
	return count;
}
} // namespace

void LeetcodeCom_Problems::CPalindromicSubstrings::Run()
{
	result = Solution().countSubstrings(s);
}
