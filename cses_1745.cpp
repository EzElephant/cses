#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAXN = 100000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp, ans = 0;
    cin >> n;
    vector<int> money(n);
    vector<vector<bool>> dp(n, vector<bool>(MAXN + 87, false));
    for (auto &x : money)
        cin >> x;
    dp[0][money[0]] = true, dp[0][0] = true;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < MAXN + 1; j++)
            if (dp[i - 1][j] == true || (j - money[i] >= 0 && dp[i - 1][j - money[i]] == true))
                dp[i][j] = true;

    for (int i = 1; i < MAXN + 1; i++)
        if (dp[n - 1][i] == true)
            ans++;
    cout << ans << '\n';
    for (int i = 1; i < MAXN + 1; i++)
        if (dp[n - 1][i] == true)
            cout << i << ' ';
    cout << '\n';

    return 0;
}