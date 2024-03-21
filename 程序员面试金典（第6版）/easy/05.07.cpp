#include<iostream>
#include<bitset>
using namespace std;

class Solution {
   public:
    int exchangeBits(int num) {
        bitset<31> res(num);

        for(int i=0;i<30;i+=2){
            int j=res[i];
            res[i]=res[i+1];
            res[i+1]=j;
        }

        return res.to_ulong();
    }
};

int main(){
    return 0;
}