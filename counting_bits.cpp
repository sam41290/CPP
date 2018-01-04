/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/


class Solution {
public:
    vector<int> countBits(int num) {
        
        //int count[num + 1];
        
       // memset(count,-1,sizeof(count));
        
        vector<int> ret;
        
        int power = 0;
        
        int next_power = 1;
        
        for(int i=0;i <= num;i++)
        {
            if(i==0)
            {
                ret.push_back(0);
                //count[i]=0;
            }
            else if(i == next_power)
            {
                ret.push_back(1);
                power = next_power;
                next_power = next_power * 2;
                //count[i] = 1;
            }
            else if(i%2 != 0)
            {
                ret.push_back(ret[i - 1] + 1);
            }
            else
            {
                int tmp = i - power;
                int cnt = 1 + ret[tmp];
                ret.push_back(cnt);
                //count[i] = cnt;
            }
        }
        return ret;
        
    }
};
