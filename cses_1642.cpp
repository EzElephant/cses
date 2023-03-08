#include <bits/extc++.h>
using namespace std;
int64_t n, x;
vector<pair<int64_t, int64_t>> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int64_t tar = x - a[i].first - a[j].first;
            for (int l = j + 1, r = n - 1; l < r;)
            {
                if (a[l].first + a[r].first > tar)
                    r--;
                else if (a[l].first + a[r].first < tar)
                    l++;
                else
                {
                    cout << a[i].second << " " << a[j].second << " " << a[l].second  << " " << a[r].second << '\n';
                    return 0;
                }
            }
        }
    cout << "IMPOSSIBLE\n";

    return 0;
}