#include<iostream>
#include<bitset>
using namespace std;

class Solution {
   public:
    int reverseBits1(int num) {
        int max=0;

        for(int j=0;j<32;j++){
            int count = 0;
            bitset<32> res(num);

            res[j]=res[j]|1;

            for (int i = 0; i < 32; ++i) {
                if (res[i] == 1) {
                    ++count;
                    max = max > count ? max : count;
                } else {
                    count = 0;
                }
            }
        }

        return max;
    }

    int reverseBits(int num) {
        int max=0;
        int count=0;
        int index=0;    //上次遇到0的索引
        int flag=false; //之前是否遇到0
        bitset<32> res(num);

        for(int i=0;i<32;++i){
            if(res[i]==1){
                ++count;
            }else{
                if(!flag){
                    ++count;
                    index=i;
                    flag=true;
                }else{
                    max=max>count?max:count;
                    count=0;
                    i=index;
                    flag=false;
                }
            }

            max=max>count?max:count;
        }

        return max;
    }
};



int main(){
    Solution test;
    cout << test.reverseBits(2147482622) << endl;
    return 0;
}