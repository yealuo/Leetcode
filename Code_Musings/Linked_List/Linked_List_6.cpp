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
    return 0;
}
