#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
constexpr int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, tmp, a[187], b[187], *cur, *next;
    cur = a, next = b;
    cin >> n >> m;
    for (int i = 0; i < 120; i++)
        a[i] = 0, b[i] = 0;
    cin >> tmp;
    if (tmp == 0)
        for (int i = 1; i <= m; i++)
            cur[i] = 1;
    else
        cur[tmp] = 1;
    n--;
    while (n--)
    {
        cin >> tmp;
        for (int i = 0; i < 120; i++)
            next[i] = 0;
        if (tmp == 0)
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i + j == 0 || i + j > m)
                        continue;
                    next[i + j] += cur[i];
                    next[i + j] %= MOD;
                }
            }
        }
        else
        {
            for (int i = -1; i < 2; i++)
            {
                if (tmp + i == 0 || tmp + i > m)
                    continue;
                next[tmp] += cur[tmp + i];
                next[tmp] %= MOD;
            }
        }
        swap(cur, next);
    }
    tmp = 0;
    for (int i = 1; i <= m; i++)
    {
        tmp += cur[i];
        tmp %= MOD;
    }
    cout << tmp << '\n';

    return 0;
}