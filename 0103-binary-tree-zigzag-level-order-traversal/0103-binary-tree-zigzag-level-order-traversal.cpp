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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(root == NULL) return output;
        queue<TreeNode*> queue;
        queue.push(root);
        int level = 0;
        while(!queue.empty())
        {
            vector<int> temp;
            int len = queue.size();
            for(int i=0; i<len; i++)
            {
                TreeNode *front = queue.front();
                queue.pop();
                temp.push_back(front->val);
                if(front->left!=NULL)
                    queue.push(front->left);
                if(front->right!=NULL)
                    queue.push(front->right);
            }
            if(level%2 != 0)
                reverse(temp.begin(),temp.end());
            output.push_back(temp);
            level++;
        }
        return output;
    }
};