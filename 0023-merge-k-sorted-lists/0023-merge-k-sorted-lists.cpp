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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool allNULL = false;
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while(!allNULL)
        {
            allNULL = true;
            int smallest = 1e9;
            int smallestInd = -1;
            for(int i = 0; i< lists.size(); i++)
            {
               if(lists[i]!= NULL)
               {
                   allNULL = false;
                   if(lists[i]->val < smallest)
                   {
                       smallest = lists[i]->val;
                       smallestInd = i;
                   }
               }
            }
            if(smallest != 1e9)
            {
                curr->next = lists[smallestInd];
                curr = curr->next;
                lists[smallestInd] = lists[smallestInd]->next;
            }
        }
        return head->next;
    }
};