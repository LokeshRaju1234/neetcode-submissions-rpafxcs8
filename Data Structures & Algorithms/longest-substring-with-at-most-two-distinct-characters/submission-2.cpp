class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int>map;

        int length = 0,left = 0,right = 0,count = 0;

        while(right < s.size())
        {
            map[s[right++]]++;
            if(map.size() > 2) count++;
            while(count == 1)
            {
                map[s[left]]--;
                if(map[s[left]] == 0) map.erase(s[left]);left++;
                if(map.size() == 2) count--;
            }

            length = max(length,right - left);
        }

        return length;
    }
};

