/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution
{
public:
    Node *inorder(Node *root, vector<Node *> &V)
    {
        if (root)
        {
            inorder(root->left, V);
            V.push_back(root);
            inorder(root->right, V);
        }
        return NULL;
    }
    Node *treeToDoublyList(Node *root)
    {
        if (root == NULL)
            return root;

        vector<Node *> in;
        inorder(root, in);
        int N = in.size();
        for (int i = 1; i < N; i++)
        {
            Node *prev = in[i - 1];
            Node *curr = in[i];
            prev->right = curr;
            curr->left = prev;
        }
        in[0]->left = in[in.size() - 1];
        in[in.size() - 1]->right = in[0];

        return in[0];
    }
};