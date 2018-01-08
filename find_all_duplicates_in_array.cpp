/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i]) - 1] < 0)
            {
                //cout<<"duplicate:"<<abs(nums[i])<<"\n";
                ret.push_back(abs(nums[i]));
            }
            else
            {
                //cout<<"marking:"<<abs(nums[i])<<"\n";
                nums[abs(nums[i]) - 1]=nums[abs(nums[i]) - 1]*-1;
            }
        }
        return ret;
        
    }
};
