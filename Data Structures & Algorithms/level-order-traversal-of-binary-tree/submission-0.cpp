class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int lsize = q.size();
            vector<int> level;

            for (int i = 0; i < lsize; i++) {

                TreeNode* current = q.front();
                q.pop();

                level.push_back(current->val);

                if (current->left != nullptr) {
                    q.push(current->left);
                }

                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};