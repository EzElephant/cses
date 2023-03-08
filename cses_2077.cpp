#include <bits/extc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> visited, flag;
vector<int> deep, low, ans;
stack<int> st;

void dfs(int u = 0, int pre = -1, int depth = 1)
{
    visited[u] = true;
    low[u] = deep[u] = depth;
    st.push(u);
    int child = 0;
    for (auto v : G[u])
    {
        if (v == pre)
            continue;
        if (!visited[v])
        {
            dfs(v, u, depth + 1);
            low[u] = min(low[u], low[v]);
            if (deep[u] <= low[v] && pre != -1 && !flag[u])
            {
                ans.emplace_back(u);
                flag[u] = true;
            }
            child++;
        }
        else if (deep[v] < deep[u])
            low[u] = min(low[u], deep[v]);
    }

    if (pre == -1 && child > 1 && !flag[u])
    {
        ans.emplace_back(u);
        flag[u] = true;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    G.resize(n), visited.resize(n), deep.resize(n), low.resize(n), flag.resize(n);
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
    for (auto x : ans)
        cout << x + 1 << ' ';
    cout << '\n';

    return 0;
}