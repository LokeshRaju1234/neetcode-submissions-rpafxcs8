class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;
       unordered_map<char,int>map1;
       unordered_map<char,int>map2;

       for(char a : s)
       {
        map1[a]++;
       }

       for(char b : t)
       {
        map2[b]++;
       }

       return map1 == map2;
    }
};
