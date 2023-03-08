#include <bits/extc++.h>
using namespace std;
bool visited[1000087];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, ans = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (visited[i])
                    ans = max(ans, i);
                else
                    visited[i] = true;
                if (visited[n / i])
                    ans = max(ans, n / i);
                else
                    visited[n / i] = true;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}