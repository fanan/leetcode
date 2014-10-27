//Determine whether an integer is a palindrome. Do this without extra space.

//click to show spoilers.

//Some hints:
//Could negative integers be palindromes? (ie, -1)

//If you are thinking of converting the integer to string, note the restriction of using extra space.

//You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

//There is a more generic way of solving this problem.

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = x;
        int i = 0;
        while(y > 0) {
            y/=10;
            ++i;
        }
        if (i<=1) {
            return true;
        }
        int j = i / 2;
        while(j >= 0) {
            int t1 = x / pow(j) % 10;
            int t2 = x / pow(i-1-j) % 10;
            if (t1 != t2) {
                return false;
            }
            --j;
        }
        return true;
    }

private:
    int pow(int x) {
        if (x <= 0) {
            return 1;
        }
        int i = 1;
        for(;x>0;--x,i*=10);
        return i;
    }
};

int main() {
    Solution s;
    std::cout << s.isPalindrome(1000000001) << std::endl;
    std::cout << s.isPalindrome(-101) << std::endl;
    std::cout << s.isPalindrome(1234321) << std::endl;
    std::cout << s.isPalindrome(123321) << std::endl;
    std::cout << s.isPalindrome(12) << std::endl;
    return 0;
}
