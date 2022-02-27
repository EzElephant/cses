#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    cin >> tmp >> n;
    set<int> p;
    multiset<int> len;
    p.insert(0), p.insert(tmp);
    len.emplace(tmp);

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        p.insert(tmp);
        auto it1 = p.find(tmp);
        auto it2 = it1;
        it1--, it2++;
        auto it = len.find(*it2 - *it1);
        len.erase(it);
        len.insert(*it2 - tmp);
        len.insert(tmp - *it1);
        it = len.end(), it--;
        cout << *it;
        if (i == n - 1)
            cout << "\n";
        else
            cout << " ";
    }

    return 0;
}