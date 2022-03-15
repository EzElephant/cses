#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 200087;
vector<int> x(MAXN), seg(4 * MAXN);

void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id] = x[r];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}

void modify(int id, int l, int r, int i, int x)
{
    if (l > i || r < i)
        return;
    if (l == r)
    {
        seg[id] = x;
        return;
    }
    int mid = (l + r) / 2;
    modify(2 * id, l, mid, i, x);
    modify(2 * id + 1, mid + 1, r, i, x);
    seg[id] = min(seg[2 * id], seg[2 * id + 1]);
}

int query(int id, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
        return 1e9 + 87;
    if (ql <= l && r <= qr)
        return seg[id];
    int mid = (l + r) / 2;
    return min(query(2 * id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, a, b, op;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    build(1, 1, n);
    while (q--)
    {
        cin >> op >> a >> b;
        if (op == 1)
            modify(1, 1, n, a, b);
        else
            cout << query(1, 1, n, a, b) << "\n";
    }

    return 0;
}