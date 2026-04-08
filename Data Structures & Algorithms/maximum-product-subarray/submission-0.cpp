class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxprod = nums[0];

        for(int i = 1;i < nums.size();i++)
        {
            maxprod = max(nums[i],maxprod * nums[i]);
            res = max(res,maxprod);
        }

        return res;
    }
};
