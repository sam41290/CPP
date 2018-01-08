/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            cout<<"getting array of size 0\n";
            return 0;
        }
        if(n==1)
            return nums[0];
        int mid = n/2;
        int ret;
        int left;
        int right;
        if(nums[mid] == nums[mid + 1])
        {
            right = (n - 1) / 2 - 1;
            left = (n - 1)/2;
        }
        else if(nums[mid] == nums[mid - 1])
        {
            right = (n - 1) / 2;
            left = (n - 1)/2  - 1;
        }
        else
            return nums[mid];
        
        if(right % 2 != 0)
        {
            vector<int> vec(nums.begin() + left + 2,nums.end());
            ret=singleNonDuplicate(vec);
        }
        else if(left % 2 != 0)
        {
            vector<int> vec(nums.begin(),nums.begin() + left);
            ret=singleNonDuplicate(vec);
        }
        
        return ret;
    }
};
