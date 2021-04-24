/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        vector<int> V;
        V.push_back(root->val);
        for(auto c: root->children) {
            vector<int> T = preorder(c);
            for(auto i: T)
                V.push_back(i);
        }
        return V;
    }
};