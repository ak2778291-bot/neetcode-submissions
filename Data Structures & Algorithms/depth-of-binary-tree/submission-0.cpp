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
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> q;
        if (root == nullptr){
            return 0;
        }
        int maxDepth = 0;
        q.push(root); // insert the root into queue
        while (!q.empty()){
            int levelSize = q.size();
            for (int i=0; i<levelSize; i++){
                TreeNode * current = q.front();
                q.pop();
                if (current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            maxDepth++;
        }
        return maxDepth;
    }
};
