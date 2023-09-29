#include <iostream>

using namespace std;

void somasub(int &x, int &y);

int main(){
    int a = 5, b=3;

    somasub(a, b);
    cout << "Soma: " << a << endl;
    cout << "Subtracao: " << b << endl;

    return 0;
}

void somasub(int &x, int &y){
    x = x + y;
    y = x - y - y;
}