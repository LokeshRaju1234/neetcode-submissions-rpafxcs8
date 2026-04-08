class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dfs(s,wordDict,0);
    }

    bool dfs(string s, vector<string>& wordDict,int i)
    {

        if(i == s.length())
        {
            return true;
        }
        
        for(string w : wordDict)
        {
            if(i + w.length() <= s.length() && s.substr(i,w.length()) == w)
            {
                if(dfs(s,wordDict,i + w.length()))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
