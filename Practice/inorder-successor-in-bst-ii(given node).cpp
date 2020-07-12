/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution
{
public:
    Node *inorderSuccessor(Node *node)
    {
        // the successor is somewhere lower in the right subtree
        if (node->right)
        {
            node = node->right;
            while (node->left)
                node = node->left;
            return node;
        }

        // Node has no right child,
        // and hence its successor is somewhere upper in the tree.
        // Go up till the node that is left child of its parent.
        // The answer is the parent.
        while (node->parent && node == node->parent->right)
            node = node->parent;
        return node->parent;
    }
};