#include <iostream>

void multiplica_por_n(int *vet, int qtde, int n);

using namespace std;

int main(){
    int tam_vet = 5, i;
    int vetor[tam_vet] = {7,0,11,4,-4};
    int mult = 7;

    cout << "Vetor antes da multiplicacao: ";
    for(i = 0; i < tam_vet; i++)
        cout << vetor[i] << " ";
    
    multiplica_por_n(vetor, tam_vet, mult);

    cout << "\nVetor *" << mult << ": ";
    for(i = 0; i < tam_vet; i++)
        cout << vetor[i] << " ";
    cout << endl;


    return 0;
}

void multiplica_por_n(int *vet, int qtde, int n){
    int i;

    for(i = 0; i < qtde; i++)
        vet[i] *= n;

}