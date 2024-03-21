#include <iostream>
#include <vector>
#include"04.h"
using namespace std;

class Solution {
   public:
    TreeNode* do_sortedArrayToBST(vector<int>& nums, int left, int right) {
        if(left>right){
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = do_sortedArrayToBST(nums, left, mid - 1);
        root->right = do_sortedArrayToBST(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return do_sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};

int main(){
    return 0;
}