//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:

//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        if (nRows < 1) {
            return "";
        }
        size_t rows = static_cast<size_t>(nRows);
        vector<string> vs(rows);
        size_t row = 0;
        bool flag = true;
        for (const char c  : s) {
            vs[row] += c;
            if (flag) {
                if (row == rows - 1) {
                    row = rows - 2;
                    flag = false;
                } else {
                    ++row;
                }
            } else {
                if (row == 0) {
                    row = 1;
                    flag = true;
                } else {
                    --row;
                }
            }
        }
        string t;
        for (const string& i : vs) {
            t += i;
        }
        return t;
    }
};

int main() {
    Solution s;
    auto t = s.convert("PAYPALISHIRING", 3);
    if (t != "PAHNAPLSIIGYIR") {
        std::cout << "error" << std::endl;
    } else {
        std::cout << "ok" << std::endl;
    }
    return 0;
}
