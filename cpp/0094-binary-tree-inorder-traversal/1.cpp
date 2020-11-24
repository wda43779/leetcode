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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        _impl(root, res);
        return res;
    }
private:
    void _impl(TreeNode* root, vector<int> &res) {
        if (!root) return;
        _impl(root->left, res);
        res.push_back(root->val);
        _impl(root->right, res);
    }
};
