/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* currNode, TreeNode* toFind, vector<TreeNode*> &path) {
        if (!currNode) {
            return false;
        }

        path.push_back(currNode);
        if (currNode == toFind) {
            return true;
        }
        bool leftSubTree = findPath(currNode->left, toFind, path);
        if (leftSubTree) return true;
        bool rightSubTree = findPath(currNode->right, toFind, path);
        if (rightSubTree) return true;
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> pathTilP;
        vector<TreeNode *> pathTilQ;
        findPath(root, p, pathTilP);
        findPath(root, q, pathTilQ);

        int idx = 0;
        TreeNode *lastSame;
        while (idx < min(pathTilP.size(), pathTilQ.size())) {
            if (pathTilP[idx]->val != pathTilQ[idx]->val) {
                return lastSame;
            }
            lastSame = pathTilP[idx];
            idx++;
        }
        return lastSame;
    }
};