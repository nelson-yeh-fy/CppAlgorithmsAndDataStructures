#include <iostream>
#include "lc_BFS.h"
#include "lc_BS.h"
#include "lc_DFS.h"
#include "lc_two_pointers.h"
#include "lc_sliding_window.h"
#include "lc_slow_fast_pointers.h"
#include "lc_merge_k_ways.h"
#include "lc_pattern_matching.h"
#include "lc_zothers.h"
#include "ds.h"

void print(ListNode* head) {
	while (head) {
		std::cout << head->val << ",";
		head = head->next;
	}
}
void ldemo_q1() {
	Solution_q1_c s;
	//vector<int> nums = { 23,5,2,1,8,12,16 };
	//int target = 7;
	//vector<int> nums = { 3, 3 };
	//int target = 6;
	//vector<int> nums = { -3,4,3,90 };
	//int target = 0;
	std::vector<int> nums = { 0, 3, -3, 4, -1 };
	int target = 0;

	std::vector<int> indices = s.twoSum(nums, target);
}
void ldemo_q3() {
	Solution_q4_a q4;
	std::vector<int> n1 = { 1,3 };
	std::vector<int> n2 = { 2,4 };
	std::cout << q4.findMedianSortedArrays(n1, n2);
}
void ldemo_q438()
{
	Solution_q438 s;
	std::string str = "cbaebabacd", p = "abc";
	str = "abab", p = "ab";
	str = "baa", p = "aa";
	std::vector<int> res = s.findAnagrams(str, p);

	for (auto in : res) {
		std::cout << in << ",";
	}
}
void ldemo_q4() {
	Solution_q4_b q4;
	std::list<int> n1 = { 1,3 };
	std::list<int> n2 = { 2,4 };
	std::cout << q4.findMedianSortedArrays(n1, n2);
}
void ldemo_q5() {
	Solution_q5_d q;
	std::string s = "babad";
	std::cout << q.longestPalindrome(s);
}
void ldemo_q6() {
	Solution_q6_b q;
	std::string s = "PAYPALISHIRING";
	//s = "cbbd";
	std::cout << q.convert(s, 3);
}
void ldemo_q7() {
	Solution_q7_b q;
	int t = 123;
	t = 2147483647;
	std::cout << "Original:" << t << ",Rev:" << q.reverse(t);
}
void ldemo_q8() {
	Solution_q8_b q;
	std::string s = "-123";
	s = "+123";
	s = "2147483646";
	std::cout << "Original:" << s << ",atoi:" << q.myAtoi(s);
}
void ldemo_q9() {
	Solution_q9_b q;
	int i = INT32_MAX;
	std::cout << "Original:" << i << ", isPalindrome?:" << q.isPalindrome(i);
}
void ldemo_q15() {
	Solution_q15_a q;
	std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	nums = { 0, 0, 0, 0 };
	std::vector<std::vector<int>> results = q.threeSum(nums);
}
void ldemo_q16() {
	Solution_q16 q;
	std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	nums = { 0, 0, 0, 0 };
	int target = 2;
	std::cout << q.threeSumClosest(nums, target);
}
void ldemo_q17() {
	Solution_q17 s;
	std::vector<std::string> words = s.letterCombinations("23");
	for (const std::string& word : words) {
		std::cout << "{" << word << "},";
	}
}
void ldemo_q18() {
	Solution_q18 s;
	int target = 0;
	std::vector<int> nums{ -2, -1, 0, 0, 1, 2 };
	nums = { -3,-2,-1,0,0,1,2,3 };

	std::vector<std::vector<int>> res;
	res = s.fourSum(nums, target);
	for (auto& it : res) {
		for (auto& it2 : it) {
			std::cout << it2 << ",";
		}
		std::cout << std::endl;
	}
}
void ldemo_q19()
{
	Solution_q19 s;
	ListNode* n5 = new ListNode(5);
	ListNode* n4 = new ListNode(4, n5);
	ListNode* n3 = new ListNode(3, n4);
	ListNode* n2 = new ListNode(2, n3);
	ListNode* n1 = new ListNode(1, n2);
	ListNode* res = s.removeNthFromEnd(n1, 6);
	print(res);
}
void ldemo_q20()
{
	Solution_q20 s;
	std::string str = "{[]()[()]}";
	std::cout << s.isValid(str);
}
void ldemo_q21()
{
	Solution_q21 s;
	ListNode* n5 = new ListNode(5);
	ListNode* n3 = new ListNode(3, n5);
	ListNode* n1 = new ListNode(1, n3);

	ListNode* n6 = new ListNode(6);
	ListNode* n4 = new ListNode(4, n6);
	ListNode* n2 = new ListNode(2, n4);

	ListNode* m = s.mergeTwoLists(n1, n2);
	while (m) {
		std::cout << m->val << ",";
		m = m->next;
	}
}
void ldemo_q22() {
	Solution_q22_b s;
	std::vector<std::string> res = s.generateParenthesis(2);
	for (auto& i : res) {
		std::cout << i << std::endl;
	}
}

void ldemo_q23()
{
	Solution_q23_b s;
	std::vector<ListNode*> input;
	ListNode* a5 = new ListNode(5);
	ListNode* a4 = new ListNode(4, a5);
	ListNode* a1 = new ListNode(1, a4);

	ListNode* b4 = new ListNode(4);
	ListNode* b3 = new ListNode(3, b4);
	ListNode* b1 = new ListNode(1, b3);

	ListNode* c6 = new ListNode(6);
	ListNode* c2 = new ListNode(2, c6);
	input.push_back(a1);
	input.push_back(b1);
	input.push_back(c2);
	ListNode* res = s.mergeKLists(input);
	while (res) {
		std::cout << res->val << ",";
		res = res->next;
	}
}
void ldemo_q24()
{
	Solution_q24 s;
	ListNode* a4 = new ListNode(4);
	ListNode* a3 = new ListNode(3, a4);
	ListNode* a2 = new ListNode(2, a3);
	ListNode* a1 = new ListNode(1, a2);

	ListNode* res = s.swapPairs(a1);
	while (res) {
		std::cout << res->val << ",";
	}
}

void ldemo_q25()
{
	Solution_q25_b s;
	ListNode* a5 = new ListNode(5);
	ListNode* a4 = new ListNode(4, a5);
	ListNode* a3 = new ListNode(3, a4);
	ListNode* a2 = new ListNode(2, a3);
	ListNode* a1 = new ListNode(1, a2);

	ListNode* res = s.reverseKGroup(a1, 5);
	while (res) {
		std::cout << res->val << ",";
		res = res->next;
	}
}
void ldemo_q28() {
	Solution_q28_b s;
	std::cout << s.strStr("hello", "ell");
	std::cout << s.strStr("ABABDABACDABABCABAB", "ABABCABAB");
}
void ldemo_q30() {
	Solution_q30 s;
	std::string str = "barfoothefoobarman";
	std::vector<std::string> words = { "foo","bar" };

	str = "wordgoodgoodgoodbestword";
	words = { "word", "good", "best", "word" };

	str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	words = { "fooo", "barr", "wing", "ding", "wing" };
	std::vector<int> res = s.findSubstring(str, words);

	for (auto& n : res) {
		std::cout << n << ",";
	}
}
void ldemo_q31() {
	Solution_q31 s;
	std::vector<int> nums{ 1 };
	s.nextPermutation(nums);
	for (auto i : nums) {
		std::cout << i << ",";
	}
}
void ldemo_q32() {
	Solution_q32_b s;
	//std::cout << s.longestValidParentheses("") << std::endl;
	std::cout << s.longestValidParentheses("()()())") << std::endl;
	//std::cout << s.longestValidParentheses("()(()") << std::endl;
}

void ldemo_q33()
{
	Solution_q33_b s;
	std::vector<int> num{ 3,4,5,0,2 };
	std::cout << s.search(num, 4);
}
void ldemo_q56() {
	Solution_q56_a q;
	std::vector<std::vector<int>> input = { {1,3},{2,6},{8,10},{15,18} };
	input = { {1,4},{4,5} };
	input = { {1, 4},{0, 2},{3, 5} };
	std::vector<std::vector<int>> res = q.merge(input);
	for (auto it = res.cbegin(); it != res.cend(); ++it) {
		std::cout << "[" << (*it)[0] << "," << (*it)[1] << "], ";
	}
}


void ldemo_q98() {
	Solution_q98_c s;
	TreeNode* n2 = new TreeNode(5, nullptr, nullptr);
	TreeNode* n3 = new TreeNode(15, nullptr, nullptr);
	TreeNode* n1 = new TreeNode(10, n2, n3);
	std::cout << s.isValidBST(n1);
	return;
}
void ldemo_q125() {
	Solution_q125 q;
	std::string s = "aabaaa";
	s = "A man, a plan, a canal: Panama";
	//s = "race a car";
	s = "...";
	std::cout << q.isPalindrome(s);
}
void ldemo_q200() {
	Solution_q200_b s;
	std::vector<std::vector<char>> grid1 = { {'1','1','1','1','0'},{'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'} };
	std::vector<std::vector<char>> grid2 = { {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
	std::cout << "islands:" << s.numIslands(grid2);
}
void ldemo_q214() {
	Solution_q214_b q;
	std::string s = "aabaaa";
	//s = "abcd";
	//s = "abbava";
	//s = "aaaa";
	std::cout << q.shortestPalindrome(s);
}
void ldemo_q305() {
	Solution_q305 s;
	std::vector<std::pair<int, int>> op1 = { {0, 0}, {0,1}, {1,1} };
	std::vector<std::pair<int, int>> op2 = { {0, 0}, {0,1}, {1,1} };
	std::vector<int> res1 = s.numIslands(3, 3, op1);
	for (auto it = res1.cbegin(); it != res1.cend(); ++it)
		std::cout << *it << ",";
}
void ldemo_q259() {
	Solution_q259_c q;
	std::vector<int> nums = { -2, 0, 1, 3 };

	int target = 2;
	std::cout << q.threeSumSmaller(nums, target);
}
void ldemo_q459() {
	Solution_q459 s;
	//std::cout << s.repeatedSubstringPattern("aba");
	//std::cout << s.repeatedSubstringPattern("abab");
	std::cout << s.repeatedSubstringPattern("abcabckabcabck");
}

void ldemo_q994() {
	Solution_q994 s;
	std::vector<std::vector<int>> oranges = { {2,1,1},{1,1,0},{0,1,1} };
	oranges = { {1,2} };
	int round = s.orangesRotting(oranges);
	std::cout << "round: " << round;
	return;
}