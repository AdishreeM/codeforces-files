#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool searchUtil(VVI &matrix, int rbeg, int rend, int cbeg, int cend, int val)
{
    if (rbeg > rend || cbeg > cend)
        return false;
    int rmid = rbeg + (rend - rbeg) / 2, cmid = cbeg + (cend - cbeg) / 2;
    if (matrix[rmid][cmid] < val)
        return searchUtil(matrix, rbeg, rmid, cmid + 1, cend, val) ||
               searchUtil(matrix, rmid + 1, rend, cbeg, cmid - 1, val) ||
               searchUtil(matrix, rmid + 1, rend, cmid, cend, val);
    if (matrix[rmid][cmid] > val)
        return searchUtil(matrix, rbeg, rmid - 1, cbeg, cmid - 1, val) ||
               searchUtil(matrix, rbeg, rmid - 1, cmid, cend, val) ||
               searchUtil(matrix, rmid, rend, cbeg, cmid - 1, val);
    return true;
}

bool searchMatrix(VVI &matrix, int target)
{
    if (matrix.size() == 0)
        return false;
    int n = matrix.size(), m = matrix[0].size();
    return searchUtil(matrix, 0, n - 1, 0, m - 1, target);
}

int main()
{
    VVI matrix = {{1, 4, 7, 11, 15},
                  {2, 3, 8, 12, 19},
                  {3, 6, 9, 16, 22},
                  {10, 13, 14, 17, 24},
                  {18, 21, 23, 26, 35}};
    int target = 35;
    cout << searchMatrix(matrix, target);
}