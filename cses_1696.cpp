#include <bits/extc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> G;
vector<int> match;
vector<bool> visited;

bool dfs(int u)
{
    for (int v : G[u])
    {
        if (visited[v])
            continue;
        visited[v] = true;
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int konig()
{
    match.assign(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        visited.assign(n + 1, false);
        if (dfs(i))
            ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    G.resize(m + 1);
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        G[v].emplace_back(u);
    }
    cout << konig() << '\n';
    for (int i = 1; i <= n; i++)
        if (match[i] != 0)
            cout << i << ' ' << match[i] << '\n';

    return 0;
}