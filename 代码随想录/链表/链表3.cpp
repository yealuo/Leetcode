#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *prev = head, *curt = head->next;

        head->next = nullptr;

        while (curt != nullptr) {
            ListNode* next = curt->next;

            curt->next = prev;
            prev = curt;
            curt = next;
        }

        return prev;
    }
};

