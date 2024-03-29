#include <bits/extc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 0; i <= a.size(); i++)
        dp[i][0] = i;
    for (int i = 0; i <= b.size(); i++)
        dp[0][i] = i;
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    cout << dp[a.size()][b.size()] << '\n';

    return 0;
}