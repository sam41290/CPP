
/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].


*/


struct myTreeNode {
    int left_count;
    int val;
    myTreeNode *left;
    myTreeNode *right;
    myTreeNode(int x) : left_count(0),val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int insert(myTreeNode *root,int x)
    {
        //cout<<"root:"<<root<<"\n";
        int sum = 0;
        myTreeNode *node = root;
        while(1)
        {
            //cout<<"current val:"<<node->val<<"\n";
            if(node->val >= x)
            {
                
                if(node->left==NULL)
                {
                    node->left = new myTreeNode(x);
                    node->left_count = node->left_count + 1;
                    node = node->left;
                    break;
                }
                node->left_count = node->left_count + 1;
                node=node->left;
            }
            else
            {
                sum = sum + node->left_count + 1;
                if(node->right == NULL)
                {
                    node->right = new myTreeNode(x);
                    node = node->right;
                    break;
                }
                node=node->right;
            }
        }
        
        //cout<<"node:"<<node->val<<"\n";
        //cout<<"count:"<<node->left_count<<"\n";
        
        return sum;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ret(n);
        
        myTreeNode *root=NULL;
        
        for(int i=n-1;i>=0;i--)
        {
            if(root==NULL)
            {
                root = new myTreeNode(nums[i]);
                ret[i] = root->left_count;
            }
            else
                ret[i]=insert(root,nums[i]);
        }
        return ret;
    }
};
