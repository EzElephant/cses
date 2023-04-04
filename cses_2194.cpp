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
    PT operator*(double b) const
    {
        return PT(x * b, y * b);
    }
    PT operator/(double b) const
    {
        return PT(x / b, y / b);
    }
    bool operator<(const PT &b) const
    {
        return x != b.x ? x < b.x : y < b.y; 
    }
    double dot(const PT &b) const
    {
        return x * b.x + y * b.y;
    }
    double cross(const PT &b) const
    {
        return x * b.y - y * b.x;
    }
    double abs2()
    {
        return x * x + y * y;
    }
};
bool btw(const PT &p1, const PT &p2, const PT &p3)
{ // 判斷p3是否在p1 p2之間(要先共線)
    return (p1 - p3).dot(p2 - p3) <= 0;
}
bool collinearity(const PT &p1, const PT &p2, const PT &p3)
{ // 判斷是否共線
    return (p1 - p3).cross(p2 - p3) == 0;
}
bool pointOnSegment(const PT &p1, const PT &p2, const PT &p3)
{
    return collinearity(p1, p2, p3) && btw(p1, p2, p3);
}
double area(const vector<PT> &Polygon)
{ // 多邊形面積
    if (Polygon.size() <= 1)
        return 0;
    double ans = 0;
    for (auto a = --Polygon.end(), b = Polygon.begin(); b != Polygon.end(); a = b++)
        ans += a->cross(*b);
    return ans / 2;
}
int pointInPolygon(const vector<PT> &Polygon, const PT &p)
{
    int ans = 0;
    for (auto a = --Polygon.end(), b = Polygon.begin(); b != Polygon.end(); a = b++)
    {
        if (pointOnSegment(*a, *b, p))
            return -1;
        if ((a->y > p.y) != (b->y > p.y) && (p.x - b->x) < (a->x - b->x) * (p.y - b->y) / (a->y - b->y))
        {
            ans = !ans;
        }
    }
    return ans;
}
int ori(const PT &p1, const PT &p2, const PT &p3)
{
    double a = (p2 - p1).cross(p3 - p1);
    if (a == 0)
        return 0;
    return a > 0 ? 1 : -1;
}
bool seg_intersect(const PT &p1, const PT &p2, const PT &p3, const PT &p4)
{ // 線段是否相交
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
PT intersect(const PT &p1, const PT &p2, const PT &p3, const PT &p4)
{ // 找交點
    double a123 = (p2 - p1).cross(p3 - p1);
    double a124 = (p2 - p1).cross(p4 - p1);
    return (p4 * a123 - p3 * a124) / (a123 - a124);
}
vector<PT> getConvexHull(vector<PT> Points)
{ // 找凸包
    sort(Points.begin(), Points.end());
    vector<PT> ans;
    int m = 0, t = 1;
    auto addPoint = [&](const PT &p)
    {
        while (m > t && (ans[m - 1] - ans[m - 2]).cross(p - ans[m - 2]) <= 0)
            ans.pop_back(), --m;
        ans.emplace_back(p);
        ++m;
    };
    for (size_t i = 0; i < Points.size(); ++i)
        addPoint(Points[i]);
    t = m;
    for (int i = int(Points.size()) - 2; i >= 0; --i)
        addPoint(Points[i]);
    if (Points.size() > 1)
        ans.pop_back();
    return ans;
}
double solve(vector<PT> ConvexHull)
{
    int n = ConvexHull.size();
    double result = 4e18 + 8787;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            result = min(result, (ConvexHull[i] - ConvexHull[j]).abs2());
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<PT> points(n);
    for (int i = 0; i < n; i++)
    {
        int64_t x, y;
        cin >> x >> y;
        points[i] = PT(x, y);
    }
    cout << solve(getConvexHull(points)) << '\n';

    return 0;
}