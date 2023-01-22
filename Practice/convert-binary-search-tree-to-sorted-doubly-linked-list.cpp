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
private:
    Node *first = nullptr, *last = nullptr;

public:
    /*
    Inorder traversal, set first node only once, last everytime, if last is set then make the relations, as it acts as previous
    */
    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            if (last)
            {
                root->left = last;
                last->right = root;
            }
            else
                first = root;
            last = root;
            inorder(root->right);
        }
    }
    Node *treeToDoublyList(Node *root)
    {
        if (!root)
            return nullptr;
        inorder(root);
        first->left = last;
        last->right = first;
        return first;
    }
};