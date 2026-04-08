class Solution {
public:
    string foreignDictionary(vector<string>& words) 
    {
        unordered_map<char,unordered_set<char>>adj;
        unordered_map<char,int>indegree;

        for(string s : words)
        {
            for(char c : s)
            {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for(int i = 0;i < words.size();i++)
        {
            string w1 = words[i],w2 = words[i + 1];
            int minlen = min(w1.size(),w2.size());
            if(w1.size() > w2.size() && w1.substr(0,minlen) == w2.substr(0,minlen))
            {
                return "";
            }
            for(int j = 0;j < minlen;j++)
            {
                if(w1[j] != w2[j])
                {
                    if(!adj.count(w2[j]))
                    {
                        adj[w1[j]].push_back(w2[j]);
                        indegree[w2[j]]++;
                    }
                }
            }

        }

        queue<int>q;
        for(auto& [c,degree] : indegree)
        {
            if(degree == 0)
            {
                q.push(c);
            }
        }

        string res;
        while(!q.empty())
        {
            char char_ = q.front();
            q.pop();
            res += char_;
            for(char nei : adj[char_])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }

        }
        return res.size() == indegree.size() ? res : "";
    }
};
