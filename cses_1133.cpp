#include <bits/extc++.h>
using namespace std;
int n;
vector<vector<int>> G;
vector<int64_t> ans, sz;

void dfs(int cur, int pre, int step)
{
    ans[1] += step;
    for (auto v : G[cur])
    {
        if (v == pre)
            continue;
        dfs(v, cur, step + 1);
        sz[cur] += sz[v];
    }
    sz[cur]++;
}

void find(int cur, int pre)
{
    for (auto v : G[cur])
    {
        if (v == pre)
            continue;
        ans[v] = ans[cur] + (n - 2LL * sz[v]);
        find(v, cur);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    G.resize(n + 1), ans.resize(n + 1), sz.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, -87, 0);
    find(1, -87);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}