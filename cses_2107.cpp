#include <bits/extc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    vector<int> next(1, 0);
    int pre = 0;
    for (int i = 1; i < str.size();)
    {
        if (str[pre] == str[i])
        {
            pre++;
            i++;
            next.emplace_back(pre);
        }
        else
        {
            if (pre == 0)
            {
                next.emplace_back(0);
                i++;
            }
            else
                pre = next[pre - 1];
        }
    }

    int n = str.size(), l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++)
    {
        if (i <= r && i + z[i - l] - 1 < r)
            z[i] = z[i - l];
        else
        {
            z[i] = max(0, r - i + 1);
            while (str[z[i]] == str[i + z[i]])
                z[i]++;
            l = i, r = i + z[i] - 1;
        }
    }

    for (auto x : z)
        cout << x << ' ';
    cout << '\n';
    for (auto x : next)
        cout << x << ' ';
    cout << '\n';

    return 0;
}