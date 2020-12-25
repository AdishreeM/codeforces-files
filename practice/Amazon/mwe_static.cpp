#include<iostream>

using namespace std;

class Printer {
public:
    static void print(int n);
};

void Printer::print(int n) {
    cout << "Printer has: " << n << endl;
}

int main(){
    int n;
    cin >> n;
    Printer::print(n);
    return 0;
}