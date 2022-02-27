#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1)
        cout << "1\n";
    else if (n <= 3)
        cout << "NO SOLUTION\n";
    else if (n == 4)
        cout << "2 4 1 3\n";
    else
    {
        for (int i = n; i > 0; i -= 2)
            cout << i << " ";
        for (int i = n - 1; i > 0; i -= 2)
        {
            cout << i;
            if (i == 1 || i == 2)
                cout << "\n";
            else
                cout << " ";
        }
    }
    return 0;
}