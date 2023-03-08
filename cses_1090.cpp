#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, ans = 0;
    cin >> n >> x;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);
    for (int i = 0, j = n - 1; i <= j;)
    {
        if (p[i] + p[j] <= x)
            i++;
        j--;
        ans++;
    }
    cout << ans << "\n";

    return 0;
}