#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, a, b;
    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        if (a & 1 == b & 1)
        {
            cout << "NO\n";
            continue;
        }
        if (a < b) swap(a, b);
        if (a > 2 * b)
            cout << "NO\n";
        else
        {
            a %= 3, b %= 3;
            if ((a == 0 && b == 0) || (a == 2 && b == 1) || (a == 1 && b == 2))
            cout << "YES\n";
            else
            cout << "NO\n";
        }
    }

    return 0;
}