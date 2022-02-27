#include <iostream>
#include <cstring>
using namespace std;
int c[1000087], dp[1000087];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        for (int j = 0; j + c[i] <= x; j++)
            dp[j + c[i]] = min(dp[j + c[i]], dp[j] + 1);
    }
    if (dp[x] > x)
        cout << "-1\n";
    else
        cout << dp[x] << "\n";
        
    return 0;
}