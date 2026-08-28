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
    Node* dfs(Node* node,unordered_map<Node*, Node*>& mp){
        vector<Node*> curr_neigh;
        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(auto it: node->neighbors){
            if(mp.find(it) != mp.end()){
                curr_neigh.push_back(mp[it]); //ye wali node uske clone ke neighbor mei dal do
            } else{
                curr_neigh.push_back(dfs(it,mp)); //dfs krke dalo neighbor mei
            }
        }

        //neighbor mei dalne k baad jod do
        clone->neighbors = curr_neigh;
        return clone;
    }
    Node* cloneGraph(Node* node ) {
        unordered_map<Node*, Node*> mp;
        if(!node) return NULL;

        if(node->neighbors.empty()) {
            Node* clone = new Node(node->val);
            return clone;
        }

        return dfs(node, mp);
    }
};
