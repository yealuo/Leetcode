#include "02.h"
#include <iostream>
using namespace std;

int kthToLast_1(ListNode* head, int k) {
    int count = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        ++count;
        temp = temp->next;
    }
    delete temp;
    count -= k;
    for (; count != 0; --count) {
        head = head->next;
    }
    return head->val;
}

int kthToLast(ListNode* head, int k) {
    ListNode* curt = head;
    ListNode* next = head;
    for (int i = 0; i < k; ++i) {
        next = next->next;
    }
    while (next != nullptr) {
        curt = curt->next;
        next = next->next;
    }
    return curt->val;
}