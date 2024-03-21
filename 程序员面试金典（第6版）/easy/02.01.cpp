#include <iostream>
#include<unordered_set>
#include "02.h"
using namespace std;

ListNode* removeDuplicateNodes(ListNode* head) {
    if (!head) {
        return NULL;
    }
    unordered_set<int> list;
    ListNode* curt=head;
    ListNode* next=curt->next;
    list.insert(curt->val);
    while(next){
        if(list.find(next->val)==list.end()){
            list.insert(next->val);
            curt=next;
            next=curt->next;
        }else{
            curt->next=next->next;
            delete next;
            next=curt->next;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
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
    ListNode* head=removeDuplicateNodes(node1);
    printList(head);
    return 0;
}