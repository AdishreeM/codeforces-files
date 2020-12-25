#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ulong;
typedef long long llong;

int main()
{
    int n, inpx, inpy;
    cin >> n;
    unordered_map<int, set<int>> coords;
    set<int> x_pts;
    set<int> y_pts;
    for(int i=0; i<n; i++)
    {
        cin >> inpx >> inpy;
        coords[inpx].insert(inpy);
        x_pts.insert(inpx);
        y_pts.insert(inpy);
    }
    
    int count = 0;
    int xmin = *x_pts.begin();
    int xmax = *x_pts.rbegin();
    int ymin = *y_pts.begin();
    int ymax = *y_pts.rbegin();

    for(auto x: x_pts)
    {
        if(x == xmin || x == xmax)
            continue;
        for(auto y: coords[x])
        {
            if(y!=ymin && y!=ymax)
                count++;
        }
    }
    cout << count;
    return 0;
}