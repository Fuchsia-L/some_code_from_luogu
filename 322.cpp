#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> ans(amount + 1, amount + 1);
        ans[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int e = i - coins[j];
                if (e >= 0)
                {
                    ans[i] = min(ans[i], ans[e] + 1);
                }
            }
        }
        if (ans[amount] > amount)
            return -1;
        return ans[amount];
    }
};
int main()
{
    vector<int> c = {1, 2, 5};
    Solution sol;
    cout << sol.coinChange(c, 11);
    return 0;
}