class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int>map;

        int length = 0,left = 0,right = 0,count = 0;

        while(right < s.size())
        {
            if(map.size() < 2) map[s[right++]]++;
            if(map.size() == 2 && map.find(s[right++]++) != map.end()) count++;
            while(count == 1)
            {
                map[s[left++]]--;
                if(map[left] == 0)
                {
                    map.erase(s[left]);
                    left++;
                    count--;
                }
            }

            length = max(length,right - left);
        }

        return length;
    }
};