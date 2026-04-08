class Solution {
public:
    string longestPalindrome(string s) {
        
        int resLen = 0,resIdx = 0;

        
        for(int i = 0; i< s.size();i++)
        {

            // even length
            int l = i,r=i;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if((r - l + 1) > resLen)
                {
                    resLen = r - i + 1;
                    resIdx = l;
                }

                l--;
                r++;
            }

            //odd length
           l = i,r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                if((r - l + 1) > resLen)
                {
                    resLen = r - i + 1;
                    resIdx = l;
                }

                l--;
                r++;
            }
            
        }

        return s.substr(l,resLen);
    }
};
