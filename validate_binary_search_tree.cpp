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
    bool isValidBST(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        vector<TreeNode *> stack;
        TreeNode *current=root;
        int top=-1;
        TreeNode *prev=NULL;
        while(current!=NULL)
        {
            stack.push_back(current);
            top++;
            if(current->left==NULL)
            {
                while(top>=0)
                {
                    current = stack[top];
                    top--;
                    stack.pop_back();
                    
                    if(prev!=NULL && (prev!=current && current->val <= prev->val))
                        return false;
                    prev=current;
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
        return true;
    }
};
