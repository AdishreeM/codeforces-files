#include <bits/stdc++.h>

using namespace std;

int getHappyRabbitCount(vector<char> field, int range)
{
    int rabbit = 0, carrot = 0;
    bool updateCarrot = false, updateRabbit = false;
    int count = 0, n = field.size();
    while (rabbit <= n && carrot <= n)
    {
        if (!rabbit && !carrot)
            updateRabbit = updateCarrot = true;
        else if(abs(rabbit - carrot) <= range)
            count++, updateCarrot = updateRabbit = true;
        else if (rabbit < carrot)
            updateRabbit = true;
        else if(carrot < rabbit)
            updateCarrot = true;

        if(updateRabbit) {
            rabbit++;
            while (rabbit <= n && field[rabbit - 1] != 'R')
                rabbit++;
            updateRabbit = false;
        }
    
        if(updateCarrot) {
            carrot++;
            while (carrot <= n && field[carrot - 1] != 'C')
                carrot++;
            updateCarrot = false;
        }
    }
    return count;
}

int main()
{
    vector<char> field = {'C', 'C', 'C', 'C', 'R', 'C', 'R', 'R', 'R'};
    int range = 3;
    int ans = getHappyRabbitCount(field, range);
    cout << ans;
    return 0;
}