#include <bits/extc++.h>
using namespace std;
#define MAXN 1000087
typedef long long ll;
const ll MOD = 1e9 + 7;
ll fac[MAXN], inv[MAXN], fac_inv[MAXN];

void init()
{
    fac[0] = fac[1] = 1, inv[0] = inv[1] = 1, fac_inv[0] = fac_inv[1] = 1;

    for (ll i = 2; i < MAXN; i++)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = MOD - (MOD / i * inv[MOD % i]) % MOD;
        fac_inv[i] = (fac_inv[i - 1] * inv[i]) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << (((fac[n] * fac_inv[k]) % MOD) * fac_inv[n - k]) % MOD << '\n';
    }

    return 0;
}