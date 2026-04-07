class Solution {
       vector<int>memo;
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.resize(amount + 1, -1);
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

        if(memo[amount] != -1)
        {
            return memo[amount];
        }
        int res = 1e9;
        for(int coin : coins)
        {
            if(amount - coin >= 0)
            {
                 res = min(res,1 + dfs(coins,amount - coin));
            }
        }
       return memo[amount] = res;
    }
};
