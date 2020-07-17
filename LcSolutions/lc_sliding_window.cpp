#include <iostream>
#include "lc_sliding_window.h"
#include "ds.h"
using namespace std;

void ldemo_q28()
{
    Solution_q28_b s;
    std::cout << s.strStr("hello", "ell");
    std::cout << s.strStr("ABABDABACDABABCABAB", "ABABCABAB");
}

void ldemo_q459()
{
    Solution_q459 s;
    //std::cout << s.repeatedSubstringPattern("aba");
    //std::cout << s.repeatedSubstringPattern("abab");
    std::cout << s.repeatedSubstringPattern("abcabckabcabck");
}
