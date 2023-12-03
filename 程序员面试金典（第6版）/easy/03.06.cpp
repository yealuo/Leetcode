#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class AnimalShelf1 {
   private:
    queue<vector<int>> catQueue;
    queue<vector<int>> dogQueue;

   public:
    AnimalShelf1() {}

    void enqueue(vector<int> animal) {
        if (animal[1] == 0) {
            // 猫
            catQueue.push(animal);
        } else if (animal[1] == 1) {
            // 狗
            dogQueue.push(animal);
        }
    }

    vector<int> dequeueAny() {
        if (!catQueue.empty() && !dogQueue.empty()) {
            if (catQueue.front()[0] < dogQueue.front()[0]) {
                return dequeueCat();
            } else {
                return dequeueDog();
            }
        } else if (catQueue.empty()) {
            return dequeueDog();
        } else if (dogQueue.empty()) {
            return dequeueCat();
        }
        return vector<int>{-1, -1};
    }

    vector<int> dequeueDog() {
        if (dogQueue.empty()) {
            return vector<int>{-1, -1};
        }
        vector<int> temp(dogQueue.front());
        dogQueue.pop();
        return temp;
    }

    vector<int> dequeueCat() {
        if (catQueue.empty()) {
            return vector<int>{-1, -1};
        }
        vector<int> temp(catQueue.front());
        catQueue.pop();
        return temp;
    }
};

struct Node {
    int animalID;
    int animalType;
    Node* next;
    Node(int animID, int animType)
        : animalID(animID), animalType(animType), next(nullptr) {}
};

class AnimalShelf {
   private:
    Node* animalsHead;
    Node* animalsTail;

   public:
    AnimalShelf() : animalsHead(nullptr), animalsTail(nullptr) {}

    void enqueue(vector<int> animal) {
        if (animalsHead == nullptr) {
            animalsHead = new Node(animal[0], animal[1]);
            animalsTail = animalsHead;
        } else {
            Node* temp = new Node(animal[0], animal[1]);
            animalsTail->next = temp;
            animalsTail = temp;
        }
    }

    vector<int> dequeueAny() {
        if (animalsHead == nullptr) {
            return vector<int>{-1, -1};
        } else {
            Node* temp = animalsHead;
            animalsHead = animalsHead->next;
            vector<int> result{temp->animalID, temp->animalType};
            delete temp;
            return result;
        }
    }

    vector<int> dequeueDog() {
        Node* current = animalsHead;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->animalType != 1) {
                prev = current;
                current = current->next;
            } else {
                vector<int> result{current->animalID, current->animalType};
                if (prev == nullptr) {
                    animalsHead = animalsHead->next;
                } else {
                    prev->next = current->next;
                }
                Node* temp = current;
                current = current->next;
                if (animalsTail == temp) {
                    animalsTail = prev;
                }
                delete temp;
                return result;
            }
        }
        return vector<int>{-1, -1};
    }

    vector<int> dequeueCat() {
        Node* current = animalsHead;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->animalType != 0) {
                prev = current;
                current = current->next;
            } else {
                vector<int> result{current->animalID, current->animalType};
                if (prev == nullptr) {
                    animalsHead = animalsHead->next;
                } else {
                    prev->next = current->next;
                }
                Node* temp = current;
                current = current->next;
                delete temp;
                if (animalsTail == temp) {
                    animalsTail = prev;
                }
                return result;
            }
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    AnimalShelf myTest;
    myTest.enqueue({0, 0});
    myTest.enqueue({1, 0});
    myTest.dequeueCat();
    myTest.dequeueDog();
    myTest.dequeueAny();
    return 0;
}