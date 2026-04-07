class Solution {
public:
    bool isValid(string s) {
        std::stack<char>S;
        std::unordered_map<char,char> closetoopen
        {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for(char c : s)
        {
            if(closetoopen.count(c))
            {
                if(!S.empty() && S.top() == closetoopen[c])
                {
                    S.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                S.push(c);
            }
        }
        return S.empty();
    }
};
