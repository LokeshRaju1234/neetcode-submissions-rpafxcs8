class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
         unordered_map<char,int>map;

        int length = 0,left = 0,right = 0,count = 0;

        while(right < s.size())
        {
            map[s[right++]]++;
            if(map.size() > k) count++;
            while(count == 1)
            {
                map[s[left]]--;
                if(map[s[left]] == 0) map.erase(s[left]);left++;
                if(map.size() == k) count--;
            }

            length = max(length,right - left);
        }

        return length;
    }
};
