#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, tmp;
    multiset<int> h;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        h.insert(tmp);
    }

    while (m--)
    {
        cin >> tmp;
        auto it = h.upper_bound(tmp);
        if (it == h.begin())
            cout << "-1\n";
        else
        {
            cout << *(--it) <<  "\n";
            h.erase(it);
        }
    }

    return 0;
}