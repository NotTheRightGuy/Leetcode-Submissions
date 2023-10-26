class Solution
{
public:
    void solve(TreeNode *root, int level, vector<int> &result)
    {
        if (!root)
            return;
        if (level == result.size())
            result.push_back(root->val);
        if (root->right)
            solve(root->right, level + 1, result);
        if (root->left)
            solve(root->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        solve(root, 0, result);
        return result;
    }
};