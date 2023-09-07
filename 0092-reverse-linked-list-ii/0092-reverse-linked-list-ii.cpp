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
    ListNode *reverse(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *later = head->next;
        while(curr!=NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = later;
            if(later!=NULL)
                later = later->next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right)
            return head;
        ListNode *tail = head;
        ListNode *prev = new ListNode(-1);
        prev->next = tail;
        ListNode *temp = prev;
        ListNode *reverseHead, *reverseTail , *before, *after;
        int index = 1;
        while(tail!=NULL)
        {
            if(left == index)
            {
                before = prev;
                reverseHead = tail;
            }
            if(right == index)
                reverseTail = tail;
            index++;
            prev = tail;
            tail = tail->next;
        }
        after = reverseTail->next;
        reverseTail->next = NULL;
        before->next = reverse(reverseHead);
        reverseHead->next = after;
        return temp->next;
        
    }
};