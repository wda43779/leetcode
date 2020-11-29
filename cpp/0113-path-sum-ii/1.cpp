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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> t;
        impl(root, sum, t, res);
        
        return res;
    }
private:
    void impl(TreeNode* root, int sum, vector<int>& path, vector<vector<int>> &res) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            res.push_back(vector<int>(path));
        }
        sum -= root->val;
        impl(root->left, sum, path, res);
        impl(root->right, sum, path, res);
        path.pop_back();
    }
};
