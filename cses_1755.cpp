#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
string str;
int m[256];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char tmp;
    int cnt = 0;
    while (cin >> tmp)
        m[tmp]++;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (m[i] & 1)
            cnt++;
    }
    if (cnt > 1)
        cout << "NO SOLUTION\n";
    else
    {
        for (int i = 'A'; i <= 'Z'; i++)
        {
            for (int j = m[i] / 2; j > 0; j--)
                cout << char(i);
        }
        for (int i = 'A'; i <= 'Z'; i++)
            if (m[i] & 1)
                cout << char(i);
        for (int i = 'Z'; i >= 'A'; i--)
        {
            for (int j = m[i] / 2; j > 0; j--)
                cout << char(i);
        }
    }

    return 0;
}