#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for (int i = 0; i < n; ++i) {
            A[m + i] = B[i];
        }
        sort(A.begin(), A.end());
    }
};

int main() {
    return 0;
}