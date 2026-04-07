class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;
       unordered_map<char,int>map;
       for(int i = 0;i < s.size();i++)
       {
        map[s[i]]++;
        map[t[i]]--;
       }

       for(auto& [key,value] : map)
       {
        if(value != 0)
        {
            return false;
        }
       }

       return true;
    }
};
