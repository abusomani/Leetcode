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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<Node *> Q;
        Q.push(root);

        while (!Q.empty())
        {
            int N = Q.size();
            vector<int> level;
            while (N--)
            {
                auto node = Q.front();
                Q.pop();
                level.push_back(node->val);

                for (auto child : node->children)
                    if (child)
                        Q.push(child);
            }
            ans.push_back(level);
        }

        return ans;
    }
};