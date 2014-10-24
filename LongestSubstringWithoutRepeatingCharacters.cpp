// Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

#include <iostream>
#include <string>
#include <map>
#include <utility>

using std::string;
using std::map;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, size_t> state {};
        size_t longest = 0;
        size_t idx = 0;
        for (idx = 0; idx < s.size(); ++idx) {
            char c = s.at(idx);
            auto found = state.find(c);
            if (found == state.cend()) {
                state.insert(std::move(std::pair<char, size_t>{c, idx}));
            } else {
                //std::cout << "found: " << found->second << std::endl;
                for (auto iter = state.begin(); iter != state.end();) {
                    if (iter->second < found->second) {
                        //std::cout << "remove: " << iter->second << std::endl;
                        iter = state.erase(iter);
                    } else {
                        ++iter;
                    }
                }
                found->second = idx;
            }
            if (longest < state.size()) {
                longest = state.size();
            }
        }
        return static_cast<int>(longest);
    }
};

int main() {
    Solution s;
    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("abcad") << std::endl;
    return 0;
}
