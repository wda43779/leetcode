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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return impl(preorder.data(), inorder.data(), preorder.size());
    }
private:
    TreeNode* impl(int *preorder, int *inorder, int size) {
        if (size == 0) return nullptr;
        if (size == 1) return new TreeNode(preorder[0]);

        // preorder[0] is the root node. Now find root in inorder
        int i;
        for (i = 0; i < size; i++) {
            if (inorder[i] == preorder[0]) {
                break;
            }
        }
        return new TreeNode(preorder[0], 
                             impl(preorder+1, inorder, i),
                             impl(preorder+i+1, inorder+i+1, size-i-1));
    }
};
