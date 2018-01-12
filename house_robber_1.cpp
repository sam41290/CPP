/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        int max_profit = 0;
        if(n==0)
            return 0;
        
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        if(n==3)
            return max(nums[1],nums[0] + nums[2]);
        int dp[n];
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[0] + nums[2];
        
        for(int i =0;i<n;i++)
        {
            if(i > 2)
                dp[i]=max(nums[i] + dp[i-2],nums[i] + dp[i-3]);
            if(dp[i] > max_profit)
                max_profit = dp[i];
        }
        return max_profit;
    }
};
