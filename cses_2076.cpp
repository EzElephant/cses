#include <bits/extc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> visited;
vector<int> deep, low;
vector<pair<int, int>> ans;

void dfs(int u = 0, int pre = -1, int depth = 1)
{
    visited[u] = true;
    low[u] = deep[u] = depth;
    int child = 0;
    for (auto v : G[u])
    {
        if (v == pre)
            continue;
        if (!visited[v])
        {
            dfs(v, u, depth + 1);
            low[u] = min(low[u], low[v]);
            if (low[v] > deep[u])
            {
                ans.emplace_back(u, v);
            }
        }
        else if (deep[v] < deep[u])
            low[u] = min(low[u], deep[v]);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    G.resize(n), visited.resize(n), deep.resize(n), low.resize(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs();
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << u + 1 << ' ' << v + 1 << '\n';

    return 0;
}