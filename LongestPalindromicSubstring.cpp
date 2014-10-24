//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        size_t length = s.size();
        if (length == 0) {
            return s;
        }
        size_t start = 0;
        size_t longest = 1;
        size_t p1 = 0;
        size_t p2 = 1;
        //p2 = p1 + 1
        for (p1 = 0; p2 < length; ++p1, ++p2) {
            if (s[p1] != s[p2]) {
                continue;
            }
            size_t l = 2;
            size_t j = 0;
            while(j + 1 <= p1 && p2 + j + 1 <= length - 1 && s[p1-j-1] == s[p2+j+1]) {
                ++j;
                l += 2;
            }
            if (l > longest) {
                longest = l;
                start = p1 - j;
            }
        }
        for (p1 = 0, p2 = 2; p2 < length; ++p1, ++p2) {
            if (s[p1] != s[p2]) {
                continue;
            }
            size_t l = 3;
            size_t j = 0;
            while(j + 1 <= p1 && p2 + j + 1 <= length - 1 && s[p1-j-1] == s[p2+j+1]) {
                ++j;
                l += 2;
            }
            if (l > longest) {
                longest = l;
                start = p1 - j;
            }
        }
        return s.substr(start, longest);
    }
};

int main() {
    Solution s;
    std::cout << s.longestPalindrome("abcdefghihgfebccba") << std::endl;
    std::cout << s.longestPalindrome("ccc") << std::endl;
    std::cout << s.longestPalindrome("cc") << std::endl;
    std::cout << s.longestPalindrome("cccc") << std::endl;
    std::cout << s.longestPalindrome("abb") << std::endl;
    return 0;
}
