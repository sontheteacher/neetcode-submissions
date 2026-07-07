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
    vector<int> rightSideView(TreeNode* root) {
       vector<int> res;
       if (!root) return res;
       queue<TreeNode*> q;
       q.push(root);

       while (!q.empty()) {
        TreeNode* curr;
        int size = q.size();
        for (int _ = 0; _ < size; _++) {
            curr = q.front(); q.pop();
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        res.push_back(curr->val);
       } 
       return res;
    }
};
