//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

#include <iostream>
#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(const vector<int>& vs) {
        if (vs.size() == 0) {
            val = 0;
            next = nullptr;
            return;
        }
        val = vs[0];
        next = nullptr;
        auto tail = this;
        for (size_t i = 1; i < vs.size(); ++i) {
            ListNode* tmp = new ListNode(vs[i]);
            tail->next = tmp;
            tail = tmp;
        }
    }
    ~ListNode() {
        if (next != nullptr) {
            delete next;
        }
    }
};

std::ostream& operator<<(std::ostream& os, const ListNode *head) {
    auto current = head;
    while(current != nullptr) {
        os << current->val;
        current = current->next;
    }
    return os;
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return new ListNode(0);
        }
        ListNode *ret = nullptr;
        ListNode *current = ret;
        ListNode *iter1 = l1;
        ListNode *iter2 = l2;
        bool flag = false;
        do {
            int v1 = iter1 == nullptr ? 0 : iter1->val;
            int v2 = iter2 == nullptr ? 0 : iter2->val;
            int v = v1 + v2;
            if (flag) {
                ++v;
            }
            if (v > 9) {
                v -= 10;
                flag = true;
            } else {
                flag = false;
            }
            if (current == nullptr) {
                ret = new ListNode(v);
                current = ret;
            } else {
                ListNode *newNode = new ListNode(v);
                current->next = newNode;
                current = newNode;
            }
            iter1 = iter1 == nullptr ? nullptr: iter1->next;
            iter2 = iter2 == nullptr ? nullptr: iter2->next;
        } while (iter1 != nullptr || iter2 != nullptr);
        if (flag) {
            current->next = new ListNode(1);
        }
        return ret;
    }
};

int main() {
    vector<int> v1 {};
    vector<int> v2 {};
    ListNode l1(v1);
    ListNode l2(v2);
    Solution s;
    auto tmp = s.addTwoNumbers(&l1, &l2);
    std::cout << tmp << std::endl;
    delete(tmp);
    return 0;
}
