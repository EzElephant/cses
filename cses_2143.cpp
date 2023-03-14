#include <bits/extc++.h>
using namespace std;
const int MAXN = 5e4 + 87;
int c, t; // 新圖的點數
bitset<MAXN> dp[MAXN];
vector<int> G[MAXN], nG[MAXN];
int low[MAXN], deep[MAXN], table[MAXN];
bool visited[MAXN], inst[MAXN];
stack<int> st;

void tarjan(int u)
{
    visited[u] = true;
    low[u] = deep[u] = ++t;
    st.push(u);
    inst[u] = true;
    for (auto v : G[u])
    {
        if (!visited[v])
        {
            tarjan(v);
        }
        if (inst[v])
        {
            low[u] = min(low[u], low[v]);
        }
    }
    if (deep[u] == low[u])
    {
        c++;
        int v;
        do
        {
            v = st.top();
            st.pop();
            inst[v] = false;
            table[v] = c;
        } while (v != u);
    }
    return;
}

void dfs(int u)
{
    visited[u] = true;
    dp[u].set(u);
    for (auto v : nG[u])
    {
        if (!visited[v])
            dfs(v);
        dp[u] |= dp[v];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        G[u - 1].emplace_back(v - 1);
    }

    // 縮點
    for (int i = 0; i < n; i++)
        if (!visited[i])
            tarjan(i);

    // 建新的圖
    for (int u = 0; u < n; u++)
        for (auto v : G[u])
            if (table[u] != table[v])
                nG[table[u]].emplace_back(table[v]);
    for (int i = 1; i <= c; i++)
    {
        sort(nG[i].begin(), nG[i].end());
        nG[i].resize(unique(nG[i].begin(), nG[i].end()) - nG[i].begin());
    }

    for (int i = 1; i <= c; i++)
        visited[i] = false;
    for (int i = 1; i <= c; i++)
        if (!visited[i])
            dfs(i);

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u = table[u - 1], v = table[v - 1];
        if (u == v || dp[u].test(v))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}