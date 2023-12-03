#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void move(vector<int>& A, vector<int>& B, vector<int>& C, int n) {
        if (n == 0) {
            return;
        }

        move(A, C, B, n - 1);
        C.push_back(A.back());
        A.pop_back();
        move(B, A, C, n - 1);
    }

    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A, B, C, A.size());
    }
};

int main() {
    return 0;
}