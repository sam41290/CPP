/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ret;
        vector<TreeNode *> stack;
        TreeNode *current=root;
        int top=-1;
        while(current!=NULL)
        {
            stack.push_back(current);
            top++;
            if(current->left==NULL)
            {
                //ret.push_back(current->val);
                while(top>=0)
                {
                    current = stack[top];
                    top--;
                    stack.pop_back();
                    ret.push_back(current->val);
                    if(current->right != NULL)
                    {
                        break;
                    }
                }
                current=current->right;
                continue;

            }
            current=current->left;

        }
        return ret[k-1];
    }
};
