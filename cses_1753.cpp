#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    // KMP-algorithm
    string str, tar;
    cin >> str >> tar;
    vector<int> next(1, 0);
    int pre = 0; // 共同前後綴長度
    // 算next陣列
    for (int i = 1; i < tar.size();)
    {
        if (tar[pre] == tar[i])
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
            {
                pre = next[pre - 1];
            }
        }
    }

    // 字串比對
    for (int i = 0, j = 0; i < str.size();)
    {
        if (str[i] == tar[j])
            i++, j++;
        else if (j > 0)
            j = next[j - 1];
        else
            i++;
        if (j == tar.size())
        {
            cnt++;
            j = next[j - 1];
        }
    }
    cout << cnt << '\n';

    return 0;
}