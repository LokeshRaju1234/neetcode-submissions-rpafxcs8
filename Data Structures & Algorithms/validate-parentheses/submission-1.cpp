class Solution {
public:
    bool isValid(string s) {
        std::stack<char>s;
        std::unordered_map<char,char> closetoOpen
        {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for(char c : s)
        {
            if(closetoopen.count(c))
            {
                if(!s.empty() && s.top() == closetoopen[c])
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                s.push(c);
            }
        }
        return s.empty();
    }
};
