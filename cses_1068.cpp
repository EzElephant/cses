#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    while (true)
    {
        cout << n;
        if (n == 1)
        {
            cout << "\n";
            return 0;
        }
        else
            cout << " ";
        if (n & 1)
            n = 3 * n + 1;
        else
            n = n >> 1;
    }
}