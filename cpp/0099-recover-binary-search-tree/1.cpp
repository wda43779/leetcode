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
    void recoverTree(TreeNode* root) {
        a = nullptr;
        b = nullptr;
        prev = nullptr;
        findSwapped(root);
        
        // swap back
        auto t = *a;
        *a = *b;
        *b = t;
    }
private:
    // use attributes instead of parameters
    int *a = nullptr;
    int *b = nullptr;
    int *prev = nullptr;
    
    void findSwapped(TreeNode* root) {
        if (!root) return;
        findSwapped(root->left);
        // in-order travese
        if (prev && *prev > root->val) {
            // bst's travere should be sorted
            // there will be only two swapped item not in order
            if (a == nullptr) {
                a = prev;
                // maybe two adjacent item swapped, there won't be second match
                b = &root->val;
            }
            else {
                b = &root->val;
            }
        }
        prev = &root->val;
        findSwapped(root->right);
    }
};
