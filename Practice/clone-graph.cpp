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
        unordered_map<Node*, Node*> Mp;
        if(!node)return nullptr;
        
        queue<Node *>Q;
        Q.push(node);
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                Node * curr = Q.front();
                Q.pop();
                
                if(!Mp.count(curr))
                    Mp[curr] = new Node(curr->val, {});
                
                vector<Node*> adj;
                for(auto &neighbor : curr->neighbors) {
                    if(!Mp.count(neighbor)) // not visited
                    {
                        Mp[neighbor] = new Node(neighbor->val, {}); // create a new node
                        Q.push(neighbor); // push in Queue like normal BFS
                    } 
                    adj.push_back(Mp[neighbor]); // make the directed edge
                }
                Mp[curr]->neighbors = adj;
            }
        }
        return Mp[node];
    }
};