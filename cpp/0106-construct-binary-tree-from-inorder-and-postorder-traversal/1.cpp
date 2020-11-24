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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return impl(inorder.data(), postorder.data(), inorder.size());
    }
private:
    TreeNode* impl(int *inorder, int *postorder, int size) {
        if (size == 0) return nullptr;
        if (size == 1) return new TreeNode(postorder[size-1]);

        // postorder[0] is the root node. Now find root in inorder
        int i;
        for (i = 0; i < size; i++) {
            if (inorder[i] == postorder[size-1]) {
                break;
            }
        }
        return new TreeNode(postorder[size-1], 
                             impl(inorder, postorder, i),
                             impl(inorder+i+1, postorder+i, size-i-1));
    }
};
