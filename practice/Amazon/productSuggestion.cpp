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
typedef vector<VS> VVS;

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

struct Node
{
    vector<Node *> children;
    vector<string> words;
    Node()
    {
        children = vector<Node *>(26, nullptr);
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void AddWord(string word)
    {
        Node *trav = root;
        for (char c : word)
        {
            if (!trav->children[c - 'a'])
            {
                Node *letter = new Node;
                trav->children[c - 'a'] = letter;
            }
            trav = trav->children[c - 'a'];
            trav->words.push_back(word);
            sort(trav->words.begin(), trav->words.end());
            if (trav->words.size() > 3)
            {
                trav->words.resize(3);
            }
        }
    }

    VVS suggestWords(string word)
    {
        VVS suggestions;
        Node *trav = root;
        for (auto c : word)
        {
            if (!trav->children[c - 'a'])
            {
                suggestions.push_back({});
                break;
            }
            trav = trav->children[c - 'a'];
            suggestions.push_back(trav->words);
        }
        int n = suggestions.size(), m = word.length();
        while (n < m)
        {
            suggestions.push_back({});
            n++;
        }
        return suggestions;
    }
};

VVS suggestedProducts(VS &products, string searchWord)
{
    Trie trie;
    for (auto product : products)
        trie.AddWord(product);
    return trie.suggestWords(searchWord);
}

//  ALTERNATE SOLUTION USING SORT ANF BINARY SEARCH TO FIND
//  LOWER AND UPPER BOUND FOR EACH PREFIX
//
// vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//     sort(products.begin(), products.end());
//     vector<vector<string>> result;
//     for (int l = 0; l < searchWord.size(); ++ l) {
//         auto start = lower_bound(products.begin(), products.end(), searchWord.substr(0, l+1));
//         auto end = lower_bound(start, min(start+3, products.end()), searchWord.substr(0, l) + (char)(searchWord[l]+1));
//         result.push_back(vector<string>(start, end));
//     }
//     return result;		         
// }

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    VS products = {"bags","baggage","banner","box","cloths"};
    string searchWord = "hats";
    VVS ans = suggestedProducts(products, searchWord);
    for (auto words : ans)
    {
        cout << '[';
        for (auto suggestion : words)
        {
            cout << suggestion << ", ";
        }
        cout << "]\n";
    }
    return 0;
}