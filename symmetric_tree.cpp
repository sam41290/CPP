/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
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
    
    bool isSymmetric(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        bool ret = true;
        
        vector<TreeNode *> fringe;
        fringe.push_back(root);
        int depth = 0;
        int next_itr=1;
        int fringe_pos = 0;
        while(next_itr!=0)
        {
            int i = next_itr;
            int k = fringe_pos + i - 1;
            next_itr = 0;
            if(i==1)
            {
                TreeNode *tmp = fringe[fringe_pos];
                fringe.push_back(tmp->left);
                next_itr++;
                fringe.push_back(tmp->right);
                next_itr++;
                fringe_pos++;
            }
            else
            {
                int mid = i/2;
                
                for(int j=0;j<i;j++)
                {
                    TreeNode *tmp = fringe[fringe_pos];
                    if(tmp!=NULL)
                    {
                        fringe.push_back(tmp->left);
                        next_itr++;
                        fringe.push_back(tmp->right);
                        next_itr++;
                    }
                    if(j<mid)
                    {
                        TreeNode *tmp2 = fringe[k];
                        if(tmp == NULL && tmp2!=NULL)
                            return false;
                        else if(tmp2 == NULL && tmp!=NULL)
                            return false;
                        else if(tmp!=NULL && tmp2!=NULL)
                        {
                            if(tmp->val != tmp2->val)
                                return false;
                        }
                        k--;
                    }
                    fringe_pos++;
                }
                
            }
            
        }
        return ret;
    }
};
