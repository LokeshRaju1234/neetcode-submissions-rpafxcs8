class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;

        if(s.length() != t.length())
        {
            return false;
        }


        for(auto str : s)
        {
            map1[str]++;
        }

        for(auto str1 : t)
        {
            map2[str1]++;
        }

        bool res = false;
        for(int i = 0;i<map1.length();i++)
        {
            if(map1[s[i]] == map2[t[i]])
            {
                res = true;
            }
            else
            {
                res = false;
            }
        }

        return res'

    }
};
