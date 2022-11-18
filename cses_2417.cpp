#include <bits/extc++.h>
using namespace std;
int cnt[1000087];
bool nprime[1000087];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int64_t sum;
    cin >> n;
    sum = (n * (n - 1)) >> 1;
    while (n--)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    for (int i = 2; i <= 500000; i++)
    {
        if (!nprime[i])
        {
            int64_t tmp = 0;
            for (int j = 1; i * j <= 1000000; j++)
            {
                tmp += cnt[i * j];
                nprime[i *  j] = true;
            }
            sum -= ((tmp * (tmp - 1)) >> 1);
        }
    }
    cout << sum << '\n';

    return 0;
}