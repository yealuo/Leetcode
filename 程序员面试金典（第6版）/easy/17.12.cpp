#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
   public:
    TreeNode* do_convertBiNode(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        root->left = do_convertBiNode(root->left);
        root->right = do_convertBiNode(root->right);

        if (root->left == nullptr) {
            return root;
        }

        TreeNode* leftNode = root->left;
        TreeNode* left_rightmostNode = leftNode;

        while (left_rightmostNode->right != nullptr) {
            left_rightmostNode = left_rightmostNode->right;
        }

        left_rightmostNode->right = root;
        root->left = nullptr;

        return leftNode;
    }

    TreeNode* convertBiNode(TreeNode* root) { return do_convertBiNode(root); }
};

class Solution {
   private:
    TreeNode* node = new TreeNode(0);
    TreeNode* curt = node;

    void DFS(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        DFS(root->left);

        curt->right = root;
        root->left = nullptr;
        curt = root;

        DFS(root->right);
    }

   public:
    TreeNode* convertBiNode(TreeNode* root) {
        DFS(root);
        return node->right;
    }
};

int main() {
    return 0;
}