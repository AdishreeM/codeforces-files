#include <bits/stdc++.h>
using namespace std;

// A structure to represent a Point in 2D plane
class Point
{
public:
    int x, y;
};

// Distance between two points
float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Smallest distance among 3 or lesser points
float getSmallestDist(vector<Point> P, int beg, int end)
{
    float min = FLT_MAX;
    int n = end - beg + 1;
    for (int i = beg; i <= end; ++i)
        for (int j = i + 1; j <= end; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// Distance beween closest points in strip
float stripClosest(vector<Point> strip, float d)
{
    int n = strip.size();
    float min = d; // Initialize the minimum distance as d
    sort(strip.begin(), strip.end(), [](auto a, auto b) {
        return (a.y - b.y);
    });

    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// Recursive function to find the smallest distance
float closestUtil(vector<Point> P, int beg, int end)
{
    if (end - beg + 1 <= 3)
        return getSmallestDist(P, beg, end);

    // Find the middle point
    int mid = (end - beg) / 2 + beg;
    Point midPoint = P[mid];

    // dividing around middle point
    float dl = closestUtil(P, beg, mid);
    float dr = closestUtil(P, mid + 1, end);

    // Find the smaller of two distances
    float d = min(dl, dr);

    // Checking point in strip
    vector<Point> strip;
    for (int i = beg; i <= end; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip.push_back(P[i]);

    // Return the minimum of d and closest distance is strip[]
    return min(d, stripClosest(strip, d));
}

// Main function that finds the smallest distance using closestUtil()
float closest(vector<Point> P, int n)
{
    if (n == 0)
        return 0;
    sort(P.begin(), P.end(), [](auto a, auto b) { return a.x - b.x; });
    return closestUtil(P, 0, n - 1);
}

// Driver code
int main()
{
    vector<Point> P = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = P.size();
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}