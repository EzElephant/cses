#include <bits/extc++.h>
using namespace std;
vector<int> parent;

int find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void un(int x, int y)
{
    parent[find(x)] = parent[find(y)];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, cnt = 0;
    int64_t cost = 0;
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    vector<tuple<int, int, int>> edge(m);
    for (auto &[w, u, v] : edge)
        cin >> u >> v >> w;
    sort(edge.begin(), edge.end());
    for (auto const [w, u, v] : edge)
    {
        if (find(u) == find(v))
            continue;
        else
        {
            un(u, v);
            cost += w;
            cnt++;
        }
    }
    if (cnt == n - 1)
        cout << cost << '\n';
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}