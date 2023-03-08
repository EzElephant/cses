#include <bits/extc++.h>
using namespace std;
int table[10], tar;
int p[12][2]= {0, 1, 0, 3, 1, 2, 1, 4, 2, 5, 3, 4, 3, 6, 4, 5, 4, 7, 5, 8, 6, 7, 7, 8};

void init()
{
    table[0] = 1;
    for (int i = 1; i < 10; i++)
        table[i] = table[i - 1] * 9;
    for (int i = 0; i < 9; i++)
        tar += i * table[i];
}

int h(vector<int> &ref)
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
        sum += (ref[i] - 1) * table[i];
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    vector<int> field(9);
    unordered_map<int, bool> visited;
    queue<pair<int, vector<int>>> q;
    for (int i = 0; i < 9; i++)
        cin >> field[i];
    if (h(field) == tar)
    {
        cout << "0\n";
        return 0;
    }
    visited[h(field)] = true;
    q.emplace(0, field);
    while (!q.empty())
    {
        auto [prev ,cur] = q.front();
        q.pop();

        auto next = cur;
        for (int d = 0; d < 12; d++)
        {
            swap(next[p[d][0]], next[p[d][1]]);
            int val = h(next);
            if (val == tar)
            {
                cout << prev + 1 << '\n';
                return 0;
            }
            if (!visited[val])
            {
                visited[val] = true;
                q.emplace(prev + 1, next);
            }
            swap(next[p[d][0]], next[p[d][1]]);
        }
    }

    return 0;
}