/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/


class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.length();
        
        if(n==0)
            return 0;
        if(s[0]=='0')
            return 0;
        
        int dp[n];
        
        
        for(int i=0;i<s.length();i++)
        {
            int tmp1 = 0;
            int tmp2 = 0;
            int tmp = 0;
            if(i == 0)
                dp[i] = 1;
            else
            {
                dp[i] = 0;
                tmp1 = s[i] - '0';
                tmp2 = s[i - 1] - '0';
                tmp = tmp + 1 * tmp1;
                if(tmp > 0)
                    dp[i]=dp[i] + dp[i-1];
                
                tmp = tmp + 10 * tmp2;
                if(tmp <= 26 && tmp > 0 && tmp2 > 0)
                {
                    if(i - 1 == 0)
                        dp[i]=dp[i]+1;
                    else
                        dp[i] = dp[i] + dp[i-2];
                }
            }
        }
        
        return dp[n - 1];
        
    }
};
