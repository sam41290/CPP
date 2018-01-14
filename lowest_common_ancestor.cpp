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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> stack;
        TreeNode *ret;
        int x=-1,y=-1,top=-1;
        TreeNode *current = root;
        int found = 0;
        while(current!=NULL)
        {
            stack.push_back(current);
            top++;
            if(current == p || current == q)
            {
                if(y==-1)
                {
                    x=top;
                    y=1;
                    ret=stack[x];
                }
                cout<<"lca ind:"<<x<<"\n";
                found++;
            }
            if(found == 2)
                return ret;
            if(current->left==NULL)
            {
                while(top>=0)
                {
                    current = stack[top];
                    top--;
                    if(y==1 && x>top)
                    {
                        ret=stack[x];
                        x=top;
                    }
                    stack.pop_back();
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
        if(found==2)
            return ret;
        return NULL;
    }
};
