#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution1 {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        if (head == nullptr) {
            return nullptr;
        }

        ListNode *curt = head, *temp;

        while (curt != nullptr) {
            if (curt->val == val) {
                temp->next = curt->next;
                delete curt;
                curt = temp;
            }

            temp = curt;
            curt = curt->next;
        }

        return head;
    }
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = new ListNode(0, head);
        ListNode *curt = head, *prev = temp;

        while (curt != nullptr) {
            if (curt->val == val) {
                prev->next = curt->next;
                delete curt;
                curt = prev->next;
            } else {
                prev = curt;
                curt = curt->next;
            }
        }

        return temp->next;
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
