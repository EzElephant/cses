#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int MAXN = 200087;
vector<ll> x(MAXN), seg(4 * MAXN), tag_increase(4 * MAXN), tag_set(4 * MAXN);

void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        seg[id] = x[r];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    seg[id] = seg[2 * id] + seg[2 * id + 1];
}

void push(ll id, ll l, ll r)
{
    if (tag_set[id] > 0)
    {
        seg[id] = (r - l + 1) * tag_set[id];
        if (l != r)
        {
            tag_set[2 * id] = tag_set[id];
            tag_increase[2 * id] = 0;
            tag_set[2 * id + 1] = tag_set[id];
            tag_increase[2 * id + 1] = 0;
        }
        tag_set[id] = 0;
    }
    if (tag_increase[id] > 0)
    {
        seg[id] += (r - l + 1) * tag_increase[id];
        if (l != r)
        {
            tag_increase[2 * id] += tag_increase[id];
            tag_increase[2 * id + 1] += tag_increase[id];
        }
        tag_increase[id] = 0; 
    }
}

void modify_increase(ll id, ll l, ll r, ll ql, ll qr, ll x)
{
    push(id, l, r);
    if (r < ql || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        tag_increase[id] += x;
        push(id, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    modify_increase(2 * id, l, mid, ql, qr, x);
    modify_increase(2 * id + 1, mid + 1, r, ql, qr, x);
}

void modify_set(ll id, ll l, ll r, ll ql, ll qr, ll x)
{
    push(id, l, r);
    if (r < ql || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        tag_set[id] = x;
        push(id, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    modify_set(2 * id, l, mid, ql, qr, x);
    modify_set(2 * id + 1, mid + 1, r, ql, qr, x);
}

ll query(ll id, ll l, ll r, ll ql, ll qr)
{
    push(id, l, r);
    if (r < ql || l > qr)
        return 0;
    if (ql <= l && r <= qr)
        return seg[id];
    ll mid = (l + r) / 2;
    return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q, a, b, u, op;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    build(1, 1, n);
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> a >> b >> u;
            modify_increase(1, 1, n, a, b, u);
        }
        else if (op == 2)
        {
            cin >> a >> b >> u;
            modify_set(1, 1, n, a, b, u);
        }
        else
        {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}