//There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::pair;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int half = (m+n) / 2;
        if ((m+n) % 2 == 0) {
            auto p = getNumber(A, m, B, n, half-1, half);
            return static_cast<double>(p.first + p.second) / 2;
        } else {
            auto p = getNumber(A, m, B, n, half, half);
            return static_cast<double>(p.first);
        }
    }
private:
    pair<int, int> getNumber(int A[], int m, int B[], int n, int idx1, int idx2) {
        if (idx1 == 0) {
            pair<int, int> p {};
            if (m == 0) {
                p.first = B[idx1];
                p.second = B[idx2];
                return p;
            }
            if (n == 0) {
                p.first = A[idx1];
                p.second = A[idx2];
                return p;
            }
            if (idx2 == idx1) {
                p.first = A[0] < B[0] ? A[0] : B[0];
                p.second = p.first;
                return p;
            }
            if (A[0] < B[0]) {
                p.first = A[0];
                if (m == 1) {
                    p.second = B[0];
                    return p;
                } else {
                    p.second = A[1] < B[0] ? A[1] : B[0];
                    return p;
                }
            } else {
                p.first = B[0];
                if (n == 1) {
                    p.second = A[0];
                    return p;
                } else {
                    p.second = A[0] < B[1] ? A[0] : B[1];
                    return p;
                }
            }
        }
        if (m == 0) {
            return pair<int, int> {B[idx1], B[idx2]};
        }
        if (n == 0) {
            return pair<int, int> {A[idx1], A[idx2]};
        }

        int cut = (idx1 + 1) / 2; // cut > 0
        if (m < cut) {
            cut = m;
        }
        if (n < cut) {
            cut = n;
        }
        if (A[cut-1] < B[cut-1]) {
            if (cut == m) {
                return getNumber(nullptr, 0, B, n, idx1 - cut, idx2 - cut);
            } else {
                return getNumber(&A[cut], m - cut, B, n, idx1 - cut, idx2 - cut);
            }
        } else {
            if (cut == n) {
                return getNumber(A, m, nullptr, 0, idx1 - cut, idx2 - cut);
            } else {
                return getNumber(A, m, &B[cut], n - cut, idx1 - cut, idx2 - cut);
            }
        }
    }
};

class Checker {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        vector<int> vs(total);
        for (int i = 0; i < m; ++i) {
            vs[i] = A[i];
        }
        for (int i = 0; i < n; ++i) {
            vs[m+i] = B[i];
        }
        sort(vs.begin(), vs.end());
        int half = total / 2;
        if (total % 2 == 0) {
            return (static_cast<double>(vs[half - 1]) + vs[half]) / 2;
        } else {
            return static_cast<double>(vs[half]);
        }
    }
};

int main() {
    Solution s;
    int A[] {1,3,5,9};
    int B[] {2,4,6,8};
    std::cout << s.findMedianSortedArrays(A, 4, B, 4) << std::endl;
    Checker c;
    std::cout << c.findMedianSortedArrays(A, 4, B, 4) << std::endl;
    return 0;
}
