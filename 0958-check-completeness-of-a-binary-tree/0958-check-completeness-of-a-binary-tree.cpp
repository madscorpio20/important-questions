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
    int find(TreeNode *root)
    {
        if(!root)
            return 0;
        return find(root->left) + 1;
    }
    bool isCompleteTree(TreeNode* root) {
        int lvl = find(root);
        queue<TreeNode*>  q;
        q.push(root);
        int currLvl = 1;
        while(!q.empty())
        {
            bool prev = true;
            if(currLvl != lvl && q.size()!=pow(2,currLvl-1))
                return false;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if(currLvl!= lvl && curr == NULL)
                    return false;
                if(currLvl == lvl)
                {
                    if(!curr)
                    {
                        prev = false;
                        continue;
                    }
                    if(curr->left || curr->right)
                        return false;
                    if(!prev)
                        return false;
                    
                }
                else
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
                
            }
            currLvl++;
        }
        return true;
    }
};