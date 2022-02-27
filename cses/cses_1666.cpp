//DSU
#include <iostream>
#include <vector>
using namespace std;
vector<int> fa;
vector<pair<int, int>> road;
int ans;

int find_fa(int x)
{
    return x == fa[x] ? x : fa[x] = find_fa(fa[x]);
}

void unite(int x, int y)
{
    fa[find_fa(y)] = find_fa(x);
}

void print()
{
    cout << ans << "\n";
    for (auto x : road)
        cout << x.first << " " << x.second << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    fa.resize(n + 1);
    road.reserve(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;

    while (m--)
    {
        cin >> a >> b;
        unite(a, b);
    }

    for (int i = 2; i <= n; i++)
    {
        if (find_fa(i) != find_fa(1))
        {
            unite(find_fa(1), find_fa(i));
            road.emplace_back(make_pair(find_fa(1), i));
            ans++;
        }
    }

    print();

    return 0;  
}