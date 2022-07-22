#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, mid;
    int64_t ans = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    if (n & 1)
        mid = a[n / 2];
    else
        mid = (a[n / 2] + a[n / 2]) >> 1;
    for (auto x : a)
        ans += (abs(x - mid));
    cout << ans << '\n';

    return 0;
}