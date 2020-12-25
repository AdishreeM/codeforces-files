#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef vector<string> VS;

class Item
{
public:
    string name;
    int relevance;
    int price;
    int sort_order;
    int sort_parameter;

    Item() = default;
    Item(string _name, int _relevance, int _price,
         int _sort_order, int _sort_parameter)
    {
        name = _name;
        relevance = _relevance;
        price = _price;
        sort_order = _sort_order;
        sort_parameter = _sort_parameter;
    }
};

class compareItem
{
public:
    bool operator()(Item a, Item b)
    {
        if (a.sort_parameter == 0)
        {
            if (a.sort_order == 0)
                return a.name < b.name;
            return a.name > b.name;
        }
        else if (a.sort_parameter == 1)
        {
            if (a.sort_order == 0)
                return a.relevance < b.relevance;
            return a.relevance > b.relevance;
        }
        else
        {
            if (a.sort_order == 0)
                return a.price < b.price;
            return a.price > b.price;
        }
    }
};

VS getDisplayItems(int numItems, map<string, PII> items, int sortParam, int sortOrder, int itemsPerPage, int pageNumber)
{
    priority_queue<Item, vector<Item>, compareItem> pq;
    int size = min((pageNumber + 1) * itemsPerPage, numItems);
    for (auto item : items)
    {
        pq.push(Item(item.first, item.second.first, item.second.second, sortOrder, sortParam));
        if (pq.size() > size)
            pq.pop();
    }

    VS ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().name);
        pq.pop();
    }

    reverse(ans.begin(), ans.end());
    int skipPages = itemsPerPage * pageNumber;
    return VS(ans.begin()+skipPages, ans.end());
}

int main()
{
    int numItems;
    int sortParam, sortOrder, itemsPerPage, pageNumber;
    cin >> numItems;
    string name;
    int rel, val;
    map<string, PII> items;
    for (int i = 0; i < numItems; i++)
    {
        cin >> name >> rel >> val;
        items[name] = {rel, val};
    }
    cin >> sortParam >> sortOrder >> itemsPerPage >> pageNumber;
    auto ans = getDisplayItems(numItems, items, sortParam, sortOrder, itemsPerPage, pageNumber);
    for (string str : ans)
        cout << str << endl;
}