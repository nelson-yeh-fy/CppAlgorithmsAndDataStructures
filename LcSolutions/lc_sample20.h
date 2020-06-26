#ifndef LE_SAMPLE_20_H
#define LE_SAMPLE_20_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <forward_list>
#include <queue>

// This solution changes the original vector, doesn't fit leetcode's requirement.
class Solution_q1_a {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        //n2 means the end of our searching candidates. because we put all values bigger than 'target' in the right side.
        std::size_t n2 = partition(nums, 0, nums.size() - 1, target);
        //n1 means the separate point of seaching candiate, e.g.: 9 is the target, put everything smaller than 9/2 left side, and other in the right side.
        std::size_t n1 = partition(nums, 0, n2, target / 2);

        for (std::size_t i = 0; i <= n1; ++i) {
            for (std::size_t j = n2; j >= n1; --j) {
                if (target == nums[i] + nums[j]) {
                    if (i > INT_MAX || j > INT_MAX) {
                        throw std::overflow_error("i or j is overflow");
                    }
                    return std::vector<int>{ static_cast<int>(i), static_cast<int>(j) };
                }
            }
        }
        return std::vector<int>{};
    }

    //This is similiar to Quick Sort's partitioning technique. i: start, j: end for the array
    std::size_t partition(std::vector<int>& nums, std::size_t i, std::size_t j, int privot_value) {
        while (i < j) {
            if (nums[j] > privot_value) {
                j--;
            }
            else if (nums[i] < privot_value) {
                i++;
            }
            else {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return j;
    }
};
// This solution doesn't fulfill the situation when there is negative value.
class Solution_q1_b {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> candidate1;  //for those value are smaller than target/2
        std::unordered_map<int, int> candidate2;  //for those value are smaller than target, bigger or equal to target/2

        //O(n), for special case there is nagative value, e.g.: {-3,0,3,90} target:0
        int min = 0;
        for (auto li = nums.cbegin(); li != nums.cend(); ++li) {
            if (*li < min)
                min = *li;
        }

        //O(n), filter out impossible items, 
        //and then store < target/2 into candidate1 hash table, > target/2 && < target into candidate2.
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] <= target / 2) {

                //this for special case like {3,3} => target 6
                auto find = candidate1.find(nums[i]);
                if (find != candidate1.end()) {
                    if (find->first + nums[i] == target) {
                        return std::vector<int> {find->second, static_cast<int>(i)};
                    }
                }
                candidate1.insert(std::make_pair(nums[i], i));
            }
            else if (nums[i] > target / 2 && nums[i] <= target+std::abs(min)) {

                //this for special case like {3,3} => target 6
                auto find = candidate2.find(nums[i]);
                if(find!=candidate2.end()){
                    if (find->first + nums[i] == target) {
                        return std::vector<int> {find->second, static_cast<int>(i)};
                    }
                }
                candidate2.insert(std::make_pair(nums[i], i));
            }
        }

        for (auto i1 = candidate1.cbegin(); i1 != candidate1.cend(); ++i1) {
            for (auto i2 = candidate2.cbegin(); i2 != candidate2.cend(); ++i2) {
                if (i1->first + i2->first == target) {
                    return std::vector<int> {i1->second, i2->second};
                }
            }
        }
        return std::vector<int>{};
    }
};
// This is the solution.
class Solution_q1_c {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashmap; //[KEY]: data,  [VALUE]: the index of this value
        
        for (auto it = nums.cbegin(); it != nums.cend(); ++it){

            int x = target - *it;
            auto find = hashmap.find(x);
            if (find!= hashmap.cend()) {
                return std::vector<int>{find->second, static_cast<int>(it - nums.cbegin())};
            }
            else {
                hashmap.insert(std::make_pair(*it, it - nums.cbegin()));
            }
        }
        return std::vector<int>{};
    }
};
// LeetCode optimized:
class Solution_q1_d {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashmap; //[KEY]: data,  [VALUE]: the index of this value

        //Remove the "i<nums.size()" because we assume there is always one answer 
        for (int i = 0;; ++i) {

            auto find = hashmap.find(target - nums[i]);
            if (find != hashmap.cend()) {
                return std::vector<int>{find->second, i};
            }
            else {
                hashmap.insert(std::make_pair(nums[i], i));
            }
        }
        return std::vector<int>{};
    }
};
void ldemo_q1();

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution_q2_a {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode();
        ListNode* head = result;
        int sum = 0;

        //traverse l1 and l2 at the same time, the order start from the beginging.
        while (l1 != nullptr || l2 != nullptr) {

            sum = sum / 10;
            if (l1 == nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            else if (l2 == nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            else {
                sum += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }

            ListNode* n = new ListNode(sum % 10);
            head->next = n;
            head = head->next;
        }

        if (sum / 10 > 0) {
            ListNode* n = new ListNode(sum / 10);
            head->next = n;
            head = head->next;
        }

        return result->next;
    }
};
//concise version but worse performance
class Solution_q2_b {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode(0), * ptr = result;
        int carry = 0;

        //traverse l1 and l2 at the same time, the order start from the beginging.
        while (l1 || l2 || carry != 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            ListNode* n = new ListNode(sum % 10);
            ptr->next = n;
            ptr = n;

            l1 = (l1 ? l1->next : nullptr); //check nullptr again, drag performance
            l2 = (l2 ? l2->next : nullptr);
        }
        return result->next;
    }
};

//looks correct, but somehow leetcode test "pwwkew" shows 4 (expected:3)
class Solution_q3_a {
public:
    int lengthOfLongestSubstring(std::string s) {

        std::unordered_set<char> uset;
        int maxLen = 0; //the longest substring length

        for (auto it = s.cbegin(); it != s.cend(); ++it) { //traverse characters in the string
            auto find = uset.find(*it);
            if (find != uset.cend()) { //found
                uset.erase(uset.cbegin(), ++find);
            }
            uset.insert(*it);
            maxLen = std::max(maxLen, static_cast<int>(uset.size()));
        }
        return maxLen;
    }
};
//basically the same with q3_a, but don't know why leetcode doesn't take q3_a.
class Solution_q3_b {
public:
    size_t lengthOfLongestSubstring(std::string s) {

        std::unordered_set<char> uset;
        size_t maxLen = 0; //the longest substring length
        size_t i = 0, j = 0, n = s.size(), ans = 0;

        while (i < n && j < n){
            if (uset.find(s[j]) == uset.end()) //If the character does not in the set
            {
                uset.insert(s[j++]); //Insert the character in set and update the j counter
                maxLen = std::max(maxLen, j - i); //Check if the new distance is longer than the current answer
            }
            else
            {
                uset.erase(s[i++]);
                /*If character does exist in the set, ie. it is a repeated character,
                we update the left side counter i, and continue with the checking for substring. */
            }
        }
        return maxLen;
    }
};
void ldemo_q3();

class Solution_q4_a {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

        std::vector<int> newSorted;
        auto i = nums1.cbegin(), j = nums2.cbegin();
        while (i != nums1.cend() ||  j != nums2.cend())
        {
            if (i == nums1.cend()) {
                newSorted.push_back(*(j++));
            }
            else if (j == nums2.cend()) {
                newSorted.push_back(*(i++));
            }
            else if (*i <= *j) {
                newSorted.push_back(*(i++));
            }
            else if (*j < *i) {
                newSorted.push_back(*(j++));
            }
        }

        size_t size = newSorted.size();
        double median = 0;
        if (size % 2 == 1) {
            median = newSorted[(size/2)];
        }
        else if (size % 2 == 0) {
            median = newSorted[(size/2)- 1] + newSorted[size/2];
            median /= 2;
        }

        return median;
    }
};
//if we're not allowed to use additional vector to store merged sorted array.
class Solution_q4_b {
public:
    double findMedianSortedArrays(std::list<int>& nums1, std::list<int>& nums2) {

        if (nums1.front() > nums2.front())
            return findMedianSortedArrays(nums2, nums1);

        int size = 1;
        auto i = nums1.cbegin(), j = nums2.cbegin();
        while (i != nums1.cend() || j != nums2.cend())
        {
            if (i == nums1.cend()) {
                nums1.push_back(*(j++));
            }
            else if (j == nums2.cend()) {
                //Do nothing
            }
            else if (*i <= *j) {
                i++;
            }
            else if (*j < *i) {
                nums1.insert(i++, *(j++));
            }
            size++;
        }

        double median = 0;
        if (size % 2 == 1) {
            median = findNth(nums1, (size / 2));
        }
        else if (size % 2 == 0) {
            median = findNth(nums1, (size /2)- (__int64)1) + findNth(nums1, (size / 2));
            median /= 2;
        }
        return median;
    }
    int findNth(std::list<int>& list, int n) {
        for (auto it = list.cbegin(); it != list.cend(); ++it) {
            if (n == 0) {
                return *it;
            }
            n--;
        }
        return INT_MIN;
    }
};
void ldemo_q4();
//using vector to record zigzag, but in fact simply using string* z can save memory
class Solution_q6_a {
public:
    std::string convert(std::string s, int numRows) {

        if (numRows == 1) return s;
        std::vector<std::vector<char>> zigzags = { static_cast<unsigned int>(numRows), std::vector<char>{} };
        std::string result = "";

        for (int i = 0; i < s.size(); ++i) {
            int slicer = i % (numRows * 2 - 2);
            if (slicer >= numRows) {
                slicer = numRows - 1 - (slicer % (numRows - 1));
            }
            zigzags[slicer].push_back(s[i]);
        }

        for (int j = 0; j < numRows; j++) {
            for (auto it = zigzags[j].cbegin(); it != zigzags[j].cend(); ++it) {
                std::cout << *it;
                result.push_back(*it);
            }
        }
        return result;
    }
};
class Solution_q6_b {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) return s;
        std::string* z = new std::string[numRows];
        std::string result = "";

        for (int i = 0; i < s.size(); ++i) {
            int slicer = i % (numRows * 2 - 2);
            if (slicer >= numRows) {
                slicer = numRows - 1 - (slicer % (numRows - 1));
            }
            z[slicer].push_back(s[i]);
        }

        for (int j = 0; j < numRows; j++) {
            result.append(z[j]);
        }
        return result;
    }
};
void ldemo_q6();

class Solution_q7_a {
public:
    int reverse(int x) {
        std::queue<int> rev;
        int result = 0;
        bool neg = x < 0 ? true : false;
        x = abs(x);
            
        while (x > 0) {
            rev.push(x % 10);
            x = x / 10;
        }

        int i = rev.size();
        while (i > 0) {
            result += rev.front() * pow(10, --i);
            rev.pop(); 
        }

        result = neg ? result * -1 : result;
        if (result > INT32_MAX || result < INT32_MIN) {
            return 0;
        }
        else {
            return result;
        }
    }
};

class Solution_q7_b {
public:
    int reverse(int x) {
        
        long long rev = 0;
        while (x) {
            int checkOverflow = rev;
            rev = rev * 10 + x % 10;
            if (checkOverflow != rev / 10) 
                return 0;
            x = x / 10;
        }
        return (rev > INT32_MAX || rev < INT32_MIN) ? 0 : rev;
    }
};
void ldemo_q7();

class Solution_q8_a {
public:
    int myAtoi(std::string s) {
        bool postive = true;
        long long result = 0;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == ' ') continue;  //32,space
            if (c == '+') continue;  //43, '+' detected
            if (c == '-') {          // 45, '-' detected
                if (result == 0) {  // number not started yet.
                    postive = false;
                    continue;
                }
                else {              // number started already
                    return 0;
                }
            }
            if (c < 48 || c > 57) {
                break;
            }else {
                result = result * 10 + (c - 48);
            }
        }
        result = postive ? result : result * -1;
        result = result < INT_MIN ? INT_MIN : result;
        result = result > INT_MAX ? INT_MAX : result;
        return result;
    }
};
class Solution_q8_b {
public:
    int myAtoi(std::string s) {
        int i = s.find_first_not_of(' ');
        if (s.empty() || i < 0)
            return 0;

        int sign = 1, ret = 0;
        if (s[i] == '-' || s[i] == '+') {
            sign = s[i++] == '+' ? 1 : -1;
        }

        int base = INT32_MAX / 10;  //Overflow checking base
        int ovc = INT32_MAX % 10;    //INT32 (2147483647) % 10 = 7, is the last one is bigger than 7, it will overflow

        while (isdigit(s[i])) {
            if ((ret > base) || ((ret == base) && (s[i] - '0' > ovc))) {
                return sign == 1 ? INT32_MAX : INT32_MIN;
            }
            ret = ret * 10 + (s[i++] - '0');
        }
        return ret * sign;
    }
};
void ldemo_q8();

class Solution_q9_a {
public:
    bool isPalindrome(int number) {

        int x = number;
        if (x < 0)
            return false;

        int rev = 0;
        int base = INT32_MAX/10;

        do {
            if ((rev > base) || (rev == base && x % 10 > base % 10))
                return false;

            rev = rev * 10 + x % 10;
            x = x / 10;
        } while (x != 0);

        //std::cout<< "number:" << number << "rev:" << rev << std::endl;
        return (number == rev) ? true : false;
    }
};
//This one reverse till half only, O(N/2), means it's still O(N).
class Solution_q9_b {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};
void ldemo_q9();
//56. Merge Intervals [Med]
class Solution_q56_a {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& vals) {

        if (vals.size() < 1) return {};
        //step1. sort the given internvals (by its first number)
        std::sort(vals.begin(), vals.end(),
            [](std::vector<int> a, std::vector<int> b) { return a[0] < b[0]; });

        std::vector<std::vector<int>> res;
        res.push_back(vals[0]);
        //step2. traverse all interval, use each one as a base to compare.
        for (auto it = vals.cbegin()+1; it != vals.cend(); ++it) {
            //step3. check if runner pointer's first num is within res.back()[0]. res.back()[1].
            if (res.back()[1] >= (*it)[0]) {
                res.back()[1] = std::max(res.back()[1], (*it)[1]);
            }
            else {
                res.push_back(*it);
            }
        }
        return res;
    }
};
void ldemo_q56();
#endif