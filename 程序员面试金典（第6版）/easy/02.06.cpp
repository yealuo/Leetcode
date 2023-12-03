#include "02.h"
#include <iostream>
#include <vector>
using namespace std;

// 散列表
bool isPalindrome_1(ListNode* head) {
    vector<int> vec;
    while (head != nullptr) {
        vec.push_back(head->val);
        head = head->next;
    }
    for (int begin = 0, end = vec.size() - 1; begin < end; ++begin, --end) {
        if (vec[begin] != vec[end]) {
            return false;
        }
    }
    return true;
}

// 找到中点
ListNode* findMidList(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// 反转链表
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 判断回文
bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
        return true;
    }
    ListNode* mid = findMidList(head);
    ListNode* latterPart = reverseList(mid->next);

    ListNode* front = head;
    ListNode* latter = latterPart;
    while (latter) {
        if (front->val != latter->val) {
            return false;
        }
        front = front->next;
        latter = latter->next;
    }
    return true;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    // 构建链表：1 -> 2 -> 3 -> 3 -> 2 -> 1
    node1->next = node2;
    node2->next = node3;
    node3->next = new ListNode(3);
    node3->next->next = new ListNode(2);
    node3->next->next->next = new ListNode(1);
    cout << isPalindrome(node1) << endl;
    return 0;
}