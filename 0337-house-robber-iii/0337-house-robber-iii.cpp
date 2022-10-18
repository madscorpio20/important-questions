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
    int find(TreeNode *root, bool prev,unordered_map<TreeNode*,unordered_map<bool,int>> &m)
    {
        if(!root)
            return 0;
        int pick = -1;
        if(m[root][prev])
            return m[root][prev];
        if(!prev)
        {
            int left = find(root->left,true,m);
            int right = find(root->right,true,m);
            pick = left + right + root->val;
        }
        int notPick = find(root->left,false,m) + find(root->right,false,m);
        return m[root][prev] = max(pick, notPick);
            
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,unordered_map<bool,int>> m;
        return find(root,false,m);
    }
};