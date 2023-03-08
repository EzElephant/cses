#include <iostream>
const int MOD = 1e9 + 7;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int64_t a, b, ans = 1;
        cin >> a >> b;
        for (int64_t i = b, base = a; i > 0; i >>= 1, base = (base * base) % MOD)
        {
            if (i & 1)
                ans = (ans * base) % MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}