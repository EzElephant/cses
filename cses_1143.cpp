#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 200087;
vector<int> x(MAXN), seg(4 * MAXN);
int tmp;

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
    seg[id] = max(seg[2 * id], seg[2 * id + 1]);
}

int query(int id, int l, int r, int tar)
{
    if (seg[id] < tar)
        return 0;
    if (l == r)
    {
        seg[id] -= tar;
        return l;
    }
    int mid = (l + r) / 2;
    if (seg[2 * id] >= tar)
    {
        tmp = query(2 * id, l, mid, tar);
        seg[id] = max(seg[2 * id], seg[2 * id + 1]);
        return tmp;
    }
    else
    {
        tmp = query(2 * id + 1, mid + 1, r, tar);
        seg[id] = max(seg[2 * id], seg[2 * id + 1]);
        return tmp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, a;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    build(1, 1, n);
    while (q--)
    {
        cin >> a;
        cout << query(1, 1, n, a) << " ";
    }
    cout << "\n";

    return 0;
}