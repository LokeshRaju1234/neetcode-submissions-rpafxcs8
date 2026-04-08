class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encode = "";
        for(int i = 0; i<strs.size();i++)
        {
            for(char c : strs[i])
            {
                encode += c;
                encode += '#';
            }
            encode += ',';
        }

        return encode;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string decode = "";
        for(char c : s)
        {
            if(c == '#')
            {
                continue;
            }

            else if(c == ',')
            {
                res.push_back(decode);
                decode = "";
            }
            else
            {
                decode += c;
            }
        }
        return res;
    }
};
