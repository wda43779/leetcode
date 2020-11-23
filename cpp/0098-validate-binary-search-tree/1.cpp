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
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, nullptr, nullptr);
    }
private:
    bool _isValidBST(TreeNode* root, int *min, int *max) {
        if (!root) return true;
        if (!ordered(min, root->val, max)) return false;
        return _isValidBST(root->left, min, &root->val) &&
            _isValidBST(root->right, &root->val, max);
    }
    bool ordered(int *a, int b, int *c) {
        return (!a || *a < b) && (!c || b < *c);
    }   
};
