class Solution {
public:
    string minWindow(string s, string t) {

        if(t.empty())return "";

        unordered_map<char,int>target,window;

        for(char a : t)
        {
            target[a]++;
        }

        int resLen = INT_MAX;
        pair<int,int> res = {-1,-1};
        int l = 0;
        int have = 0;
        int need = target.size();
        for(int r = 0;r < s.size();r++)
        {
            char c= s[r];
            window[c]++;

            if(target.count(c) && window[c] == target[c])
            {
                have++;
            }

            while(have == need)
            {
                if((r - l + 1) < resLen)
                {
                    resLen = r- l + 1;
                    res = {l,r};
                }
                window[s[l]]--;
                if(target.count(s[l]) && window[s[l]] < target[s[l]])
                {
                    have--;
                }

                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first,resLen);
    }
};
