#include <bits/extc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 103;
ll G[MAXN][MAXN], ans[MAXN][MAXN], n, m, k;

void mul()
{
    ll tmp[MAXN][MAXN];
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            tmp[i][j] = 0;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (long long k = 0; k < MAXN; k++)
                tmp[i][j] = (tmp[i][j] + (1LL * G[i][k] * ans[k][j]) % MOD) % MOD;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            ans[i][j] = tmp[i][j];
}

void square()
{
    ll tmp[MAXN][MAXN];
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            tmp[i][j] = 0;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (long long k = 0; k < MAXN; k++)
                tmp[i][j] = (tmp[i][j] + (1LL * G[i][k] * G[k][j]) % MOD) % MOD;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            G[i][j] = tmp[i][j];
}

void fastp()
{
    for (int i = 0; i < n; i++)
        ans[i][i] = 1;
    while (k)
    {
        if (k & 1)
            mul();
        square();
        k >>= 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u][v]++;
    }
    fastp();
    cout << ans[0][n - 1] << '\n';

    return 0;
}
