#include <bits/extc++.h>
using namespace std;
const int MAXN = 5e4 + 87;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1);
    vector<vector<int>> G(n + 1);
    vector<bitset<MAXN>> dp(n + 1);
    queue<int> q;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        G[v].emplace_back(u);
        in[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i].set(i);
        if (in[i] == 0)
            q.emplace(i);
    }
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        for (auto v : G[cur])
        {
            dp[v] |= dp[cur];
            in[v]--;
            if (in[v] == 0)
                q.emplace(v);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i].count() << ' ';
    cout << '\n';

    return 0;
}