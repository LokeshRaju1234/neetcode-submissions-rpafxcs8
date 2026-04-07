class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
         int n = s.size(),si = 0,ei = 0,len = 0,count = 0;

        vector<int>freq(128,0);

        while(ei < n)
        {
            if(freq[s[ei++]]++ == 0) count++;
            while(count > 2)
            {
                if(freq[s[si++]]-- == 1) count--;
            }

            len = max(len,ei - si);
        }

        return len;
    }
};

