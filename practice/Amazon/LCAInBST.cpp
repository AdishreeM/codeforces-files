#include <bits/stdc++.h>
using namespace std;

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


struct Node {
    int val;
    Node *left, *right;
    Node() {
        val = 0;
        left = right = nullptr;
    }
    Node(int _val) {
        val = _val;
        left = right = nullptr;
    }
};

class BST {
    Node *root;

public:
    BST() {
        root = nullptr;
    }
    
    void addNode(int val) {
        if (!root) {
            root = new Node(val);
            return;
        }

        Node *trav = root;
        while(trav) {
            if(trav->val > val) {
                if(trav->left)
                    trav = trav->left;
                else {
                    Node *newNode = new Node(val);
                    trav->left = newNode;
                    break;
                }
            } else {
                if(trav->right)
                    trav = trav->right;
                else {
                    Node *newNode = new Node(val);
                    trav->right = newNode;
                    break;
                }
            }
        }
    }

    Node* getLCA(int val1, int val2)
    {
        Node *trav = root;
        while(trav)
        {
            if(root->val > val1 && root->val > val2)
                trav = root->left;
            else if(root->val < val1 && root->val < val2)
                trav = root->right;
            else
                return trav;
        }
        return trav;
    }

    int getDistance(Node* node, int val)
    {
        int dist = 0;
        Node *trav = node;
        while(trav && trav->val != val) {
            dist++;
            if(trav->val < val)
                trav = trav->right;
            else
                trav = trav->left;
        }
        return dist;
    }
};

int findDistance(VI nums, int val1, int val2) {
    if(find(nums.begin(), nums.end(), val1) == nums.end())
        return -1;
    if(find(nums.begin(), nums.end(), val2) == nums.end())
        return -1;
    BST tree;
    for(auto num: nums)
        tree.addNode(num);
    Node *lca = tree.getLCA(val1, val2);
    return tree.getDistance(lca, val1) + tree.getDistance(lca, val2);
}

int main() {
    VI nums = {5, 1, 2, 7, 6};
    int val1 = 2, val2 = 6;
    cout << findDistance(nums, val1, val2) << endl;
    return 0;
}