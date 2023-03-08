#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> ans(n, 0);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = -i;
    }
    sort(a.begin(), a.end());
    for (auto [u, v] : a)
    {
        auto it = s.upper_bound(v);
        if (it != s.end())
            ans[-v] = -(*it) + 1;
        s.emplace(v);
    }
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
    
    return 0;
}