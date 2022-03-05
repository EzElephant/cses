#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;
using namespace std;
const ll INF = LLONG_MAX / 2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, ans;
    bool update;
    vector<tuple<ll, ll, ll>> edge(m);
    vector<ll> dist(n + 1, INF);

    while (m--)
    {
        ll v, u, w;
        cin >> v >> u >> w;
        edge.emplace_back(v, u, -w);
        edge.emplace_back(u, v, -w);
    }

    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        update = false;
        for (auto [v, u, w] : edge)
        {
            if (dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                update = true;
            }
        }
        if (!update)
        {
            ans = -dist[n];
            break;
        }
        else if (i == n && update)
            ans = -1;
    }
    cout << ans << "\n";

    return 0;
}