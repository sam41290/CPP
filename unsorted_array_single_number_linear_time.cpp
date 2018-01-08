
/*every number present twice except one number*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int all_sum=0;
        for(int i = 0; i < nums.size();i++)
        {
            all_sum = all_sum ^ nums[i];

        }
        return all_sum;
    }
};

/*every number present thrice except one*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first = 0, second = 0;
        for(int i =0; i < nums.size();i++)
        {
            first = first ^ nums[i] & ~(second);
            second = second ^ nums[i] & ~(first);
        }
        return first;
    }
};
