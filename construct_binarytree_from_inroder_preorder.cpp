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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        cout<<preorder.size()<<" "<<inorder.size()<<"\n";
        
        if(preorder.size()==0 || inorder.size()==0)
            return NULL;
        
        TreeNode *root = new TreeNode(preorder[0]);
        
        vector<int> inorder_left;
        
        int i;
        for(i = 0;i<inorder.size();i++)
        {
            if(inorder[i]==preorder[0])
                break;
            inorder_left.push_back(inorder[i]);
        }
        vector<int> preorder_left;
        int j;
        for(j=1;j<=i;j++)
            preorder_left.push_back(preorder[j]);
        
        root->left = buildTree(preorder_left,inorder_left);
        
        int right_size = inorder.size() - (i+1);
        if(right_size > 0)
        {
            vector<int> inorder_right(inorder.begin() + i + 1,inorder.end());
            vector<int> preorder_right(preorder.begin() + i + 1,preorder.end());
            root->right = buildTree(preorder_right,inorder_right);
        }
        return root;
        
    }
};
