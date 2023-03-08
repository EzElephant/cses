#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (abs(a[i] - b[j]) <= k)
            i++, j++, ans++;
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    cout << ans << '\n';

    return 0;
}