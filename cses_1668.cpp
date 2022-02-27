#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100087;
bool flag;
int p[MAXN];
int re[3] = {0, 2, 1};
vector<int> G[MAXN];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[i])
            continue;
        q.emplace(i);
        p[i] = 1;
        while (!q.empty())
        {
            if (flag)
                break;
            for (auto x : G[q.front()])
            {
                if (p[q.front()] == p[x])
                {
                    flag = true;
                    break;
                }
                if (p[x]) continue;
                q.emplace(x);
                p[x] = re[p[q.front()]];
            }
            q.pop();
        }
    }

    if (flag)
        cout << "IMPOSSIBLE\n";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << p[i];
            if (i == n)
                cout << "\n";
            else
                cout << " ";
        }
    }

    return 0;
}