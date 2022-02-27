#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100087;
int n, m, a, b, repeat;
vector<int> G[MAXN], route;
bool visited[MAXN], flag;

bool dfs(int u, int pre)
{
    if (visited[u])
    {
        route.emplace_back(u);
        repeat = u;
        return true;
    }
    visited[u] = true;
    for (auto x : G[u])
    {
        if (x != pre && dfs(x, u))
        {
            if (!flag)
                route.emplace_back(u);
            if (repeat == u)
                flag = true;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, -87);
        if (repeat)
            break;
    }
    if (!repeat)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << route.size() << "\n";
        for (auto x : route)
            cout << x << " ";
    }

    return 0;
}