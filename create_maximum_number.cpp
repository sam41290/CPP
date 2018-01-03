
/*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

*/


class Solution {
public:
    
    void display_vector(vector<int> &num)
    {
        for(int i=0;i<num.size();i++)
            cout<<num[i]<<" ";
        cout<<"\n";
    }
    
    vector<int> maxNum(vector<int> &num,int k)
    {
        int n=num.size();
        //cout<<"maxnum:"<<n<<k<<"\n";
        vector<int> largest(k);
        for(int i=0,j=0;i<n;i++)
        {
            while(n - i > k - j && j > 0 && largest[j - 1] < num[i])
                j--;
            if(j < k)
            {
                largest[j]=num[i];
                j++;
            }
        }
        return largest;
    }
    
    vector<int> merge(vector<int> &nums1,vector<int> &nums2)
    {
        int n1= nums1.size();
        int n2= nums2.size();
        cout<<"merge:"<<n1<<n2<<"\n";
        
        display_vector(nums1);
        display_vector(nums2);
        
        vector<int> merged(n1 + n2);
        int k=0;
        for(int i=0,j=0;i < n1 || j <n2;)
        {
            if(i < n1 && j < n2)
            {
                if(nums1[i] > nums2[j])
                {
                    merged[k]=nums1[i];
                    i++;
                    k++;
                }
                else if(nums1[i] < nums2[j])
                {
                    merged[k]=nums2[j];
                    j++;
                    k++;
                }
                else
                {
                    if(nums1[i] == nums2[j])
                    {
                        vector<int> vec1(nums1.begin() + i,nums1.end());
                        vector<int> vec2(nums2.begin() + j,nums2.end());
                        if(compare(vec1,vec2)==1)
                        {
                           merged[k]=nums1[i];
                           i++;
                           k++; 
                        }
                        else
                        {
                            merged[k]=nums2[j];
                            j++;
                            k++;
                        }
                            
                    }
                }
            }
            else if (i < n1)
            {
                merged[k]=nums1[i];
                i++;
                k++;         
            }
            else if(j < n2)
            {
                merged[k]=nums2[j];
                j++;
                k++;
            }
        }
        return merged;
    }
    
    int compare(vector<int> &nums1,vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i;
        for (i = 0; i<n1 || i <n2 ;i++)
        {
            if(i >= n1 || i >= n2)
                break;
            if(nums1[i] > nums2[i])
                return 1;
            if(nums2[i] > nums1[i])
                return -1;
        }
        if(i >= n1 && i < n2)
            return -1;
        else if (i < n1 && i >=n2)
            return 1;
        else
            return 0;
        
        return 0;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int large=0;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> max_num;
        
        for (int i=0;i < k;i++)
            max_num.push_back(0);
        
        int i = max(0,k - n2);
        while(i <= n1 && i <= k)
        {
            vector<int> large_num1 = maxNum(nums1,i);
            vector<int> large_num2 = maxNum(nums2, k - i);
            vector<int> large_num = merge(large_num1,large_num2);
            if(compare(large_num,max_num)==1)
                max_num=large_num;
            i++;
        }
        return max_num;
    }
};
