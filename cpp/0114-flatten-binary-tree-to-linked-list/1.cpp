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
    void flatten(TreeNode *root) {
        auto head = new TreeNode();
        impl(root, head);
        delete head;
    }
private:
    TreeNode *impl(TreeNode *root, TreeNode *head) {
        if (!root) return head;
        head->left = nullptr;
        head->right = root;
        
        auto right = root->right;
        return impl(right, impl(root->left, root));
    }
};
