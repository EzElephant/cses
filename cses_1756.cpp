#include <bits/extc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            cout << u << ' ' << v << '\n';
        else
            cout << v << ' ' << u << '\n';
    }

    return 0;
}