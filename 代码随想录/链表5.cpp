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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *fast = dummyHead, *slow = dummyHead;

        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return dummyHead->next;
    }
};

int main() {
    return 0;
}