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
    void find(TreeNode* root, string s, int &sum)
    {
        s+= to_string(root->val);
        if(!root->left && !root->right)
        {
            sum+= stoi(s);
            return;
        }
        if(root->left)
        find(root->left,s,sum);
        if(root->right)
        find(root->right,s,sum);
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        int sum = 0;
        find(root,s,sum);
        return sum;
    }
};