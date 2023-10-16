class Solution
{
public:
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftHeight = depth(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = depth(root->right);
        if (rightHeight == -1)
            return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return depth(root) != -1;
    }
};