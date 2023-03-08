#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> c(n), dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    dp[0] = 1;
    for (int i = 0; i < x; i++)
        for (auto coin : c)
            if (i + coin <= x)
            {
                dp[i + coin] += dp[i];
                dp[i + coin] %= MOD;
            }
    cout << dp[x] << "\n";

    return 0;
}