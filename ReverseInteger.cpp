//Reverse digits of an integer.

//Example1: x = 123, return 321
//Example2: x = -123, return -321

//click to show spoilers.

//Have you thought about this?
//Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

//Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

//Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).


#include <iostream>
#include <vector>

class Solution {
public:
    int reverse(int x) {
        bool positive = x > 0;
        x = x > 0 ? x : -x;
        std::vector<int> v {};
        while(x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        for (auto iter = v.cbegin(); iter != v.cend(); ++iter) {
            x = x * 10 + *iter;
        }
        return positive ? x : -x;
    }
};

int main() {
    Solution s;
    std::cout << s.reverse(321) << std::endl;
    std::cout << s.reverse(-321) << std::endl;
    std::cout << s.reverse(-10) << std::endl;
    std::cout << s.reverse(10) << std::endl;
    std::cout << s.reverse(1000000003) << std::endl;
    return 0;
}
