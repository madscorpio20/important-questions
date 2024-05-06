/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = head->next;
        while(curr!=NULL){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(curr != NULL)
                nxt = curr->next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp = reverse(head);
        head = temp;
        while(temp != NULL){
            ListNode *nxt = temp->next;
            while(nxt != NULL && temp->val > nxt->val){
                nxt = nxt->next;
            }
            temp->next = nxt;
            temp = nxt;
        }
        ListNode *newHead = reverse(head);
        return newHead;
        
    }
};