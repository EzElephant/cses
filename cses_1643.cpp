#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int64_t ans;
    cin >> n;
    vector<int64_t> dp(n);
    cin >> dp[0];
    ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        cin >> dp[i];
        dp[i] = max(dp[i], dp[i-1] + dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';

    return 0;
}