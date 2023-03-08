#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> prime;
void init()
{
    int sqrt_1087 = sqrt(1087);
    vector<bool> sieve(1087, false);
    sieve[0] = sieve[1] = true;
    for (int i = 2; i <= sqrt_1087; i++)
        if (!sieve[i])
            for (int k = (1087 - 1) / i, j = i * k; k >= i; k--, j -= i)
                if (!sieve[k])
                    sieve[j] = true;
    for (int i = 2; i < 1087; i++)
        if (!sieve[i])
            prime.emplace_back(i);
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
        int n, ans = 1;
        cin >> n;
        for (int i = 0; n != 1 && prime[i] < 1000; i++)
        {
            int tmp = 1;
            while (n % prime[i] == 0)
            {
                n /= prime[i];
                tmp++;
            }
            ans *= tmp;
        }
        if (n != 1)
            ans *= 2;
        cout << ans << '\n';
    }

    return 0;
}