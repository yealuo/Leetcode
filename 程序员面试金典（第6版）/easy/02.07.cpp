#include<iostream>
#include "02.h"
using namespace std;

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int count1=0,count2=0;
    ListNode* ptrA=headA;
    ListNode* ptrB=headB;
    while(ptrA){
        ++count1;
        ptrA=ptrA->next;
    }
    while(ptrB){
        ++count2;
        ptrB=ptrB->next;
    }
    ptrA = headA;
    ptrB = headB;
    if(count1>count2){
        for(int i=count1-count2;i>0;--i){
            ptrA=ptrA->next;
        }
    }else{
        for(int i=count2-count1;i>0;--i){
            ptrB=ptrB->next;
        }
    }
    while(ptrA!=ptrB&&ptrA!=nullptr){
        ptrA=ptrA->next;
        ptrB=ptrB->next;
    }
    return ptrA;
}

int main(){
    return 0;
}