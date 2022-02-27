#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, time, deadline;
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> f;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> time >> deadline;
        f.emplace(time);
        ans += deadline;
    }

    for (long long i = n; i > 0; i--)
    {
        ans -= (f.top() * i);
        f.pop();
    }
    cout << ans << "\n";

    return 0;
}