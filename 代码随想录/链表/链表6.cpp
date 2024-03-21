#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *fast = head, *slow = head;

        while (fast != nullptr) {
            if (fast->next == nullptr) {
                return nullptr;
            }

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                break;
            }
        }

        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        slow = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main() {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    Solution test;

    cout << test.detectCycle(n1)->val;

    return 0;
}