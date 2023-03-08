#include <bits/extc++.h>
using namespace std;
inline int lowbit(int x) { return x & -x; }
class BIT
{
    int n;
    vector<long long> bit;

public:
    void init(int _n)
    {
        n = _n;
        bit.resize(n);
        for (auto &b : bit)
            b = 0;
    }
    long long query(int x) const
    {
        long long sum = 0;
        for (; x; x -= lowbit(x))
            sum += bit[x];
        return sum;
    }
    void modify(int x, int val)
    {
        for (; x <= n; x += lowbit(x))
            bit[x] += val;
    }
};

class BIT2D
{
    int m;
    vector<BIT> bit1D;

public:
    void init(int _m, int _n)
    {
        m = _m;
        bit1D.resize(m);
        for (auto &b : bit1D)
            b.init(_n);
    }
    long long query(int x, int y) const
    {
        long long sum = 0;
        for (; x; x -= lowbit(x))
            sum += bit1D[x].query(y);
        return sum;
    }
    void modify(int x, int y, int val)
    {
        for (; x <= m; x += lowbit(x))
            bit1D[x].modify(y, val);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<string> forest(n);
    for (auto &str : forest)
        cin >> str;
    BIT2D bit2d;
    bit2d.init(n + 87, n + 87);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (forest[i][j] == '*')
                bit2d.modify(i + 2, j + 2, 1);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            if (forest[x - 1][y - 1] == '.')
            {
                bit2d.modify(x + 1, y + 1, 1);
                forest[x - 1][y - 1] = '*';
            }
            else
            {
                bit2d.modify(x + 1, y + 1, -1);
                forest[x - 1][y - 1] = '.';
            }
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << bit2d.query(x2 + 1, y2 + 1) - bit2d.query(x2 + 1, y1) - bit2d.query(x1, y2 + 1) + bit2d.query(x1, y1) << '\n';
        }
    }

    return 0;
}