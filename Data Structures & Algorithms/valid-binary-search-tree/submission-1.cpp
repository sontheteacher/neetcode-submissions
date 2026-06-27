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

#include <limits>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return traverse(root, LONG_MIN, LONG_MAX);
    }

    bool traverse(TreeNode* root, long l, long r){
        if (!root) {
            return true;
        }
        if (!(l < root -> val  && root -> val < r)) {
            return false;
        }
        return traverse(root -> left, l, root -> val) && 
                traverse(root -> right, root -> val, r);

    }
};
