#include <bits/extc++.h>
using namespace std;
#define ever ;;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, cnt = 0;
    cin >> n >> m;
    queue<int> q;
    vector<tuple<int, int, int>> edge(m);
    vector<vector<int>> G(n + 1);
    vector<bool> visited(n + 1);
    vector<int64_t> dist(n + 1, 1e18 + 87);
    dist[1] = 0;
    for (auto &[u, v, w] : edge)
    {
        cin >> u >> v >> w;
        w = -w;
        G[u].emplace_back(v);
    }
    for (int i = 0; i < n; i++)
        for (auto const [u, v, w] : edge)
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
    q.emplace(1);
    while (q.size())
    {
        auto cur = q.front();
        q.pop();
        if (visited[cur])
            continue;
        visited[cur] = true;
        for (auto v : G[cur])
            q.emplace(v);
    }
    for (int i = 0; i < n; i++)
        for (auto const [u, v, w] : edge)
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                if (visited[v])
                    q.emplace(v);
            }
    visited.assign(n + 1, false);
    while (q.size())
    {
        auto cur = q.front();
        q.pop();
        if (cur == n)
        {
            cout << "-1\n";
            return 0;
        }
        if (visited[cur])
            continue;
        visited[cur] = true;
        for (auto v : G[cur])
            q.emplace(v);
    }
    cout << -dist[n] << '\n';

    return 0;
}