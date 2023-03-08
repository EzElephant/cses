#include <iostream>
#include <stack>
#include <queue>
using namespace std;
char field[1087][1087];
bool visited[1087][1087], flag;
pair<int, int> before[1087][1087], ans;
int x, y;
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char characters[4] = {'D', 'U', 'R', 'L'};

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    pair<int, int> tmp;
    q.push(make_pair(r, c));
    while (!q.empty())
    {
        tmp = q.front(), q.pop();
        if (field[tmp.first][tmp.second] == 'B')
        {
            flag = true;
            ans = tmp;
            break;
        }
        for (int k = 0; k < 4; k++)
        {
            visited[tmp.first][tmp.second] = true;
            tmp.first += dir[k][0];
            tmp.second += dir[k][1];
            if (tmp.first < 0 || tmp.second < 0 || tmp.first >= x || tmp.second >= y)
                ;
            else if (field[tmp.first][tmp.second] != '#' && visited[tmp.first][tmp.second] == false)
            {
                q.emplace(tmp);
                visited[tmp.first][tmp.second] = true;
                before[tmp.first][tmp.second] = make_pair(tmp.first - dir[k][0], tmp.second - dir[k][1]);
            }
            tmp.first -= dir[k][0];
            tmp.second -= dir[k][1];
        }
    }
    return;
}

void print()
{
    if (!flag)
    {
        cout << "NO\n";
        return;
    }

    int cnt = 0, tmp_x, tmp_y;
    pair<int, int> cur = ans;
    stack<int> route;
    while (field[cur.first][cur.second] != 'A')
    {
        tmp_x = cur.first - before[cur.first][cur.second].first;
        tmp_y = cur.second - before[cur.first][cur.second].second;
        for (int i = 0; i < 4; i++)
        {
            if (tmp_x == dir[i][0] && tmp_y == dir[i][1])
            {
                route.emplace(i);
                break;
            }
        }
        cur = before[cur.first][cur.second];
        cnt++;
    }

    cout << "YES\n"
         << cnt << "\n";
    while (!route.empty())
    {
        cout << characters[route.top()];
        route.pop();
    }
    cout << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> field[i][j];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            if (field[i][j] == 'A')
                bfs(i, j);
    print();

    return 0;
}