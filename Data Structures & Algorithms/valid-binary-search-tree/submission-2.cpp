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
       return dfs(root, INT_MIN, INT_MAX);
    }

    bool dfs(TreeNode* node, int left, int right) {
        if (!node) return true;

        int val = node->val;
        if (!(left < val && val < right)) return false;
        bool left_res = dfs(node->left, left, val);
        bool right_res = dfs(node->right, val, right);

        return left_res && right_res;
    }
};
