#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
int64_t power(int64_t a, int64_t b, int64_t mod)
{
    int64_t result = 1;
    while (b)
    {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int64_t a, b, c;
        cin >> a >> b >> c;
        cout << power(a, power(b, c, MOD - 1), MOD) << '\n';
    }

    return 0;
}