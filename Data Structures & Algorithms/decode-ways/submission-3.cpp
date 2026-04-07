class Solution {
public:
    int dfs(int i,string s)
    {
        int res = 0;
        if(i == s.length())
        {
            return 1;
        }

        if(s[i] == '0')
        {
            return 0;
        }

        res = dfs(i + 1,s);
       if(i < s.size() - 1)
       {
        if(s[i] == '1' ||
        s[i] == '2' && s[i + 1] < '7')
        {
            res += dfs(i + 2,s);
        }
       }

       return res;

    }
    int numDecodings(string s) {
        return dfs(0,s);
    }
};