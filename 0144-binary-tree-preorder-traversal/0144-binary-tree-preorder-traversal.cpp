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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        if(root == NULL)
            return output;
        stack <TreeNode*> s1;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode *curr = s1.top();
            cout<<curr->val;
            s1.pop();
            output.push_back(curr->val);
            if(curr->right!=NULL)
                s1.push(curr->right);
            if(curr->left!=NULL)
                s1.push(curr->left);
        }
        return output;
    }

};