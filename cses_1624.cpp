#include <bits/extc++.h>
using namespace std;
int cnt, r[10];
bool occupy[10][10], c[10];

bool legal(int x, int y, int step)
{
    if (c[y])
        return false;
    if (occupy[x][y])
        return false;
    for (int i = 0; i < step; i++)
    {
        if (abs(r[i] - y) == abs(i - x))
            return false;
    }
    return true;
}

void dfs(int step)
{
    if (step == 8)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 8; i++)
        if (legal(step, i, step))
        {
            r[step] = i;
            c[i] = true;
            dfs(step + 1);
            r[step] = 0;
            c[i] = false;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char ch;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> ch;
            if (ch == '*')
                occupy[i][j] = true;
        }
    dfs(0);
    cout << cnt << '\n';

    return 0;
}
