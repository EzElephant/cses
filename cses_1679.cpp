#include <bits/extc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<bool> visited(n + 1);
    vector<int> deg(n + 1), ans;
    vector<vector<int>> G(n + 1);
    queue<int> q;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        deg[v]++;
        G[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.emplace(i);
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        ans.emplace_back(u);
        for (auto v : G[u])
        {
            deg[v]--;
            if (deg[v] == 0)
                q.emplace(v);
        }
    }
    if (ans.size() == n)
        for (auto v : ans)
            cout << v << ' ';
    else
        cout << "IMPOSSIBLE";
    cout << '\n';

    return 0;
}