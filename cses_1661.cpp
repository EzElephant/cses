#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, x, sum = 0, ans = 0;
    map<ll, int> m;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    m[0] = 1;
    for (auto y : a)
    {
        sum += y;
        ans += m[sum - x];
        m[sum]++;
    }
    cout << ans << "\n";

    return 0;
}