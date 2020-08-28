#ifndef LE_TWO_POINTERS_H
#define LE_TWO_POINTERS_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

//5. Longest Palindromic Substring  [Med]

//Incorrect, failed at "cc","ccc","cccc","ccccc"
class Solution_q5_a {
public:
    std::string longestPalindrome(std::string s) {

        switch (s.size()) {
        case 0: return "";
        case 1: return s;
        case 2:
            return s[0] == s[1] ? s : std::string(1, s[0]);
        }

        std::unordered_map<int, int> PRs; //Record Palindrome ranges
        int maxkey = 0, max = 0, len = 0;

        for (int R = 1; R < s.size(); ++R)
        {
            len = 0;
            if (PRs.count(R - 1) > 0) {
                int L = PRs[R - 1] - 1;
                if (L >= 0 && s[R] == s[L]) {
                    PRs[R] = L;
                    len = R - L + 1;
                }
                else if (isPalindrome(s, L + 1, R)) {
                    PRs[R] = L + 1;
                    len = R - L + 1 + 1;
                }
            }

            else if (isPalindrome(s, R - 2, R)) {
                PRs[R] = R - 2;
                len = 3;
            }
            else if (isPalindrome(s, R - 1, R)) {
                PRs[R] = R - 1;
                len = 2;
            }

            if (len >= max) {
                max = len;
                maxkey = R;
            }
        }
        return s.substr(PRs[maxkey], maxkey - PRs[maxkey] + 1);
    }

    bool isPalindrome(std::string& s, int L, int R) {
        if (L < 0) {
            return false;
        }
        while (L < R) {
            if (s[L++] != s[R--])
                return false;
        }
        return true;
    }
};
//This one find palindrome seeds first O(N), and then extend seeds to find complete palindrome O(N*N/2)
struct PalindromeRange {
    int leftIndex;
    int rightIndex;
};
class Solution_q5_b {
public:
    std::string longestPalindrome(std::string s) {

        if (s.size() < 2) return s;

        //Record Palindrome ranges [Key]:Right index, [Value]:Left index.
        std::vector<PalindromeRange> pseeds;
        int max = INT_MIN;
        std::string maxStr = "";

        //Screen and find all palindrome seeds;
        for (int i = 1; i < s.size(); ++i)
        {
            if (isPalindrome(s, i - 2, i)) { //isPalindrome(s, i-2, i)); s[i-2]==s[i]
                pseeds.push_back({ i, i - 2 });
            }
            if (isPalindrome(s, i - 1, i)) { //isPalindrome(s, i - 1, i); s[i-1]==s[i]
                pseeds.push_back({ i, i - 1 });
            }
        }

        //Screen all palindrome seeds, try to extend it and find valid palindromes.
        for (auto it = pseeds.cbegin(); it != pseeds.cend(); ++it) {

            int left = it->leftIndex;
            int right = it->rightIndex;
            while (left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            if (max < right - left + 1) {
                max = right - left + 1;
                maxStr = s.substr(left, right - left + 1);
            }
        }

        if (max == INT_MIN)
            return std::string(1, s[0]);
        else
            return maxStr;
    }
    bool isPalindrome(std::string& s, int L, int R) {
        if (L < 0) {
            return false;
        }
        while (L < R) {
            if (s[L++] != s[R--])
                return false;
        }
        return true;
    }
};
class Solution_q5_c {
public:
    std::string longestPalindrome(std::string s) {

        if (s.size() < 2) return s;
        //Record Palindrome ranges [Key]:Right index, [Value]:Left index.
        std::vector<PalindromeRange> pseeds;
        std::string maxStr = "";
        int max = INT_MIN;

        //Screen and find all palindrome seeds;
        int i = 0;
        while (i < s.size()) {
            int left = i;
            int right = i;
            while (right < s.size() - 1 && s[right] == s[right + 1]) {
                right++;
            }

            i = right + 1;
            pseeds.push_back({ left, right });
        }

        //Screen all palindrome seeds, try to extend it and find valid palindromes.
        for (auto it = pseeds.cbegin(); it != pseeds.cend(); ++it) {

            int left = it->leftIndex;
            int right = it->rightIndex;
            while (left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            if (max < right - left + 1) {
                max = right - left + 1;
                maxStr = s.substr(left, right - left + 1);
            }
        }
        return maxStr;
    }
};
class Solution_q5_d {    
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 2) return s;
        size_t i = 0, left = 0, right = 0; //runner index, left index, right index
        std::string maxStr = "";

        while (i < s.size()) {
            //step1.find palindrome seeds:
            left = i;
            right = i;
            while (right < s.size() - 1 && s[right] == s[right + 1])
                right++;
            i = right + 1;

            //step2.extend the palindrome and find its length
            while (left > 0 && right + 1 < s.size() && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }

            //step3.get the longest palindrome
            maxStr = (maxStr.size() < right - left + 1) ? s.substr(left, right - left + 1) : maxStr;
        }
        return maxStr;
    }
};
void ldemo_q5();

//============================================

//1. Two Sum [Easy]

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
            else if (nums[i] > target / 2 && nums[i] <= target + std::abs(min)) {

                //this for special case like {3,3} => target 6
                auto find = candidate2.find(nums[i]);
                if (find != candidate2.end()) {
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

        for (auto it = nums.cbegin(); it != nums.cend(); ++it) {

            int x = target - *it;
            auto find = hashmap.find(x);
            if (find != hashmap.cend()) {
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

//15. 3Sum [Med]
class Solution_q15_a {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

        if (nums.size() < 3) return {};
        //step1. assume this is sorted, if not, we sort it and takes O(NLog(N)) time.
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> hits;

        //step2. pick one number each round when we traverse the array, and make this problem reduced to 2Sum.
        for (int i = 0; i < nums.size() - 2; ++i) {
            
            //step3. bypass the same i, save time.
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                //step4. check if any 2sum combination fits the test. i(a)+b+c == 0  (0-i == b+c)
                if (0 - nums[i] < nums[left] + nums[right]) right--;
                else if (0 - nums[i] > nums[left] + nums[right]) left++;
                else {
                    hits.push_back(std::vector<int> { nums[i], nums[left], nums[right] });
                    ++left;
                    --right;
                    while (left < right && nums[left-1] == nums[left]) ++left; //avoid duplilcates
                    while (left < right && nums[right] == nums[right+1]) --right; //avoid duplicates
                }
            }
        }
        return hits;
    }
};
void ldemo_q15();

//11. Container With Most Water [Med]
class solution_q11 {
public:
    int maxArea(std::vector<int>& nums) {

        if (nums.size() <= 1) return 0;
        //step1. use two pointers (left and right), they'll be used to measure area
        int left = 0, right = nums.size() - 1, max = 0;

        //step2. traverse nums (left and right), if nums[left] < nums[right], move left toward right, vise versa
        while (left < right) {

            //step3. calculate and record the max area;
            int minHeight = std::min(nums[left], nums[right]);
            max = std::max(max, minHeight * (right - left));

            while (left < right && nums[left] <= minHeight) left++;
            while (left < right && nums[right] <= minHeight) right--;
        }

        return max;
    }
};
//16. 3Sum Closest [Med]
class Solution_q16 {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        //step1. Assume this nums is sorted, if not we take O(N*Log(N)) to sort it.
        std::sort(nums.begin(), nums.end());

        int min_diff = INT32_MAX, closest = INT32_MAX;
        //step2. Traverse the array, using index i as a fixed num for each round.
        //target - nums[i] becomes our new target, thus reduce it to 2 sum problem.
        for (size_t i = 0; i < nums.size() - 2; ++i) { //nums.size()-2 because we need a triplet

            //step3. Try to find close target, record the closest result.
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {

                int diff = target - nums[i] - nums[left] - nums[right];
                if (std::abs(min_diff) > std::abs(diff)) {
                    min_diff = diff;
                    closest = nums[i] + nums[left] + nums[right];
                }

                if (target - nums[i] < nums[left] + nums[right]) --right;
                else if (target - nums[i] > nums[left] + nums[right]) ++left;
                else {
                    //this is exactly the same, we have answer here.
                    return target;
                }
            }
        }
        return closest;
    }
};
void ldemo_q16();
//18. 4Sum [Med]
class Solution_q18 {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        //pre-req
        if (nums.size() < 4) return {};
        //step1. Sort the nums, takes O(log(N))
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        std::vector<std::vector<int>> res;
        //step2 Reduce 4Sum to 3Sum like this: a+b+c+d == target (b+c+d == target-a)
        for (int a = 0; a < n-3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            //accerlerate
            if (target < nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3]) break;
            if (target > nums[a] + nums[n - 3] + nums[n - 2] + nums[n - 1]) continue;

            //step3 Reduce 3Sum to 2Sum: c+d == target-a-b
            for (int b = a + 1; b < n-2; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                //accerlerate
                if (target < nums[a] + nums[b] + nums[a + 1] + nums[a + 2]) break;
                if (target > nums[a] + nums[b] + nums[n - 2] + nums[n - 1]) continue;

                int newTarget = target - nums[a] - nums[b];
                int c = b + 1, d = n - 1;
                while (c < d) {
                    if (newTarget > nums[c] + nums[d]) ++c;
                    else if (newTarget < nums[c] + nums[d]) --d;
                    else {
                        res.push_back({ nums[a],nums[b],nums[c],nums[d] });
                        do { ++c; } while (c<d && nums[c] == nums[c-1]);
                        do { --d; } while (c<d && nums[d] == nums[d+1]);
                    }
                }
            }
        }
        return res;
    }
};
void ldemo_q18();

//214. Shortest Palindrome [Hard]

//a starts from far right, but will take O(N*N) time worse case for "aaaaaaaa...aaa"
class Solution_q214_a { 
public:
    std::string shortestPalindrome(std::string s) {

        if (s.size() < 2) return s;

        //Step1. Find the anchor index from far right, anchor index is for adding chars in front of string.
        int anc = s.size(), r_ptr = anc;
        bool found = false;

        while (!found && anc > 0) {
            //find possible anchors
            anc--;
            int l_ptr = 0;
            while (s[anc] != s[l_ptr]) {
                anc--;
            }
            r_ptr = anc;

            //start from anchor, check if the string is a palindrome
            while (l_ptr < r_ptr && s[l_ptr] == s[r_ptr]) {
                l_ptr++;
                r_ptr--;
            }
            found = (l_ptr < r_ptr) ? false : true;
        }

        //Step2. Fill chars started from anchor index to the string end, in front of the string to make it palindrome
        std::string tmp = s.substr(anc+1, s.size()-anc);
        std::reverse(tmp.begin(), tmp.end());
        /*for (int i = s.size() - 1; i > anc; --i) {
            tmp.push_back(s[i]);
        }*/
        return tmp.append(s);
    }
};
//b starts from far left, use lc_q5_technique, this one works well (can use KMP as well)

//KMP: check this https://leetcode.com/problems/shortest-palindrome/discuss/60113/Clean-KMP-solution-with-super-detailed-explanation
class Solution_q214_b {
public:
    std::string shortestPalindrome(std::string s) {
        if (s.size() < 2) return s;
        int i = 0, left = 0, right = 0, max_ptr = 0;

        while (i <= s.size() / 2) {
            //Step1. find possible palidrome seeds first, [l_ptr<->r_ptr] is possible seeds.
            left = i;
            right = i;
            while (s[left] == s[right + 1])
                right++;
            i = right + 1;

            //Step2. extend the seed for a complete palindrome.
            while (left - 1 >= 0 && right + 1 < s.size() && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }

            //Step3. get the shortest (l_ptr==0, r_ptr is the closest to far right)
            if (left == 0 && max_ptr < right)
                max_ptr = right;
        }

        //Step4. Fill chars started from anchor index to the string end, in front of the string to make it palindrome
        std::string tmp = s.substr(max_ptr + 1, s.size() - max_ptr);
        std::reverse(tmp.begin(), tmp.end());
        return tmp.append(s);
    }
};
void ldemo_q214();
//125. Valid Palindrome [Easy]
class Solution_q125 {
public:
    bool isPalindrome(std::string s) {
        if (s.empty()) return true;

        //step1. One pointer [left] starts from 0, another one [right] starts from s.size()-1
        for(int left = 0, right = s.size() - 1; left < right; ++left, --right){
            //step2. [left] moves toward right; [right] moves towards left, ignore non alphanumeric chars
            while (left < right && isalnum(s[left]) == false) {
                left++;
            }
            while (left < right && isalnum(s[right]) == false) {
                right--;
            }
            //step3. Compare chars, return flase if encounters difference; return true at the end;
            if (toupper(s[left]) != toupper(s[right]))
                return false;

            /*while (left < s.size()-1 && (s[left] < 'A' || s[left] > 'Z') && (s[left] < 'a' || s[left] > 'z')) {
                left++;
            }
            while (right > 0 && (s[right] < 'A' || s[right] > 'Z') && (s[right] < 'a' || s[right] > 'z')) {
                right--;
            }
            int swift = 'a' - 'A';
            if (s[left] < s[right]) {
                if (s[left] + swift != s[right]) return false;
            }
            else if (s[left] > s[right]) {
                if (s[left] != s[right] + swift) return false;
            }*/
        }
        return true;
    }
};
void ldemo_q125();
//259. three Sum Smaller [Med]
class Solution_q259_a {
public:
    int threeSumSmaller(std::vector<int>& nums, int target) {
        
        int hits = 0;
        //step1. one pointer [left] starts from 0, one pointer [right] from nums.size()-1, one pointer [i] from 1 to nums.size()-2
        for (int left = 0, right = nums.size() - 1; left < right; ++left, --right) {

            //step2. move [left] towards right, next round move [right] towards left, until [left]>[right]
            for (int i = left+1; i < right; ++i) {
                if (target > nums[left] + nums[right] + nums[i]) 
                    hits++;
            }
            for (int i = left + 2; i < right; ++i) {
                if (target > nums[left+1] + nums[right] + nums[i]) 
                    hits++;
            }
            for (int i = left + 1; i < right-1; ++i) {
                if (target > nums[left] + nums[right-1] + nums[i]) 
                    hits++;
            }
        }
        return hits;
    }
};
//if the given array is sorted. then we can try below
class Solution_q259_b {
public:
    int threeSumSmaller(std::vector<int>& nums, int target) {

        std::sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1, hits = 0;
        //step1. one pointer [left] starts from 0, one pointer [right] from nums.size()-1, one pointer [i] from 1 to nums.size()-2
        while ( left < right-1 ) {
            //step2. since nums is sorted now, move [right] towards left to find candidates (and shrink the numbers we will try)
            while (target < nums[left] + nums[right]) 
                right--;

            //step3. i goes from left to right, this is more time consuming.
            int i = left + 1;
            while (i < right && target - nums[right] > nums[left] + nums[i++])
                hits++;

            right--;
        }
        return hits;
    }
};
class Solution_q259_c {
public:
    int threeSumSmaller(std::vector<int>& nums, int target) {

        std::sort(nums.begin(), nums.end());
        int hits = 0;
        //step1. one pointer [i] to find possible hits
        for (int i = 0; i < nums.size() - 2; ++i) {
            //step2. i is fixed in this run, we reduce 3sum to 2sum problem here.
            int left = i+1, right = nums.size() - 1;
            while (left < right) {
                if (target - nums[i] > nums[left] + nums[right]) {
                    hits += right - left;
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
        return hits;
    }
};
void ldemo_q259();
#endif