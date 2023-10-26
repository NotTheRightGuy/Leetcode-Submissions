class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> currentLevel;
        stack<TreeNode *> nextLevel;
        bool ltr = true;
        currentLevel.push(root);
        vector<vector<int>> ans;

        while (!currentLevel.empty())
        {
            vector<int> currAns;
            while (!currentLevel.empty())
            {
                TreeNode *curr = currentLevel.top();
                currentLevel.pop();
                currAns.push_back(curr->val);
                if (ltr)
                {
                    if (curr->left)
                        nextLevel.push(curr->left);
                    if (curr->right)
                        nextLevel.push(curr->right);
                }
                else
                {
                    if (curr->right)
                        nextLevel.push(curr->right);
                    if (curr->left)
                        nextLevel.push(curr->left);
                }
            }
            ans.push_back(currAns);
            currentLevel = nextLevel;
            nextLevel = stack<TreeNode *>();
            ltr = !ltr;
        }
        return ans;
    }
};