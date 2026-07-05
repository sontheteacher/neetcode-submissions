/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
      Node* res = new Node(node->val);
      unordered_map<int, Node*> clones;
      clones[node->val] = res;
      queue<Node*> q;
      q.push(node);

        // the queue keep track of all original 
        // node and while adding the neighbors
        // we create the clone and then match
        // initiate the neighbors for the clone
      while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        for (Node* nei : cur->neighbors) {
            if (clones.find(nei->val) == clones.end()) {
                clones[nei->val] = new Node(nei->val);
                q.push(nei);
            }
            clones[cur->val]->neighbors.push_back(clones[nei->val]);
        }
      }
      return res;

    }
};
