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
    int findSize(ListNode *head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = findSize(head);
        
        vector<ListNode*> ans(k);
        int partSize = size/k;
        int extraSize = size%k;
        int ind = 0;
        ListNode *temp = head;
        int currSize = 0;
        while(temp!=NULL){
            ListNode *newHead = temp;
            ListNode *newTail = temp;
            while(currSize < partSize){
                newTail = temp;
                temp = temp->next;
                currSize++;
            }
            if(extraSize > 0){
                newTail = temp;
                temp = temp->next;
                extraSize--;
            }
            newTail->next = NULL;
            ans[ind] = newHead;
            ind++;
            currSize = 0;
        }
        return ans;
    }
};