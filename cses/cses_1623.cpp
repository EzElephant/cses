#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, max, base;
    long long sum = 0, tmp, min = LLONG_MAX;
    cin >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
    }
    max = pow(2, n);
    for (int i = 0; i < max; i++)
    {
        tmp = 0, base = 1;
        for (int j = 0; j < n; j++)
        {
            if (i & base)
                tmp += p[j];
            base<<=1;
        }
        min = abs(sum - 2 * tmp) < min ? abs(sum - 2 * tmp) : min;
    }
    cout << min << "\n";
}