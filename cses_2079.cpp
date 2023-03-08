#include <bits/extc++.h>
using namespace std;
int n, ans;
vector<vector<int>> G;
vector<int> sz;

void dfs(int cur, int pre)
{
    sz[cur] = 1;
    int mx = -87;
    for (auto v : G[cur])
    {
        if (v == pre)
            continue;
        dfs(v, cur);
        sz[cur] += sz[v];
        mx = max(sz[v], mx);
    }
    mx = max(n - sz[cur], mx);
    if (mx <= n / 2)
        ans = cur;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    G.resize(n + 1), sz.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, -87);
    cout << ans << '\n';

    return 0;
}