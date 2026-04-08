class Solution {
public:
    bool isAnagram(string s, string t) {
       unodered_map<char,int>map1;
       unodered_map<char,int>map2;

       for(char a : s)
       {
        map1[a]++
       }

       for(char b : t)
       {
        map2[b]++
       }

       return map1 == map2;
    }
};
