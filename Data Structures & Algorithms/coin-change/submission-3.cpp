// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int mincoins = dfs(coins,amount);
//         return (mincoins >= 1e9)? -1:mincoins;
//     }

//     private:
//     int dfs(vector<int>& coins,int amount)
//     {
//         if(amount == 0)
//         {
//             return 0;
//         }
//         int res = 1e9;
//         for(int coin : coins)
//         {
//             if(amount - coin >= 0)
//             {
//                  res = min(res,1 + dfs(coins,amount - coin));
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        int res = 1e9;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = min(res,
                      1 + dfs(coins, amount - coin));
            }
        }
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
};