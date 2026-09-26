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

    int dfs(TreeNode* root, int maxSoFar) {

        if (root == nullptr) {
            return 0;
        }

        int good = 0;

        if (root->val >= maxSoFar) {
            good = 1;
        }

        maxSoFar = max(maxSoFar, root->val);

        int leftGood = dfs(root->left, maxSoFar);
        int rightGood = dfs(root->right, maxSoFar);

        return good + leftGood + rightGood;
    }

    int goodNodes(TreeNode* root) {

        return dfs(root, root->val);
    }
};