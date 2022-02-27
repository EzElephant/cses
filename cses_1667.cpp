#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 100087;
int n, m, before[MAXN];
vector<int> G[MAXN];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    q.emplace(1);
    before[1] = -1;
    while (!q.empty())
    {
        if (q.front() == n)
            break;
        for (auto x : G[q.front()])
        {
            if (before[x] == 0)
            {
                q.emplace(x);
                before[x] = q.front();
            }
        }
        q.pop();
    }

    if (!before[n])
        cout << "IMPOSSIBLE\n";
    else
    {
        int cur = n, ans = 1;
        stack<int> route;
        route.emplace(cur);
        while (before[cur] != -1)
        {
            route.emplace(before[cur]);
            cur = before[cur];
            ans++;
        }
        cout << ans << "\n";
        while (ans--)
        {
            cout << route.top();
            route.pop();
            if (ans == 0)
                cout << "\n";
            else
                cout << " ";
        }
    }

    return 0;
}