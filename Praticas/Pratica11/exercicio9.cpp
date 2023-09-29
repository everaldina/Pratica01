#include <iostream>

float calc_serie(int N);

using namespace std;

int main(){
    int N = 4;

    cout << "S(" << N << ") = " << calc_serie(N) << endl;

    return 0;
}

float calc_serie(int N){
    float div = N, sup = 1;
    float soma = 0;

    while(div>=1){
        soma += sup/div;
        div--;
        sup++;
    }

    return soma;
}