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
    
    int max_depth = 0;
    
    void dfs(TreeNode *node,int depth)
    {
        if(depth > max_depth)
            max_depth = depth;
        if(node->left!=NULL)
            dfs(node->left,depth + 1);
        if(node->right!=NULL)
            dfs(node->right,depth + 1);
        return;
    }
    
    int maxDepth(TreeNode* root) {
        if(root!=NULL)
            dfs(root,1);
        return max_depth;
    }
};
