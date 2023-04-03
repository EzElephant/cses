#include <bits/extc++.h>
using namespace std;
const int MAXN = 2e5 + 87;
int seg[4 * MAXN], x[MAXN], n, cnt = 1;
vector<vector<int>> G;
vector<int> sz, h_child, parent, level;
vector<int> top, idx;
 
int query(int id, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return seg[id];
    int mid = (l + r) / 2;
    return max(query(2 * id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
}
 
void modify(int id, int l, int r, int target, int value)
{
    if (l == r)
    {
        seg[id] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (target <= mid)
        modify(2 * id, l, mid, target, value);
    else
        modify(2 * id + 1, mid + 1, r, target, value);
    seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}
 
void find_h_child(int u, int d)
{
    level[u] = d;
    sz[u] = 1;
    h_child[u] = -1;
    for (auto v : G[u])
    {
        if (v == parent[u])
            continue;
        parent[v] = u;
        find_h_child(v, d + 1);
        if (h_child[u] == -1 || sz[v] > sz[h_child[u]])
            h_child[u] = v;
        sz[u] += sz[v];
    }
}
 
void build_link(int u, int link_top)
{
    idx[u] = cnt++;
    top[u] = link_top;
    modify(1, 1, n, idx[u], x[u]);
    if (h_child[u] == -1)
        return;
    build_link(h_child[u], link_top);
    for (auto v : G[u])
    {
        if (v == parent[u] || v == h_child[u])
            continue;
        build_link(v, v);
    }
}
 
int get(int a, int b)
{
    int ta = top[a], tb = top[b], mx = 0;
    while (ta != tb)
    {
        if (level[ta] < level[tb])
        {
            mx = max(mx, query(1, 1, n, idx[tb], idx[b]));
            b = parent[tb];
            tb = top[b];
        }
        else
        {
            mx = max(mx, query(1, 1, n, idx[ta], idx[a]));
            a = parent[ta];
            ta = top[a];
        }
    }
    if (level[a] > level[b])
        swap(a, b);
    mx = max(max(mx, query(1, 1, n, idx[a], idx[b])), 0);
    return mx;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int q;
    cin >> n >> q;
    G.resize(n + 1);
    sz.resize(n + 1), h_child.resize(n + 1), parent.resize(n + 1), level.resize(n + 1);
    top.resize(n + 1), idx.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    find_h_child(1, 0);
    build_link(1, 1);
    while (q--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            x[a] = b;
            modify(1, 1, n, idx[a], x[a]);
        }
        else
            cout << get(a, b) << ' ';
    }
 
    return 0;
}