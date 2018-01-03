/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

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
class Solution1 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        //cout<<"array size:"<<nums.size()<<"\n";
        
        if(nums.size() == 0)
            return NULL;
        
        int max=0;
        int max_ind = 0;
        for(int i=0;i < nums.size();i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
                max_ind=i;
            }
        }
        TreeNode *root = new TreeNode(max);
        
        //cout<<"max="<<max<<"\n";
         //cout<<"max ind="<<max_ind<<"\n";
        
        if(max_ind > 0)
        {
            cout<<"going left for "<<max<<"\n";
            vector<int> left(nums.begin(),nums.begin() + max_ind );
            root->left = constructMaximumBinaryTree(left);
        }
        else
            root->left = NULL;
        if(max_ind < nums.size() - 1)
        {
            cout<<"going right for "<<max<<"\n";
            vector<int> right(nums.begin() + max_ind + 1 ,nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        else
            root->right=NULL;
        return root;
    }
};

class Solution2 {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        TreeNode *tree=NULL;
        for(int i=0;i < nums.size();i++)
        {
            TreeNode *cur = new TreeNode(nums[i]);
            if(tree==NULL)
                tree = cur;
            else
            {
                TreeNode *root = tree;
                if(cur->val > root->val)
                {
                    cur->left = root;
                    tree = cur;
                }
                else
                {
                    TreeNode *prev = root;
                    root = root->right;
                    while (root!=NULL)
                    {
                        if(cur->val > root->val)
                        {
                            cur->left=root;
                            prev->right=cur;
                            break;
                        }
                        prev=root;
                        root=root->right;
                    }
                    if(root == NULL)
                        prev->right = cur;
                }
            }
            
        }
        return tree;
    }
};
