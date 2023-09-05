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
            return NULL;
        map<Node*,Node*> m;
        Node *temp = head;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val);
            m[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                m[temp]->next = m[temp->next];
            }
            else
                m[temp]->next = NULL;
            if(temp->random!=NULL)
                m[temp]->random = m[temp->random];
            else
                m[temp]->random = NULL;
            temp = temp->next;
        }
        return m[head];
    }
};