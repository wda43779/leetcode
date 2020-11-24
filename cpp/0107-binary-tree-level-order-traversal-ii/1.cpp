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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        impl(root, 0, res);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
private:
    void impl(TreeNode *root, int level, vector<vector<int>> &res) {
        if (!root) return;
        // preorder
        if (res.size() == level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val);
        impl(root->left, level+1, res);
        impl(root->right, level+1, res);
    }
};
