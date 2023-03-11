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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSize (ListNode *head)
    {
        int size = 0;
        while(head!=NULL)
        {
            head = head->next;
            size++;
        }
        return size;
    }
    TreeNode *help(ListNode* &head, int size)
    {
        if(size <= 0) return NULL;
        TreeNode *left = help(head,size/2);
        TreeNode *curr = new TreeNode(head->val);
        head = head->next;
        TreeNode *right = help(head, size - size/2 - 1);
        curr->left = left;
        curr->right = right;
        return curr;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int size = findSize(head);  
        return help(head, size);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};