/*
    Definition for a Node.
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
    unordered_map<int, Node*> _map;
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        return dfs(node);
    }

    Node* dfs(Node* node){
        Node* n = new Node(node->val);
        _map[node->val]=n; // marking the node visited

        for(auto neighbor: node->neighbors){
            auto nbor = _map.find(neighbor->val);
            if(nbor==_map.end()){
                n->neighbors.push_back(dfs(neighbor));
            }

            else{
                n->neighbors.push_back(nbor->second);
            }
        }

        return n;
    }
};
