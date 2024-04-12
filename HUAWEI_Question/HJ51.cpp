//
// Created by Administrator on 2024/4/12.
//
#include <iostream>

using namespace std;

struct ListNode {
    int m_nKey;
    ListNode *m_pNext;
};

int main() {
    int node_num;
    ListNode *head = (ListNode *) malloc(sizeof(ListNode)); //构建空的头节点方便后续操作
    ListNode *tail = head;  //尾指针，以便尾插法构建链表
    while (cin >> node_num) {
        for (int i = 0; i < node_num; ++i) {
            int value;
            cin >> value;
            ListNode *node = (ListNode *) malloc(sizeof(ListNode));
            node->m_nKey = value;
            node->m_pNext = nullptr;    //需要把新节点的下一个节点置为空节点，否则会出现异常
            tail->m_pNext = node;
            tail = node;
        }

        int target;
        cin >> target;
        ListNode *prev = head, *curt = prev;    //双指针法
        while (target--)
            curt = curt->m_pNext;

        if (curt == nullptr)
            return -1;

        while (curt != nullptr) {
            prev = prev->m_pNext;
            curt = curt->m_pNext;
        }

        cout << prev->m_nKey << endl;

    }
    free(head);
    return 0;
}