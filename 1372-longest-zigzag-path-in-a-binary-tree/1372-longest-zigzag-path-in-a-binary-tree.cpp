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
    int helper(TreeNode *root, int prevIsLeft, int cnt)
    {
        if(!root->right && !root->left)
            return cnt;
        if(prevIsLeft!=0)
        {
            int first = cnt;
            int second = cnt;
            if(root->right)
                first = helper(root->right, 0, cnt+1);
            if(root->left)
                second = helper(root->left, 1, 1);
            return max(first,second);
        }
        else
        {
            int first = cnt;
            int second = cnt;
            if(root->left)
                first = helper(root->left, 1, cnt+1);
            if(root->right)
                second = helper(root->right, 0, 1);
            return max(first, second);
        }
    }
    int longestZigZag(TreeNode* root) {
        return helper(root,2,0);
    }
};