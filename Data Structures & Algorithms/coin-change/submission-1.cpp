class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int mincoins = dfs(coins,amount);
        return (mincoins >= 1e9)? -1:mincoins;
    }

    private:
    int dfs(vector<int>& coins,int amount)
    {
        if(amount == 0)
        {
            return 0;
        }
        int res = 1e9;
        for(int coin : coins)
        {
            if(amount - coin >= 0)
            {
                 res = 1 + min(res,dfs(coins,amount - coin));
            }
        }

        return res;
    }
};
