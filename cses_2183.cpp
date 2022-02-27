#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> x(n);
    long long ans = 1;

    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x.begin(), x.end());

    for (auto i : x)
    {
        if (ans < i)
            break;
        else
            ans += i;
    }
    cout << ans << "\n";
    
    return 0;
}