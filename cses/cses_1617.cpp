#include <iostream>
using namespace std;
const long long MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, base = 2, ans = 1;
    cin >> n;
    while (n)
    {
        if (n & 1)
            ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        n>>=1;
    }
    cout << ans << "\n";

    return 0;
}