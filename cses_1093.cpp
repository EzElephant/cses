#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, sum;
    cin >> n;
    sum = (n * (n + 1)) >> 1;
    if (sum & 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    sum >>= 1;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] += dp[i - 1][j]; // not include i
            dp[i][j] %= MOD;
            if (j >= i)
            {
                dp[i][j] += dp[i - 1][j - i]; // include i
                dp[i][j] %= MOD;
            }
        }
    }
    // mod devide 2
    int base = (MOD + 1) >> 1, ans = 0, tmp = dp[n][sum];
    while (base)
    {
        if (base & 1)
            ans = (ans + tmp) % MOD;
        tmp = (tmp << 1) % MOD;
        base >>= 1;
    }
    cout << ans << '\n';

    return 0;
}