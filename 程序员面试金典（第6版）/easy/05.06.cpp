#include<iostream>
#include<bitset>
using namespace std;

class Solution {
   public:
    int convertInteger(int A, int B) {
        bitset<32> res(A^B);
        
        return res.count();
    }
};

int main(){
    return 0;
}