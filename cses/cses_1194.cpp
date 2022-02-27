#include <iostream>
#include <queue>
#include <stack>
using namespace std;
char field[1087][1087], dir[4] = {'D', 'U', 'R', 'L'};
int n, m, x, y, tmp, cnt;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int flee[1087][1087], monster[1087][1087], route[1087][1087];
bool flag;
pair<int, int> ans, before[1087][1087], temp;
queue<pair<int, int>> q, qm; //q是起始點的queue qm是monster的queue
stack<int> s;
 
void bfs()
{
    while (!q.empty())
    {
        temp = q.front();
        for (int i = 0; i < 4; i++)
        {
            x = q.front().first + dx[i];
            y = q.front().second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m)
            {
                flag = true;
                ans = make_pair(q.front().first, q.front().second);
                return;
            }
            if (before[x][y] != make_pair(0, 0))
                continue;
            if (route[x][y] <= 0)
                continue;
            if (field[x][y] == '#' || field[x][y] == 'A')
                continue;
            q.emplace(make_pair(x, y));
            before[x][y] = temp;
        }
        q.pop();
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];
 
    for (int i = 0; i < 1050; i++)
        for (int j = 0; j < 1050; j++)
        {
            flee[i][j] = 1e9;
            monster[i][j] = 1e9;
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (field[i][j] == 'A')
            {
                q.emplace(make_pair(i, j));
                flee[i][j] = 0;
            }
            else if (field[i][j] == 'M')
            {
                qm.emplace(make_pair(i, j));
                monster[i][j] = 0;
            }
        }
    while(!q.empty())
    {
        tmp = flee[q.front().first][q.front().second];
        for (int i = 0; i < 4; i++)
        {
            x = q.front().first + dx[i];
            y = q.front().second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;
            if (field[x][y] == '#' || flee[x][y] != 1e9)
                continue;
            q.emplace(make_pair(x, y));
            flee[x][y] = tmp + 1;
        }
        q.pop();
    }
    while(!qm.empty())
    {
        tmp = monster[qm.front().first][qm.front().second];
        for (int i = 0; i < 4; i++)
        {
            x = qm.front().first + dx[i];
            y = qm.front().second + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;
            if (field[x][y] == '#' || monster[x][y] != 1e9)
                continue;
            qm.emplace(make_pair(x, y));
            monster[x][y] = tmp + 1;
        }
        qm.pop();
    }
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            route[i][j] = monster[i][j] - flee[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (field[i][j] == 'A')
            {
                before[i][j] = make_pair(i, j);
                q.emplace(make_pair(i, j));
            }
 
    bfs();
 
    if (!flag)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        temp = ans;
        while (temp != before[temp.first][temp.second])
        {
            cnt++;
            x = temp.first - before[temp.first][temp.second].first;
            y = temp.second - before[temp.first][temp.second].second;
            for (int i = 0; i < 4; i++)
            {
                if (x == dx[i] && y == dy[i])
                    s.emplace(i);
            }
            temp = before[temp.first][temp.second];
        }
        cout << cnt << "\n";
        while (!s.empty())
        {
            cout << dir[s.top()];
            s.pop();
        }
    }
 
    return 0;
}