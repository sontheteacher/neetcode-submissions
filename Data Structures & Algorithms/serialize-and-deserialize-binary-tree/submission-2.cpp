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

class Codec {
public:
    const string NULL_REP = "N";
    const char SPLITTER = '#';
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res = "";
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr == nullptr) res = res + NULL_REP;
            else res = res + to_string(curr->val);
            res += SPLITTER;
            if (curr != nullptr) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       vector<string> node_vals;
       tokenize(data, node_vals);

       if (node_vals[0] == NULL_REP) return nullptr;
       
       TreeNode* root = new TreeNode(stoi(node_vals[0]));
       int num_node = node_vals.size();
       vector<TreeNode*> nodes(num_node, nullptr);
       queue<TreeNode*> q;
       q.push(root);

       int curr_id = 1; 
       while (curr_id < num_node) {
        // loop variant, curr_id start on left child
        TreeNode* curr = q.front(); q.pop();
        string left_val = node_vals[curr_id];
        if (left_val != NULL_REP) {
            curr->left = new TreeNode(stoi(left_val));
            q.push(curr->left);
        }
        curr_id++;
        string right_val = node_vals[curr_id];
        if (right_val != NULL_REP) {
            curr->right = new TreeNode(stoi(right_val));
            q.push(curr->right);
        }
        curr_id++;
       }
        return root;
    }

    void tokenize(string s, vector<string>& res) {
       stringstream ss(s);
       string token;

       while(getline(ss, token, SPLITTER)) {
        res.push_back(token);
       }
    }
};