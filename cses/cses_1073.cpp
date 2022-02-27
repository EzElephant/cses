#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    multiset<int> k;
    int n, tmp, ans = 0;
    cin >> n;

    while (n--)
    {
        cin >> tmp;
        if (!k.empty() && k.upper_bound(tmp) != k.end())
        {
            k.erase(k.upper_bound(tmp));
            k.insert(tmp);
        }
        else
        {
            k.insert(tmp);
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}