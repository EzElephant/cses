#include <bits/extc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int64_t mul(int64_t a, int64_t b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t n, sum = 0;
    cin >> n;
    for (int64_t i = 1; i <= n;)
    {
        int64_t base = n / i;
        int64_t last = n / base;
        sum = (sum + base * mul(mul(last - i + 1, i + last), 500000004)) % MOD;
        i = last + 1;
    }
    cout << sum << '\n';

    return 0;
}