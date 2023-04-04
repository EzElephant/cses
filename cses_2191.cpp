#include <bits/extc++.h>
using namespace std;
#define double long long

struct PT
{
    double x, y;
    PT(double x = 0, double y = 0) : x(x), y(y) {}
    PT operator+(const PT &b) const
    {
        return PT(x + b.x, y + b.y);
    }
    PT operator-(const PT &b) const
    {
        return PT(x - b.x, y - b.y);
    }
    double dot(const PT &b) const
    {
        return x * b.x + y * b.y;
    }
    double cross(const PT &b) const
    {
        return x * b.y - y * b.x;
    }
};
double area(const vector<PT> &Polygon)
{
    if (Polygon.size() <= 1)
        return 0;
    double ans = 0;
    for (auto a = --Polygon.end(), b = Polygon.begin(); b != Polygon.end(); a = b++)
        ans += a->cross(*b);
    return abs(ans);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<PT> poly(n);
    for (int i = 0; i < n; i++)
    {
        int64_t x, y;
        cin >> x >> y;
        poly[i] = PT(x, y);
    }
    cout << area(poly) << '\n';

    return 0;
}