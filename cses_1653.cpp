#include <bits/extc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tar;
    cin >> n >> tar;
    vector<int> a(n);
    vector<pair<int, int>> dp(1 << n, {1e9 + 87, 1e9 + 87});
    for (auto &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    dp[0] = {1, 0};
    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                int prev = i ^ (1 << j);
                if (dp[prev].second + a[j] <= tar)
                {
                    if ((dp[prev].first < dp[i].first) || 
                    ((dp[prev].first == dp[i].first) && dp[prev].second + a[j] < dp[i].second))
                    {
                        dp[i] = {dp[prev].first, dp[prev].second + a[j]};
                    }
                }
                else
                {
                    if ((dp[prev].first + 1 < dp[i].first) || 
                    ((dp[prev].first + 1 == dp[i].first) && dp[prev].second + a[j] < dp[i].second))
                    {
                        dp[i] = {dp[prev].first + 1, a[j]};
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first << '\n';

    return 0;
}