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

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int mx = 1; // always one node
        for (int i = 0; i < root->children.size(); i++)
            mx = max(mx, 1 + maxDepth(root->children[i]));
        return mx;
    }
    int maxDepth1(Node *root)
    {
        if (!root)
            return 0;
        int mx = 0;
        for (int i = 0; i < root->children.size(); i++)
            mx = max(mx, maxDepth(root->children[i]));
        return mx + 1; // this node + max from levels below
    }
};