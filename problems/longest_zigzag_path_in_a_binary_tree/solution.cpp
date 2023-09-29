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
    int longestZigZag(TreeNode* root) {
        int max_length = 0;
        dfs(root, false, 0, max_length);
        dfs(root, true, 0, max_length);
        return max_length;
    }

    void dfs(TreeNode* node, bool isRight, int length, int& max_length){
        if(!node) return;
        max_length = max(max_length, length);
        if(isRight){
            dfs(node->right,false,length+1,max_length);
            dfs(node->left, true,1,max_length);
        }
        else{
            dfs(node->left,true,length + 1,max_length);
            dfs(node->right, false,1,max_length);
        }
    }
};