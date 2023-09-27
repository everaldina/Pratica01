#include <iostream>

using namespace std;

int insere_meio( int *vetor, int qtde, int elemento);

int main(){
    int i, tam_impar = 7, tam_par = 6;
    int vetor_impar[7] = {1,2,3,4,5,6,7};
    int vetor_par[6] = {1,2,3,4,5,6};

    cout << "Vetor (par) antes da insercao: ";
    for(i = 0; i < tam_par; i++)
        cout << vetor_par[i] << " ";

    tam_par = insere_meio(vetor_par, tam_par, 0);

    cout << "\nVetor (par) depois da insercao: ";
    for(i = 0; i < tam_par; i++)
        cout << vetor_par[i] << " ";


    cout << "\n\nVetor (impar) antes da insercao: ";
    for(i = 0; i < tam_impar; i++)
        cout << vetor_impar[i] << " ";

    tam_impar = insere_meio(vetor_impar, tam_impar, 0);

    cout << "\nVetor (impar) depois da insercao: ";
    for(i = 0; i < tam_impar; i++)
        cout << vetor_impar[i] << " ";
    
    return 0;
}

int insere_meio( int *vetor, int qtde, int elemento){
    int i;

    for (i = qtde; i >= qtde/2; i--){
        if(i == qtde/2){
            vetor[i] = elemento;
            break;
        }else
            vetor[i] = vetor[i-1];
    }

    return ++qtde;

}