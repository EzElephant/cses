#include <bits/extc++.h>
using namespace std;
#define double int64_t
struct PT {
    double x, y;
    PT(double x = 0, double y = 0) : x(x), y(y) {}
    PT operator+(const PT &b) const {
        return PT(x + b.x, y + b.y);
    }
    PT operator-(const PT &b) const {
        return PT(x - b.x, y - b.y);
    }
    double dot(const PT &b) const {
        return x * b.x + y * b.y;
    }
    double cross(const PT &b) const {
        return x * b.y - y * b.x;
    }
};
bool btw(const PT &p1, const PT &p2, const PT &p3) { // 判斷p3是否在p1 p2之間(要先共線)
    return (p1 - p3).dot(p2 - p3) <= 0;
}
int ori(const PT &p1, const PT &p2, const PT &p3) {
    double a = (p2 - p1).cross(p3 - p1);
    if (a == 0)
        return 0;
    return a > 0 ? 1 : -1;
}
bool seg_intersect(const PT &p1, const PT &p2, const PT &p3, const PT &p4) { // 線段是否相交
    int a123 = ori(p1, p2, p3);
    int a124 = ori(p1, p2, p4);
    int a341 = ori(p3, p4, p1);
    int a342 = ori(p3, p4, p2);
    if (a123 == 0 && a124 == 0)
        return btw(p1, p2, p3) || btw(p1, p2, p4) || btw(p3, p4, p1) || btw(p3, p4, p2);
    else if (a123 * a124 <= 0 && a341 * a342 <= 0)
        return true;
    return false;
}

void solve()
{
    int64_t x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    PT p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
    if (seg_intersect(p1, p2, p3, p4))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}