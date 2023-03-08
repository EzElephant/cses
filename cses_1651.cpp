#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int MAXN = 200087;
vector<ll> x(MAXN), seg(4 * MAXN), tag(4 * MAXN);
 
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
}
 
void push(ll id, ll l, ll r)
{
    if (l == r)
        seg[id] += tag[id];
    if (l != r)
    {
        tag[2 * id] += tag[id];
        tag[2 * id + 1] += tag[id];
    }
    tag[id] = 0;
}
 
void modify(ll id, ll l, ll r, ll ql, ll qr, ll x)
{
    push(id, l, r);
    if (r < ql || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        tag[id] += x;
        push(id, l, r);
        return;
    }
    ll mid = (l + r) / 2;
    modify(2 * id, l, mid, ql, qr, x);
    modify(2 * id + 1, mid + 1, r, ql, qr, x);
}
 
ll query(ll id, ll l, ll r, ll ql, ll qr)
{
    push(id, l, r);
    if (r < ql || l > qr)
        return -1;
    if (ql <= l && r <= qr)
        return seg[id];
    ll mid = (l + r) / 2;
    return max(query(2 * id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
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
            modify(1, 1, n, a, b, u);
        }
        else
        {
            cin >> u;
            cout << query(1, 1, n, u, u) << "\n";
        }
    }
 
    return 0;
}