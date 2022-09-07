#include <iostream>
#include <vector>
using namespace std;
vector<int64_t> a, pre;
vector<vector<int64_t>> dp;

int64_t sum(int l, int r)
{
    return l == 0 ? pre[r] : pre[r] - pre[l - 1];
}

int64_t dfs(int l, int r)
{
    if (dp[l][r] != -1e18)
        return dp[l][r];
    // base case
    if (r - l == 1)
        return dp[l][r] = max(a[l], a[r]);

    // recursive step
    return dp[l][r] = max(a[l] + sum(l + 1, r) - dfs(l + 1, r), a[r] + sum(l, r - 1) - dfs(l, r - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    a.resize(n), pre.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++)
        dp[i].resize(n, -1e18);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i] = a[i];
        if (i == 0)
            continue;
        pre[i] += pre[i - 1];
    }
    cout << dfs(0, n - 1) << '\n';

    return 0;
}