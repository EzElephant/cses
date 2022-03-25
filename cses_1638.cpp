#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> g(n);
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++)
        cin >> g[i];

    if (g[0][0] == '.')
        dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i - 1 >= 0 && g[i][j] == '.')
                dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
            if (j - 1 >= 0 && g[i][j] == '.')
                dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}