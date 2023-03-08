#include <bits/extc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll mx = -87;
    cin >> n;
    vector<tuple<ll, ll, ll>> p(n);
    for (auto &[b, a, w] : p)
        cin >> a >> b >> w;
    sort(p.begin(), p.end());

    map<ll, ll> dp;
    dp[0] = 0;
    for (auto const [b, a, w] : p)
    {
        auto it = dp.lower_bound(a);
        it--;
        mx = max(mx, it->second + w);
        dp[b] = mx;
    }
    cout << mx << '\n';

    return 0;
}