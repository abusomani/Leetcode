/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        // Logic:
        //        node moves to all nodes in tree in level order fashion
        //        needle keeps sewing together next level's children

        // dummy is sentinel, keeps track of start node of next level
        Node *node = root;
        Node *dummy = new Node(0);

        // this loop is for different levels
        while (node != nullptr)
        {

            // needle is sewing next fields in current level
            // first time in a level, it is same as dummy (with null next)
            // but as soon as we get a non null child from node
            // needle threads that child into its next,
            //      --------->>  thus making that child as next of dummy
            Node *needle = dummy;

            // this loop moves node in current level
            while (node != nullptr)
            {
                if (node->left)
                {
                    needle->next = node->left;
                    needle = needle->next;
                }
                if (node->right)
                {
                    needle->next = node->right;
                    needle = needle->next;
                }

                // move node to next in same level, end up null at rightmost
                node = node->next;
            }

            // current level ended in node being null
            // take node fom sentinel's next, which is next levels start
            node = dummy->next;

            // dummy.next grabbed into node above, it has been used
            //  so make it null so next time we dont grab again,
            //   if all next lvl is null, it remains null prompting end of run
            dummy->next = nullptr;
        }

        return root;
    }
};