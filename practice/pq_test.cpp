#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> PCI;

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")\n";
}


struct Comparator {
    bool operator()(PCI a, PCI b) {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    } 
};


int main()
{
    
    map<char, int> freq;
    for(int i=0; i<5; i++) {
       freq['a'+i]=5-i;
    }
    freq['f'] = 5;

    int k = 6;

    priority_queue<PCI, vector<PCI>, Comparator> pq;
    for(auto word_freq: freq)
    {
        pq.push(word_freq);
        if(pq.size() > k)
            pq.pop();
    }

    while(!pq.empty()) {
        cout << pq.top();
        pq.pop();
    }

    return 0;
} 