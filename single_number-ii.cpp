//We can sum the bits in same positions for all the numbers and take modulo with 3.
// The bits for which sum is not multiple of 3, are the bits of number with single occurrence.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                if((nums[j] & (1<<i))!=0)
                    count++;
            }
            res= res | ((count%3) << i);
        }
        return res;
    }
};
