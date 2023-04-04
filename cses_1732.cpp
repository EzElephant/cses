#include <bits/extc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int n = str.size(), l = 0, r = 0;
    vector<int> z(n), ans;
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
        if (z[i] == n - i)
            ans.push_back(n - i);
    }
    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << ' ';
    cout << '\n';

    return 0;
}