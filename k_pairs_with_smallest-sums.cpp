class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<pair<int,int>> ret;
        
        int pair_count = size1 * size2;
        
        if(pair_count == 0)
            return ret;
        
        
        
        int min_index;
        
        int index[size1];
        
        for(int i=0;i<size1;i++)
            index[i]=0;
        
        while (k>0 && pair_count > 0)
        {
            int min_sum=INT_MAX;
            for(int i=0;i<size1;i++)
            {
                if(index[i] < size2)
                {
                    int sum=nums1[i] + nums2[index[i]];
                    
                    if(sum <= min_sum)
                    {
                        min_sum=sum;
                        min_index=i;
                    }
                }
            }
            ret.push_back(pair<int,int>(nums1[min_index],nums2[index[min_index]]));
            index[min_index]=index[min_index] + 1;
            k--;
            pair_count--;
        }
        return ret;
        
    }
};
