#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t n;
    cin >> n;
    int64_t tmp = ((1 + n) * n) >> 1;
    if (tmp & 1)
        cout << "NO\n";
    else
    {
        tmp >>= 1;
        vector<bool> a(n + 1, false);
        int cnt = 0;
        for (int i = n; i > 0; i--)
        {
            if (i <= tmp)
            {
                cnt++;
                a[i] = true;
                tmp -= i;
            }
        }
        cout << "YES\n";
        cout << cnt << '\n';
        for (int i = 1; i <= n; i++)
            if (a[i])
                cout << i << ' ';
        cout << '\n' << n - cnt << '\n';
        for (int i = 1; i <= n; i++)
            if (!a[i])
                cout << i << ' ';
        cout << '\n';
    }

    return 0;
}