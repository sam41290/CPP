class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = 1;
        int all_product = INT_MIN;
        int min_product = 1; 
        for(int j=0; j < nums.size() ; j++)
        {
            if(nums[j] < 0)
            {
                int tmp = max_product;
                max_product = max(min_product * nums[j],nums[j]);
                min_product = min(tmp * nums[j],nums[j]);
            }
            else
            {
                max_product = max(max_product * nums[j],nums[j]);
                min_product = min(min_product * nums[j],nums[j]);
            }
            if(max_product > all_product)
                all_product = max_product;
            //cout<<"max product:"<<max_product<<"\n";
            //cout<<"min product:"<<min_product<<"\n";
            //cout<<"all product:"<<all_product<<"\n";
        }
        return all_product;
            
    }
};
