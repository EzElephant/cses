#include <bits/extc++.h>
using namespace std;
int n, k;
vector<int> a;

bool judge(int64_t sep)
{
    int cnt = 0;
    int64_t sum = 0;
    for (int x : a)
    {
        if (x > sep)
            return false;
        if (sum + x > sep)
        {
            cnt++;
            sum = 0;
        }
        sum += x;
    }
    if (sum != 0)
        cnt++;
    return cnt <= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t l = 0, r = 0, ans = 0;
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a)
    {
        cin >> x;
        r += x;
    }
    while (l <= r)
    {
        int64_t mid = (l + r) / 2;
        if (judge(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans << '\n';

    return 0;
}