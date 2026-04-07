class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;//target
        for(int i = n - 1;i >= 0;i--)
        {
            if(i + nums[i] >= goal)
            {
                goal = i;//it is jumping from right now
            }
        }

        return (goal == 0) ? true:false;
    }
};
