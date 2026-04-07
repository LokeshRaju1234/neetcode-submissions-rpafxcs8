class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {

        unordered_map<int,int>map;

        for(int ele : nums)
        {
            if(map.find(ele) == map.end())
            {
                map[ele]++;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};