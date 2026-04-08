class Solution {
public:
    int countSubstrings(string s) {
        string T = "^";
        for(char c : s)
        {
            T += "#";
            T += c;
        }
        T += "#$";

        int n = T.length();
        int c = 0, r = 0;
        vector<int>p(n,0);

        for(int i = 1;i < n - 1;i++)
        {
            int mirror = 2 * c - i;
            if(i < r)
            {
                p[i] = min(r - i,p[mirror]); //p[i] cannot be bigger than p[mirror]
            }

            while(T[i - p[i] - 1] == T[i + p[i] + 1])
            {
                p[i]++;
            }

            //update center if it is max Palindrome 
            if(i + p[i] > r)
            {
                c = i;
                r = i + p[i];
            }

        }

        int count = 0;
for (int i = 1; i < n - 1; i++) {
    count += (P[i] + 1) / 2;
}

    }
};