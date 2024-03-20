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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt = 0;
        ListNode *temp = list1;
        while(cnt < a - 1){
            temp = temp->next;
            cnt++;
        }
        ListNode *temp1 = temp->next;
        temp->next = list2;
        ListNode *temp2 = list2;
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        
        while(cnt < b-1){
            temp1 = temp1->next;
            cnt++;
        }
        temp2->next = temp1->next;
        return list1;
    }
};