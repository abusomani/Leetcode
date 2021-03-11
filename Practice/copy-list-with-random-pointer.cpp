/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        Node *curr = head;
        // insert node between every node
        while(curr) {
            Node *nxt = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nxt;
            curr = nxt;
        }
        //form the random links
        curr = head;
        while(curr) {
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        // form the next links
        Node *newHead = head->next, *res = head->next;
        curr = head;
        while(curr){
            if(newHead)
                curr->next = newHead->next;
            if(curr->next)
                newHead->next = curr->next->next;
            curr = curr->next;
            newHead = newHead->next;
        }
        return res;
    }
};