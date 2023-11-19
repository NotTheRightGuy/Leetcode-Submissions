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
    void height(TreeNode* root, int &dep, bool left) {
	if (!root) return;
	dep++;
	if (left)
		height(root->left, dep, true);
	else
		height(root->right, dep, false);
}

int countNodes(TreeNode *root) {
	int left = 0;
	int right = 0;
	height(root, left, true);
	height(root, right, false);

	if (left == right) {
		return (int)(pow(2, left) - 1);
	}
	else {
		int leftSubTree = countNodes(root->left);
		int rightSubTree = countNodes(root->right);
		return leftSubTree + rightSubTree + 1;
	}
}
};