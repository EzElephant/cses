#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
typedef long long ll;
using namespace std;
const ll INF = LLONG_MAX / 2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, ans;
    bool update;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> edge;
    vector<ll> dist(n + 1, INF);
    edge.reserve(m);

    while (m--)
    {
        ll v, u, w;
        cin >> v >> u >> w;
        edge.emplace_back(v, u, -w);
    }

    dist[1] = 0;
    for (int i = 0; i <= n; i++)
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
        if (ans != -dist[n] && i == n && update)
        {
            ans = -1;
            break;
        }
        ans = -dist[n];
    }
    cout << ans << "\n";

    return 0;
}