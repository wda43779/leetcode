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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return impl(1, n);
    }
private:
    vector<TreeNode*> impl(int l, int r) {
        vector<TreeNode*> res;
        
        if (l > r) {
            res.push_back(nullptr);
        } else if (l == r) {
            res.push_back(new TreeNode(l));
        } else {
            for (int i = l; i <= r; i++) {
                auto leftTrees = impl(l, i-1);
                auto rightTrees = impl(i+1, r);
                for (auto &left : leftTrees) {
                    for (auto &right : rightTrees) {
                        auto root = new TreeNode(i, left, right);
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
