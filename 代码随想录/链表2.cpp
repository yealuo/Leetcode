#include <iostream>
using namespace std;

class MyLinkedList {
   private:
    int val;
    MyLinkedList* next;
    MyLinkedList* curt = next;

   public:
    MyLinkedList() : next(nullptr) {}
    MyLinkedList(int v) : val(v), next(nullptr) {}

    int getSize() {
        int count = 0;

        while (curt != nullptr) {
            ++count;
            curt = curt->next;
        }

        curt = next;

        return count;
    }

    int get(int index) {
        if (index < 0 || index > getSize() - 1) {
            return -1;
        }

        for (int i = 0; i < index; ++i) {
            curt = curt->next;
        }

        MyLinkedList* temp = curt;

        curt = next;

        return temp->val;
    }

    void addAtHead(int val) {
        MyLinkedList* temp = new MyLinkedList(val);

        next = temp;
        temp->next = curt;
        curt = temp;
    }

    void addAtTail(int val) {
        if (curt == nullptr) {
            MyLinkedList* temp = new MyLinkedList(val);

            next = temp;
            curt = temp;
        } else {
            while (curt->next != nullptr) {
                curt = curt->next;
            }

            MyLinkedList* temp = new MyLinkedList(val);

            curt->next = temp;
            curt = next;
        }
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > getSize()) {
            return;
        } else if (index == getSize()) {
            addAtTail(val);
        } else if (index == 0) {
            addAtHead(val);
        } else {
            for (int i = 0; i < index - 1; ++i) {
                curt = curt->next;
            }

            MyLinkedList* temp = new MyLinkedList(val);
            MyLinkedList* temp2 = curt->next;

            curt->next = temp;
            temp->next = temp2;
            curt = next;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index > getSize() - 1) {
            return;
        } else if (index == 0) {
            next = curt->next;
            delete curt;
            curt = next;
        } else {
            for (int i = 0; i < index - 1; ++i) {
                curt = curt->next;
            }

            MyLinkedList* temp = curt->next;

            curt->next = temp->next;
            delete temp;
            curt = next;
        }
    }
};

int main() {
    return 0;
}