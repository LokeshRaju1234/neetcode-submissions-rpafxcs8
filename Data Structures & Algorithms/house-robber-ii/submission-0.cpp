class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }

        return max(helper(vector<int>(nums.begin() + 1,nums.end())),helper(vector<int>(nums.begin(),nums.end() - 1)))
    }

    int helper(vector<int>& nums)
    {
        vector<int>dp(nums.size());
        if(nums.size() == 1)
        {
            return nums[0];
        }

        if(nums.empty())
        {
            return 0;
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size() - 1;i++)
        {
            dp[i] = max(dp[i - 1],dp[i - 2]);
        }
        return dp.back();
    }
};
