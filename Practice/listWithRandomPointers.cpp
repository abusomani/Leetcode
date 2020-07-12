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
        if(head == NULL)
            return head;
        
        Node * temp = head, * curr = head, *dummy;
        
        // insert nodes between two nodes.
        while(temp != NULL) {
            dummy = new Node(temp->val);
            dummy->next = temp->next;
            temp->next = dummy;
            temp = dummy->next;
        }
        
        // copy random pointers
        temp = curr;
        while(temp and temp->next) {
            temp->next->random = (temp->random ? temp->random->next : NULL);
            temp = temp->next->next;
        }
        
        // remove the original links
        temp = curr;
        curr = temp->next;
        while(temp and temp->next) {
            dummy = temp->next;
            temp->next = dummy->next;
            dummy->next = (dummy->next ? dummy->next->next : NULL);
            temp = temp->next;
        }
        
        return curr;
        
    }
};