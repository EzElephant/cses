#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 100087;
ll n, m, a, b, w;
vector<pair<ll, ll>> G[MAXN];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
ll dist[MAXN];
bool visited[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        G[a].emplace_back(b, w);
    }

    for (int i = 0; i < MAXN; i++)
        dist[i] = 8.7e17;
    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty())
    {
        auto tmp = pq.top();
        pq.pop();
        if (visited[tmp.second])
            continue;
        visited[tmp.second] = true;
        for (auto [x, v] : G[tmp.second])
        {
            if (dist[x] > dist[tmp.second] + v)
            {
                dist[x] = dist[tmp.second] + v;
                pq.emplace(dist[x], x);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}