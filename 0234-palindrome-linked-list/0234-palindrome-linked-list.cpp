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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        fast = slow->next;
        slow = head;
        while(fast!=NULL)
        {
            if(fast->val!=slow->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};