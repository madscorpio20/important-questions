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
     string find(TreeNode* root, unordered_map<string,int> &m, vector<TreeNode*> &ans)
    {
         if(!root) return "#";
         string left = find(root->left,m,ans);
         string right = find(root->right,m,ans);
         string curr = to_string(root->val) + " " + left + " " + right;
         m[curr]++;
         if(m[curr] == 2)
         {
             // cout<<curr<<endl;
             ans.push_back(root);
         }
         // cout<<ans.size()<<" "<<root->val<<endl;
         return curr;
             
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode*> ans;
        find(root,m,ans);
        return ans;
    }
};