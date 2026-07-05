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
       unordered_map<Node*, Node*> clones;
       clones[node] = new Node(node->val);
       queue<Node*> q;
       q.push(node);

       while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        for (Node* nei : curr->neighbors) {
            if (clones.find(nei) == clones.end()) {
                clones[nei] = new Node(nei->val);
                q.push(nei);
            }
            clones[curr]->neighbors.push_back(clones[nei]);
        }
       } 
        return clones[node];
    }
};
