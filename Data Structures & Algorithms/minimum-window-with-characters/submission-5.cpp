class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>target;
        for(char a : t)
        {
            target[a]++;
        }

        int resLen = INT_MAX;
        pair<int,int> res = {-1,-1};

        for(int i = 0;i < s.size();i++)
        {
            unordered_map<char,int>map;
            for(int j = i;j < s.size();j++)
            {
                map[s[j]]++;
                bool valid = true;
                for(auto &[c,cnt] : target)
                {
                    if(map[c] < cnt)
                    {
                        valid = false;
                        break;
                    }
                }

                if(valid && (j - i + 1) < resLen)
                {
                    resLen = j - i + 1;
                    res = {i,j};
                }
            }
        }
         resLen == INT_MAX ? return "" : return s.substr(res.first,resLen);

    }
};
