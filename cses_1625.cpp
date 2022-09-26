#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/extc++.h>
using namespace std;
const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
queue<pair<int, int>> q;
string buffer;
int ans;
bool grid[9][9];

// bool legal(int x, int y)
// {
//     grid[x][y] = true;

//     bool visited[7][7], result = true;
//     for (int i = 0; i < 7; i++)
//         for (int j = 0; j < 7; j++)
//             visited[i][j] = grid[i][j];
//     q.emplace(6, 0);
//     visited[6][0] = true;
//     while (!q.empty())
//     {
//         auto tmp = q.front();
//         q.pop();
//         for (int d = 0; d < 4; d++)
//         {
//             int i = tmp.first + dir[d][0];
//             int j = tmp.second + dir[d][1];
//             if (i >= 0 && j >= 0 && i < 7 && j < 7 && !visited[i][j])
//             {
//                 q.emplace(i, j);
//                 visited[i][j] = true;
//             }
//         }
//     }
//     for (int i = 0; i < 7; i++)
//         for (int j = 0; j < 7; j++)
//             if (visited[i][j] == false)
//                 result = false;

//     grid[x][y] = false;
//     return result;
// }

bool legal(int x, int y)
{
    bool d, u, r, l;
    d = grid[x + 1][y];
    u = grid[x - 1][y];
    r = grid[x][y + 1];
    l = grid[x][y - 1];
    if ((d && u && !r && !l) || (!d && !u && r && l))
        return false;
    return true;
}

void dfs(int step, int x, int y)
{
    if (x == 7 && y == 1 && step < 48)
        return;
    if (step == 48)
    {
        ans++;
        return;
    }

    int s = 0;
    switch (buffer[step])
    {
    case 'D':
        s += 1 << 0;
        break;
    case 'U':
        s += 1 << 1;
        break;
    case 'R':
        s += 1 << 2;
        break;
    case 'L':
        s += 1 << 3;
        break;
    default:
        s += 15;
    }
    for (int d = 0; s; s ^= d)
    {
        d = s & -s;
        int i = x + dir[__lg(d)][0];
        int j = y + dir[__lg(d)][1];
        if (i > 0 && j > 0 && i <= 7 && j <= 7 && !grid[i][j] && legal(i, j))
        {
            grid[i][j] = true;
            dfs(step + 1, i, j);
            grid[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> buffer;
    for (int i = 0; i < 9; i++)
    {
        grid[i][8] = true;
        grid[i][0] = true;
        grid[0][i] = true;
        grid[8][i] = true;
    }
    grid[1][1] = true;
    dfs(0, 1, 1);
    cout << ans << '\n';

    return 0;
}