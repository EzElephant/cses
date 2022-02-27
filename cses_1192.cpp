#include <iostream>
#include <queue>
using namespace std;
char field[1087][1087];
bool visited[1087][1087];
int x, y, ans;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            cin >> field[i][j];
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            if (!visited[i][j] && field[i][j] == '.')
            {
                ans++;
                queue<pair<int, int>> q;
                pair<int, int> tmp;
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    tmp = q.front(), q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        visited[tmp.first][tmp.second] = true;
                        tmp.first += dir[k][0];
                        tmp.second += dir[k][1];
                        if (tmp.first < 0 || tmp.second < 0 || tmp.first >= x || tmp.second >= y);                 
                        else if (field[tmp.first][tmp.second] == '.' && visited[tmp.first][tmp.second] == false)
                        {
                            q.emplace(tmp);
                            visited[tmp.first][tmp.second] = true;
                        }
                        tmp.first -= dir[k][0];
                        tmp.second -= dir[k][1];
                    }
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}