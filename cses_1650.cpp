#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q, tmp, a, b;
    cin >> n >> q;
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> pre[i];
        pre[i] ^= pre[i-1];
    }
    while (q--)
    {
        cin >> a >> b;
        tmp = pre[b] ^ pre[a - 1];
        cout << tmp << '\n';
    }

    return 0;
}