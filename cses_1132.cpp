#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 200087;
int dis[MAXN][2];
bool visited[MAXN];
vector<int> tree[MAXN];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, farest;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    q.emplace(n / 2 + 1);
    while (!q.empty())
    {
        visited[q.front()] = true;
        for (int x : tree[q.front()])
        {
            if (visited[x])
                continue;
            q.emplace(x);
            visited[q.front()] = true;
            farest = x;
        }
        q.pop();
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < 2; j++)
            dis[i][j] = -1;

    q.emplace(farest);
    dis[farest][0] = 0;
    while (!q.empty())
    {
        for (int x : tree[q.front()])
        {
            if (dis[x][0] != -1)
                continue;
            q.emplace(x);
            dis[x][0] = dis[q.front()][0] + 1;
            farest = x;
        }
        q.pop();
    }
    
    q.emplace(farest);
    dis[farest][1] = 0;
    while (!q.empty())
    {
        for (int x : tree[q.front()])
        {
            if (dis[x][1] != -1)
                continue;
            q.emplace(x);
            dis[x][1] = dis[q.front()][1] + 1;
        }
        q.pop();
    }
    
    for (int i = 1; i <= n; i++)
        cout << max(dis[i][0], dis[i][1]) << " ";
    cout << "\n";

    return 0;
}