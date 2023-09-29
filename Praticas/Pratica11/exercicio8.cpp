#include <iostream>

int conta_primos (int *vet, int qtde);
bool isPrimo(int n);

using namespace std;

int main(){
    int tam = 7, i;
    int vet[tam] = {0, 8, 1, 2, 9, 10, 7};

    cout << "Vetor: ";
    for(i=0; i<tam; i++)
        cout << vet[i] << " ";

    cout << "\nQuantidade de primos: " << conta_primos(vet, tam) << endl;


    return 0;
}

int conta_primos (int *vet, int qtde){
    int i, countPrim = 0;

    for(i=0; i<qtde; i++){
        if(isPrimo(vet[i]))
            countPrim++;
    }

    return countPrim;
}

bool isPrimo(int num){
    int i;

    if(num < 2 )
        return false;
    else if(num == 2)
        return true;
    else{
        for(i=2; i<=num/2; i++){
            if(num%i == 0)
                return false;
        }
        return true;
    }
    
}