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
typedef vector<bool> VB;
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

string setToLowerCase(string str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
        str[i] = tolower(str[i]);
    return str;
}

VS getKFrequentKeywords(VS reviews, VS keywords, int K)
{
    vector<pair<string, int>> frequency;
    for (auto keyword : keywords)
    {
        keyword = setToLowerCase(keyword);
        int found = 0;
        for (auto review : reviews)
        {
            review = setToLowerCase(review);
            if (review.find(keyword) != string::npos)
                found++;
        }
        frequency.push_back({keyword, found});
    }

    sort(frequency.begin(), frequency.end(), [](auto a, auto b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    });

    VS ans(K);
    for (int i = 0; i < K; i++)
        ans.push_back(frequency[i].first);

    return ans;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int k = 2;
    VS keywords = {"anacell", "betacellular", "cetracular", "deltacellular", "eurocell"};
    VS reviews = {"I love anacell Best services; Best services provided by anacell",
                  "deltacellular has great services",
                  "deltacellular provides much better services than betacellular",
                  "cetracular is worse than anacell",
                  "Betacellular is better than deltacellular."};
    cout << getKFrequentKeywords(reviews, keywords, k);
    return 0;
}