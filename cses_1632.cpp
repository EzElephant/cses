#include <bits/extc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, cnt = 0;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    multiset<int> ms;
    for (auto &x : a)
        cin >> x.second >> x.first;
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++)
        ms.insert(0);
    for (auto x : a)
    {
        auto it = ms.upper_bound(x.second);
        if (it == ms.begin())
            continue;
        --it;
        ms.erase(it);
        ms.insert(x.first);
        ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}