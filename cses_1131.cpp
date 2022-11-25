#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 200087;
int dis[MAXN];
bool visited[MAXN];
vector<int> tree[MAXN];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, farest, ans;
    cin >> n;
    if (n == 1)
    {
        cout << "0\n";
        return 0;
    }
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

    q.emplace(farest);
    for (int i = 0; i < MAXN; i++)
        dis[i] = -1;
    dis[farest] = 0;
    while (!q.empty())
    {
        for (int x : tree[q.front()])
        {
            if (dis[x] != -1)
                continue;
            q.emplace(x);
            dis[x] = dis[q.front()] + 1;
            ans = dis[x];
        }
        q.pop();
    }
    
    cout << ans << "\n";

    return 0;
}