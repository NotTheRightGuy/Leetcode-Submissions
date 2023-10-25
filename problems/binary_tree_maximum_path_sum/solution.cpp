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
    int solve(TreeNode* root, int &maxValue) {
	if (!root) return 0;
	int currentValue = root->val;
	int valueFromLeft = max(solve(root->left, maxValue), 0);
	int valueFromRight = max(solve(root->right, maxValue), 0);
	maxValue = max(maxValue, currentValue + valueFromLeft + valueFromRight);
	return max(valueFromLeft, valueFromRight) + currentValue;
}

int maxPathSum(TreeNode* root) {
	int maxValue = INT_MIN;
	solve(root, maxValue);
	return maxValue;
}
};