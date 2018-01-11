#include <iostream>
#include <vector>
#include<climits>

using namespace std;

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount <= 0)
            return 0;
        int max_size = amount;
        
        int dp[max_size];
        
        for(int i=0;i<max_size;i++)
            dp[i]=-1;
        
        for(int i = 0; i < coins.size();i++)
        {
            if(coins[i] > amount)
                continue;
            dp[coins[i] - 1]= 1;
        }
        for(int i=0;i<amount;i++)
        {
            if(dp[i]==1)
                continue;
            else 
            {
                int min_count = INT_MAX;
                for(int j=0;j<coins.size();j++)
                {
                    int coin = coins[j];
                    if(coin > (i + 1))
                        continue;
                    int left = (i+1)-coin;
                    int coin_count = 0;
                    if(dp[left - 1] > 0)
                        coin_count = 1 + dp[left - 1];
                    if(coin_count < min_count && coin_count!=0)
                        min_count = coin_count;
                }
                if(min_count < INT_MAX)
                    dp[i]=min_count;
            }
        }
        return dp[amount - 1];
       
    }
};

int main()
{
        Solution sol;
	int vec[]={186,419,83,408};
	vector<int> coins(vec,vec + sizeof(vec)/sizeof(vec[0]));
        int cnt=sol.coinChange(coins,6249);
        cout<<"coin count: "<<cnt<<"\n";
        return 0;
}
