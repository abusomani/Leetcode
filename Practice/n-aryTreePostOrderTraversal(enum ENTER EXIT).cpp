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
private:
    enum
    {
        ENTER,
        EXIT
    };

public:
    vector<int> postorder(Node *root)
    {
        vector<int> ans;
        stack<pair<int, Node *>> St;
        St.push({ENTER, root});

        while (!St.empty())
        {
            pair<int, Node *> P = St.top();
            St.pop();

            if (P.second == nullptr)
                continue;

            if (P.first == EXIT)
                ans.push_back(P.second->val);
            else
            {
                St.push({EXIT, P.second});
                for (int i = P.second->children.size() - 1; i >= 0; i--)
                    if (P.second->children[i])
                        St.push({ENTER, P.second->children[i]});
            }
        }

        return ans;
    }
};