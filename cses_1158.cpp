#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n), dp(x + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int j = 0; j < n; j++)
        for (int i = x; i >= h[i]; i--)
            if (i + h[j] <= x)
                dp[i] = max(dp[i], dp[i - h[j]] + s[j]);
    cout << dp[x] << "\n";

    return 0;
}