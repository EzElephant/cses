#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 200087;
vector<int> tree[MAXN];
int sz[MAXN];

int dfs(int node)
{
    for (auto x : tree[node])
        sz[node] += dfs(x);
    return sz[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    cin >> n;
    for (int i = 0; i < MAXN; i++)
        sz[i] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> tmp;
        tree[tmp].emplace_back(i);
    }
    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << sz[i] - 1 << " ";
    cout << "\n";

    return 0;
}