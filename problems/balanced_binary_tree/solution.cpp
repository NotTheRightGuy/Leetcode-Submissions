/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int heightOfTree(TreeNode* root){
        if(!root) return 0;
        int leftTree = heightOfTree(root->left);
        if(leftTree == -1) return -1;
        int rightTree = heightOfTree(root->right);
        if(rightTree == -1) return -1;
        if(abs(leftTree - rightTree) > 1) return -1;
        return max(leftTree,rightTree) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return heightOfTree(root) != -1;
    }
};