#include <iostream>

using namespace std;

void maxmin(int vetor[], int n, int &maximo, int &minimo);

int main(){
    int numeros[10] = {2, -3, 5, 12, 1, 3, 1, 10, 0, 4};
    int max, min;

    maxmin(numeros, 10, max, min);

    cout << "Maximo: " << max << endl;
    cout << "Minimo: " << min << endl;

    return 0;
}

void maxmin(int num[], int n, int &maximo, int &minimo){
    int i;

    maximo = minimo = 0;
    for(i=0; i<n; i++){
        if(num[i] > maximo)
            maximo = num[i];
        if(num[i] < minimo)
            minimo = num[i];
    }
}