#define ONLINE_JUDGE
#define DEBUG
#ifdef ONLINE_JUDGE
#undef DEBUG
#endif

//
//
// ▄▄▄█████▓▓█████  ███▄ ▄███▓ ██▓███   ██▓     ▄▄▄      ▄▄▄█████▓▓█████      ██████ ▄▄▄█████▓ ▄▄▄       ██▀███  ▄▄▄█████▓
// ▓  ██▒ ▓▒▓█   ▀ ▓██▒▀█▀ ██▒▓██░  ██▒▓██▒    ▒████▄    ▓  ██▒ ▓▒▓█   ▀    ▒██    ▒ ▓  ██▒ ▓▒▒████▄    ▓██ ▒ ██▒▓  ██▒ ▓▒
// ▒ ▓██░ ▒░▒███   ▓██    ▓██░▓██░ ██▓▒▒██░    ▒██  ▀█▄  ▒ ▓██░ ▒░▒███      ░ ▓██▄   ▒ ▓██░ ▒░▒██  ▀█▄  ▓██ ░▄█ ▒▒ ▓██░ ▒░
// ░ ▓██▓ ░ ▒▓█  ▄ ▒██    ▒██ ▒██▄█▓▒ ▒▒██░    ░██▄▄▄▄██ ░ ▓██▓ ░ ▒▓█  ▄      ▒   ██▒░ ▓██▓ ░ ░██▄▄▄▄██ ▒██▀▀█▄  ░ ▓██▓ ░
//   ▒██▒ ░ ░▒████▒▒██▒   ░██▒▒██▒ ░  ░░██████▒ ▓█   ▓██▒  ▒██▒ ░ ░▒████▒   ▒██████▒▒  ▒██▒ ░  ▓█   ▓██▒░██▓ ▒██▒  ▒██▒ ░
//   ▒ ░░   ░░ ▒░ ░░ ▒░   ░  ░▒▓▒░ ░  ░░ ▒░▓  ░ ▒▒   ▓▒█░  ▒ ░░   ░░ ▒░ ░   ▒ ▒▓▒ ▒ ░  ▒ ░░    ▒▒   ▓▒█░░ ▒▓ ░▒▓░  ▒ ░░
//     ░     ░ ░  ░░  ░      ░░▒ ░     ░ ░ ▒  ░  ▒   ▒▒ ░    ░     ░ ░  ░   ░ ░▒  ░ ░    ░      ▒   ▒▒ ░  ░▒ ░ ▒░    ░
//   ░         ░   ░      ░   ░░         ░ ░     ░   ▒     ░         ░      ░  ░  ░    ░        ░   ▒     ░░   ░   ░
//             ░  ░       ░                ░  ░      ░  ░            ░  ░         ░                 ░  ░   ░
//

#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi = acos(-1.0);

typedef unsigned long int ulong;
typedef long long int llong;
typedef unsigned long long int ullong;

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int, int> MII;
typedef unordered_map<int, int> UMII;
typedef set<int> SI;
typedef multiset<int> MI;

typedef pair<llong, llong> PLL;
typedef vector<llong> VLL;
typedef vector<PLL> VPLL;
typedef vector<VLL> VVLL;
typedef map<llong, llong> MLL;
typedef unordered_map<llong, llong> UMLL;
typedef set<llong> SL;
typedef multiset<llong> MSL;

typedef vector<string> VS;

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")\n";
}

template <class T>
ostream &operator<<(ostream &os, set<T> V)
{
    os << "[";
    for (auto vv : V)
        os << vv << ", ";
    return os << "\b\b]\n";
}

template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    for (auto vv : V)
        os << vv << ' ';
    return os << "\n";
}

template <class K, class X>
ostream &operator<<(ostream &os, map<K, X> V)
{
    os << "[";
    for (auto vv : V)
        os << vv << ", ";
    return os << "\b\b]\n";
}

llong ceildiv(llong n, llong f)
{
    if (n % f)
    {
        return n / f + 1;
    }
    else
        return n / f;
}

//
//
// ▄▄▄█████▓▓█████  ███▄ ▄███▓ ██▓███   ██▓     ▄▄▄      ▄▄▄█████▓▓█████    ▓█████  ███▄    █ ▓█████▄
// ▓  ██▒ ▓▒▓█   ▀ ▓██▒▀█▀ ██▒▓██░  ██▒▓██▒    ▒████▄    ▓  ██▒ ▓▒▓█   ▀    ▓█   ▀  ██ ▀█   █ ▒██▀ ██▌
// ▒ ▓██░ ▒░▒███   ▓██    ▓██░▓██░ ██▓▒▒██░    ▒██  ▀█▄  ▒ ▓██░ ▒░▒███      ▒███   ▓██  ▀█ ██▒░██   █▌
// ░ ▓██▓ ░ ▒▓█  ▄ ▒██    ▒██ ▒██▄█▓▒ ▒▒██░    ░██▄▄▄▄██ ░ ▓██▓ ░ ▒▓█  ▄    ▒▓█  ▄ ▓██▒  ▐▌██▒░▓█▄   ▌
//   ▒██▒ ░ ░▒████▒▒██▒   ░██▒▒██▒ ░  ░░██████▒ ▓█   ▓██▒  ▒██▒ ░ ░▒████▒   ░▒████▒▒██░   ▓██░░▒████▓
//   ▒ ░░   ░░ ▒░ ░░ ▒░   ░  ░▒▓▒░ ░  ░░ ▒░▓  ░ ▒▒   ▓▒█░  ▒ ░░   ░░ ▒░ ░   ░░ ▒░ ░░ ▒░   ▒ ▒  ▒▒▓  ▒
//     ░     ░ ░  ░░  ░      ░░▒ ░     ░ ░ ▒  ░  ▒   ▒▒ ░    ░     ░ ░  ░    ░ ░  ░░ ░░   ░ ▒░ ░ ▒  ▒
//   ░         ░   ░      ░   ░░         ░ ░     ░   ▒     ░         ░         ░      ░   ░ ░  ░ ░  ░
//             ░  ░       ░                ░  ░      ░  ░            ░  ░      ░  ░         ░    ░
//
//

bool isValidBoard(VS board)
{
    int n = board.size(), m = board[0].length();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != '*')
            {
                int count = 0;

                if (i - 1 >= 0 && board[i - 1][j] == '*')
                    count++;
                if (j - 1 >= 0 && board[i][j - 1] == '*')
                    count++;
                if (i + 1 < n && board[i + 1][j] == '*')
                    count++;
                if (j + 1 < m && board[i][j + 1] == '*')
                    count++;
                if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == '*')
                    count++;
                if (i - 1 >= 0 && j + 1 < m && board[i - 1][j + 1] == '*')
                    count++;
                if (i + 1 < n && j - 1 >= 0 && board[i + 1][j - 1] == '*')
                    count++;
                if (i + 1 < n && j + 1 < m && board[i + 1][j + 1] == '*')
                    count++;

                if (board[i][j] == '.')
                {
                    if (count != 0)
                        return false;
                }
                else
                {
                    char num = '0' + count;
                    if (board[i][j] != num)
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int n, m;
    cin >> n >> m;
    VS board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    bool ans = isValidBoard(board);
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}