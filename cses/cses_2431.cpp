#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long q, cnt, n, base, tmp, ans, total, before;
    cin >> q;
    while (q--)
    {
        cin >> n;
        if (n < 10)
        {
            cout << n << "\n";
            continue;
        }
        total = 0 ,base = 0, cnt = 0;
        while (n > total)
        {
            base = base * 10 + 9;
            cnt++;
            before = total;
            total = total + cnt * 9 * pow(10, cnt - 1);
        }
        n -= before;
        tmp = ceil(n / double(cnt));
        ans = pow(10, cnt - 1) + tmp - 1;
        tmp = n % cnt;
        if (tmp == 0)
            cout << ans % 10;
        else
        {
            string num = to_string(ans);
            cout << num[tmp - 1];
        }
        cout << "\n";
    }
    return 0;
}