#include <bits/extc++.h>
using namespace std;
int in_cnt[1000087], fac_cnt[1000087], n;
vector<int> table[1000087];

int Count(int k)
{
    if (k == 1)
        return n - 1;
    int result = 0;
    vector<int> factor;
    if (table[k].size())
        factor = table[k];
    else
    {
        int tmp = k;
        for (int i = 2; i * i <= tmp; i++)
        {
            if (tmp % i == 0)
            {
                while (tmp % i == 0)
                {
                    tmp /= i;
                }
                factor.emplace_back(i);
            }
        }
        if (tmp != 1)
            factor.emplace_back(tmp);
        table[k] = factor;
    }

    int64_t mx = (1LL << factor.size());
    for (int64_t i = 0; i < mx; i++)
    {
        int flag = 1;
        int product = 1;
        for (int j = 0; j < factor.size(); j++)
        {
            if ((i >> j) & 1)
            {
                flag *= -1;
                product *= factor[j];
            }
        }
        result += flag * fac_cnt[product];
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t ans = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
        in_cnt[x]++;
    }
    for (int i = 1; i < 1000087; i++)
        for (int j = i; j < 1000087; j = j + i)
            fac_cnt[i] += in_cnt[j];

    for (int i = 0; i < n; i++)
        ans += Count(a[i]);
    cout << (ans >> 1) << '\n';

    return 0;
}