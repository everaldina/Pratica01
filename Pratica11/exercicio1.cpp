#include <iostream>

using namespace std;

void maxmin(int num[], int n, int &max, int &min){
    int i;

    max = min = 0;
    for(i=0; i<n; i++){
        if(num[i] > max)
            max = num[i];
        if(num[i] < min)
            min = num[i];
    }
}

int main(){
    int numeros[10] = {2, -3, 5, 12, 1, 3, 1, 10, 0, 4};
    int max, min;

    maxmin(numeros, 10, max, min);

    cout << "Maximo: " << max << endl;
    cout << "Minimo: " << min << endl;

}