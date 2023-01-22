/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        Node dummy = Node(0);
        Node *curr = &dummy;

        stack<Node *> St;
        St.push(head);
        while (!St.empty())
        {
            Node *p = St.top();
            St.pop();
            curr->next = p;
            p->prev = curr;
            curr = curr->next; // critical step

            if (p->next)
                St.push(p->next);
            if (p->child)
                St.push(p->child), p->child = nullptr; // make child null for final DLL
        }

        dummy.next->prev = nullptr;
        return dummy.next;
    }
};