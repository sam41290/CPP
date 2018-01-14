/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL)
            return ret;
        vector<TreeNode *> fringe;
        int depth = 0;
        int fringe_pos = 0;
        int next_itr = 1;
        fringe.push_back(root);
        
        while(next_itr != 0)
        {
            vector<int> tmp;
            if(depth%2!=0)
            {
                int j = fringe_pos + next_itr - 1;
                while(j>=fringe_pos)
                {
                    tmp.push_back(fringe[j]->val);
                    j--;
                }
            }
            else
            {
                int j = fringe_pos;
                while (j<=(fringe_pos + next_itr - 1))
                {
                    tmp.push_back(fringe[j]->val);
                    j++;
                }
            }
            ret.push_back(tmp);
            int i = next_itr;
            next_itr = 0;
            TreeNode *cur;
            for(int j=0;j<i;j++)
            {
                cur=fringe[fringe_pos];
                if(cur->left!=NULL)
                {
                    fringe.push_back(cur->left);
                    next_itr++;
                }
                if(cur->right!=NULL)
                {
                    fringe.push_back(cur->right);
                    next_itr++;
                }
                fringe_pos++;
            }
            depth++;
        }
        return ret;
    }
};
