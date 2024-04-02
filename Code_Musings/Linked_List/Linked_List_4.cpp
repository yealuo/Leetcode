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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* curt = dummyHead;
        ListNode* next = curt->next;

        while (curt->next != nullptr && curt->next->next != nullptr) {
            ListNode* nnext = next->next->next;
            curt->next = next->next;
            next->next->next = next;
            next->next = nnext;

            curt = next;
            next = curt->next;
        }

        head = dummyHead->next;
        delete dummyHead;

        return head;
    }
};

