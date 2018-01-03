/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

*/


class Solution {
public:
    int findLength(vector<int> A, vector<int> B) {
        int max_length=0;
        int dp[A.size() + 1][B.size() + 1];
        for(int i=0; i < A.size() + 1; i++)
        {
            for(int j=0; j < B.size() + 1;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=0; i < A.size(); i++)
        {
            for(int j=0; j < B.size();j++)
            {
                if(A[i]==B[j])
                {
                    dp[i + 1][j + 1]=dp[i][j] + 1;
                    if(dp[i+1][j+1] > max_length)
                        max_length = dp[i+1][j+1];
                }
            }
        }
        return max_length;
    }
};
