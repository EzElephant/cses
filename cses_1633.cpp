#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i + j <= n)
                dp[i + j] = (dp[i + j] + dp[i]) % MOD;
            else
                break;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}