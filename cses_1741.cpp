#include <bits/extc++.h>
using namespace std;
typedef long long ll;
const ll shift = 1000001;
const int MAXN = 2000001;

ll cnt[4 * MAXN], sum[4 * MAXN];

void modify(int id, int l, int r, int ql, int qr, int x)
{
    if (r < ql || l > qr)
        return;
    if (ql <= l && r <= qr)
    {
        cnt[id] += x;
        if (cnt[id])
            sum[id] = r - l + 1;
        else if (l < r)
            sum[id] = sum[2 * id] + sum[2 * id + 1];
        else
            sum[id] = 0;
        return;
    }
    int mid = (l + r) / 2;
    modify(2 * id, l, mid, ql, qr, x);
    modify(2 * id + 1, mid + 1, r, ql, qr, x);
    if (cnt[id])
        sum[id] = r - l + 1;
    else
        sum[id] = sum[2 * id] + sum[2 * id + 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll result = 0;
    cin >> n;
    vector<tuple<int, int, int, int>> line;
    while (n--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line.emplace_back(x1, 1, y1 + shift, y2 + shift);
        line.emplace_back(x2, -1, y1 + shift, y2 + shift);
    }
    sort(line.begin(), line.end());
    ll pre = 0;
    for (auto [x, val, y1, y2] : line)
    {
        result += 1LL * (x - pre) * sum[1];
        modify(1, 1, MAXN, y1, y2 - 1, val);
        pre = x;
    }
    cout << result << '\n';

    return 0;
}