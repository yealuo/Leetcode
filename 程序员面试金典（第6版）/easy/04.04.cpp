#include<iostream>
#include"04.h"
using namespace std;

class Solution {
   public:
    int height(TreeNode* root){
        if(root==nullptr){
            return true;
        }

        int leftResult=height(root->left);
        int rightResult=height(root->right);

        if(leftResult==-1||rightResult==-1||abs(leftResult-rightResult)>1){
            return -1;
        }

        return 1+max(leftResult,rightResult);
    }

    bool isBalanced(TreeNode* root) {
        return height(root)>=0;
    }
};

int main(){
    return 0;
}
