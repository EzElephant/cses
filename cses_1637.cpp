#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    cin >> n;
    vector<int> dp(n + 1, 94879487);
    dp[n] = 0;
    for (int i = n; i > 0; i--)
    {
        tmp = i;
        while (tmp)
        {
            dp[i - tmp % 10] = min(dp[i] + 1, dp[i - tmp % 10]);
            tmp /= 10;
        }
    }
    cout << dp[0] << "\n";

    return 0;
}