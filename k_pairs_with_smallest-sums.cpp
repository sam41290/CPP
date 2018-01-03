
/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]


*/



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
