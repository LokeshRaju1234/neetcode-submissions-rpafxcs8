class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;

        if(s.length() != t.length())
        {
            return false;
        }

        for(int i = 0;i < s.size();i++)
        {
            map1[s[i]]++;
            map2[t[i]]++;
        }

        return map1 == map2;
    }
};
