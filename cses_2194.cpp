#include <bits/extc++.h>
using namespace std;
#define double long long
int mode = 0;
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
        if (mode == 0)
            return x != b.x ? x < b.x : y < b.y;
        else if (mode == 1)
            return y != b.y ? y < b.y : x < b.x;
        else
            return x + y != b.x + b.y ? x + y < b.x + b.y : x < b.x;
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long result = 8e18 + 87;
    cin >> n;
    vector<PT> points(n);
    for (int i = 0; i < n; i++)
    {
        int64_t x, y;
        cin >> x >> y;
        points[i] = PT(x, y);
    }
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++)
        for (int j = 1; (j * j < n || j < 487) && i + j < n; j++)
            result = min(result, (points[i] - points[i + j]).abs2());
    mode = 1;
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++)
        for (int j = 1; (j * j < n || j < 487) && i + j < n; j++)
            result = min(result, (points[i] - points[i + j]).abs2());
    mode = 2;
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++)
        for (int j = 1; (j * j < n || j < 487) && i + j < n; j++)
            result = min(result, (points[i] - points[i + j]).abs2());
    cout << result << '\n';

    return 0;
}