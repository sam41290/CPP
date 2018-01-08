/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/


class Solution {
public:
    
    map<int,int> dp;
    
    int get_val(int n)
    {
        //cout<<"getting value for:"<<n<<"\n";
        map<int,int> :: iterator itr;
        if(n==0)
            return 0;
        itr = dp.find(n);
        if(itr != dp.end())
            return itr->second;
        else
        {
            int min_count = INT_MAX;
            for(int i = 1;i * i<=n;i++)
            {
                int j = i*i;
                //dp.insert(pair<int,int>(i*i,1));
                int count = 1 + get_val(n - j);
                if(count < min_count)
                    min_count = count;
                if(min_count == 2)
                    break;
            }
            dp.insert(pair<int,int>(n,min_count));
            return min_count;
        }
        return 0;
    }
    
    int numSquares(int n) {
        
        
        for(int i=1;i*i<=n;i++)
        {
            //dp.erase(i*i);
            dp.insert(pair<int,int>(i*i,1));
            //dp.insert(pair<int,int>(i*i + (i-1)*(i-1),2));
            //dp.insert(pair<int,int>(i*i + (i)*(i),2));
        }
        int ret = get_val(n);
        
        return ret;
        
    }
};
