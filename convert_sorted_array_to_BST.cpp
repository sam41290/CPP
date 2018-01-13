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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size();
        TreeNode *root;
        if(n==0)
            return NULL;
        if(n==1)
        {
            root = new TreeNode(nums[0]);
            return root;
        }
        else
        {
            int mid = n/2;
            root = new TreeNode(nums[mid]);
            vector<int> vec_left(nums.begin(),nums.begin() + mid);
            vector<int> vec_right(nums.begin() + mid + 1,nums.end());
            root->left=sortedArrayToBST(vec_left);
            root->right=sortedArrayToBST(vec_right);
        }
        return root;
    }
};
