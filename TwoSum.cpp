/*
 *Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 *The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 *You may assume that each input would have exactly one solution.
 *
 *Input: numbers={2, 7, 11, 15}, target=9
 *Output: index1=1, index2=2
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Unit {
public:
    Unit() = default;
    ~Unit() = default;

    Unit(int _value, int _index = 0):
        value(_value),
        index(_index) {
    }

    bool operator<(const Unit& rhs) const {
        return value < rhs.value;
    }

    bool operator<(const int v) const {
        return value < v;
    }

    int operator+(const Unit& rhs) const {
        return value + rhs.value;
    }

    int operator*(const int m) const {
        return value * m;
    }

    friend std::ostream& operator<<(std::ostream& os, const Unit& unit) {
        return os << "(value: " << unit.value << " index: " << unit.index << ")";
    }

    int getIndex() const {
        return index;
    }

private:
    int value;
    int index;
};

class Solution {
public:
    Solution() = default;
    ~Solution() = default;

    vector<int> twoSum(vector<int> &numbers, int target) {
        int index = 1;
        vector<Unit> units {};
        for (const int i : numbers) {
            units.push_back(Unit(i, index++));
        }
        std::sort(units.begin(), units.end());
        //for (const Unit& u : units) {
            //std::cout << u << std::endl;
        //}
        Unit halfTarget((target+1)/2 , 0);
        auto rightIter = std::upper_bound(units.cbegin(), units.cend(), halfTarget);
        auto leftIter = rightIter - 1;
        //std::cout << *leftIter << std::endl;
        //std::cout << *rightIter << std::endl;
        if (rightIter == units.cend()) {
            --rightIter;
            leftIter = rightIter - 1;
        }
        int v = *rightIter + *leftIter;
        if (v == target) {
            int idx1 = leftIter->getIndex();
            int idx2 = rightIter->getIndex();
            if (idx1 < idx2) {
                return vector<int> {idx1, idx2};
            } else {
                return vector<int> {idx2, idx1};
            }
        }
        if (v > target) {
            --leftIter;
            --rightIter;
        } else {
            ++rightIter;
            ++leftIter;
            if (rightIter == units.cend()) {
                //std::cout <<"right not found" << std::endl;
                return vector<int> {0, 0};
            }
        }
        bool found = true;
        while(true) {
            int v = *rightIter + *leftIter;
            //std::cout << v << std::endl;
            if (v == target) {
                break;
            }
            if (v < target) {
                ++rightIter;
                if (rightIter == units.cend()) {
                    //std::cout << " right not found" << std::endl;
                    found = false;
                    break;
                }
            } else {
                if (leftIter != units.cbegin()) {
                    --leftIter;
                } else {
                    //std::cout << "left not found" << std::endl;
                    found = false;
                    break;
                }
            }
        }

        if (!found) {
            return vector<int> {0, 0};
        }
        int idx1 = leftIter->getIndex();
        int idx2 = rightIter->getIndex();
        if (idx1 < idx2) {
            return vector<int> {idx1, idx2};
        } else {
            return vector<int> {idx2, idx1};
        }
    }
private:
    
};

int main() {
    vector<int> numbers {0, 4, 3, 0};
    Solution solution;
    vector<int> results = solution.twoSum(numbers, 3);
    std::cout << results[0] << "," << results[1] << std::endl;
    return 0;
}
