#include <bits/extc++.h>
using namespace std;
typedef long long ll;
struct Item
{
    ll sum, MCS, pre, post;
    Item(ll sum = 0) : sum(sum), MCS(max(sum, 0LL)), pre(max(sum, 0LL)), post(max(sum, 0LL)) {}
    friend Item operator+(const Item &L, const Item &R)
    {
        Item tmp(L.sum + R.sum);
        tmp.MCS = max({L.MCS, R.MCS, L.post + R.pre});
        tmp.post = max(R.post, L.post + R.sum);
        tmp.pre = max(L.pre, L.sum + R.pre);
        return tmp;
    }
};
vector<ll> a;
vector<Item> seg;

void build(int l, int r, int id)
{
    if (l == r)
    {
        seg[id] = Item(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, id * 2);
    build(mid + 1, r, id * 2 + 1);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
    return;
}

void modify(ll p, ll val,int l, int r, int id)
{
    if (p < l || p > r)
        return;
    if (l == r)
    {
        seg[id] = Item(val);
        return;
    }
    int mid = (l + r) / 2;
    modify(p, val,l, mid, id * 2);
    modify(p, val, mid + 1, r, id * 2 + 1);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    a.resize(n);
    seg.resize(4 * n + 87);
    for (auto &x : a)
        cin >> x;
    build(0, n - 1, 1);
    while (m--)
    {
        ll p, val;
        cin >> p >> val;
        modify(p - 1, val, 0, n - 1, 1);
        cout << seg[1].MCS << '\n';
    }

    return 0;
}