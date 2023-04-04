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
};
void getConvexHull(vector<PT> Points)
{ // 找凸包
    sort(Points.begin(), Points.end());
    vector<PT> ans;
    int m = 0, t = 1, n = Points.size();
    auto addPoint = [&](const PT &p)
    {
        while (m > t && (ans[m - 1] - ans[m - 2]).cross(p - ans[m - 2]) < 0)
            ans.pop_back(), --m;
        ans.emplace_back(p);
        ++m;
    };
    for (int i = 0; i < n; i++)
        addPoint(Points[i]);
    t = m;
    for (int i = n - 2; i >= 0; i--)
        addPoint(Points[i]);
    if (ans.size() > 1)
        ans.pop_back();
    
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].x << ' ' << ans[i].y << '\n';
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
    getConvexHull(points);

    return 0;
}