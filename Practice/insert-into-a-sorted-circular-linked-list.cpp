/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution
{
public:
    Node *insert(Node *head, int x)
    {
        if (!head)
        {
            head = new Node(x);
            head->next = head;
            return head;
        }
        bool inserted = false;
        Node *prev = head, *next = head->next;
        while (next != head)
        {
            int prevVal = prev->val, nextVal = next->val;
            if (prevVal == x or (x > prevVal and x <= nextVal) or (x > prevVal and nextVal < prevVal) //  [4, 1] => [6]
                or (x < nextVal and nextVal < prevVal))                                               // [4, 1] => [0]
            {
                inserted = true;
                Node *curr = new Node(x);
                curr->next = next;
                prev->next = curr;
                break;
            }
            prev = next;
            next = next->next;
        }
        if (!inserted)
        {
            Node *curr = new Node(x);
            curr->next = next;
            prev->next = curr;
        }
        return head;
    }
};