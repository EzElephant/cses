#include <bits/extc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x2 -= x1, y2 -= y1; // p1p2
    x3 -= x1, y3 -= y1; // p1p3
    ll tmp = x2 * y3 - y2 * x3;
    if (tmp < 0)
        cout << "RIGHT\n";
    else if (tmp > 0)
        cout << "LEFT\n";
    else
        cout << "TOUCH\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}