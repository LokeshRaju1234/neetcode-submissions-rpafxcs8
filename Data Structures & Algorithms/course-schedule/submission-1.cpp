class Solution {
    unordered_set<int>visited;
    unordered_map<int,vector<int>> map;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < numCourses,i++)
        {
            map[i] = {};
        }

        for(const auto& preq : prerequisites)
        {
            map[preq[0]].push_back(preq[1]);
        }

        for(int i = 0; i < numCourses;i++)
        {
            if(!dfs(i))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(int crc)
    {
        if(visited.count(crc))
        {
            return false;
        }

        if(map[crc].empty())
        {
            return true;
        }

        visited.insert(crc);

        for(int pre : map[crc])
        {
            if(!dfs(pre))
            {
                return false;
            }
        }

        visited.erase(crc);
        map[crc].clear();
        return true;
    }
};
