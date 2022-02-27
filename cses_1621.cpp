#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp, ans = 0, before;
    cin >> n;
    set<int> x;

    while (n--)
    {
        cin >> tmp;
        before = x.size();
        x.emplace(tmp);
        if (x.size() != before)
            ans++;
    }
    cout << ans << "\n";
    
    return 0;
}