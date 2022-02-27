#include <iostream>
#define lowbit(a) a & -a
typedef long long ll;
using namespace std;
ll n, q, op, a, b, x[200087], seg[800087];

void init(ll id, ll l, ll r)
{
    if (l == r)
    {
        seg[id] = x[l];
        return;
    }
    ll mid = (l+r) / 2;
    init(2 * id, l, mid);
    init(2 * id + 1, mid + 1, r);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
    return;
}

ll query(ll id, ll l, ll r, ll ql, ll qr)
{
    if (r < ql || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return seg[id];
    ll mid = (l+r) / 2;
    return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
}

void modify(ll id, ll l, ll r, ll target, ll value)
{
    if (l == r)
    {
        seg[id] = value;
        return;
    }
    ll mid = (l+r) / 2;
    if (target <= mid)
        modify(2 * id, l, mid, target, value);
    else
        modify(2 * id + 1, mid + 1, r, target, value);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> x[i];
    init(1, 1, n);

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