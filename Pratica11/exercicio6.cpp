#include <iostream>

using namespace std;

int* intercala(int *vet1, int tam1, int *vet2, int tam2);

int main(){
    int i, tam_impar = 7, tam_par = 6;
    int vetor_impar[7] = {1,2,3,4,5,6,7};
    int vetor_par[6] = {1,2,3,4,5,6};
    int *result;

    cout << "Vetor par: ";
    for(i = 0; i < tam_par; i++)
        cout << vetor_par[i] << " ";
    cout << "\nVetor impar: ";
    for(i = 0; i < tam_impar; i++)
        cout << vetor_impar[i] << " ";

    result = intercala(vetor_par, tam_par, vetor_par, tam_par);
    cout << "\n\nVetor par + par: ";
    for(i = 0; i < tam_par*2; i++)
        cout << result[i] << " ";
    result = intercala(vetor_par, tam_par, vetor_impar, tam_impar);
    cout << "\nVetor par + impar: ";
    for(i = 0; i < tam_par + tam_impar; i++)
        cout << result[i] << " ";
    result = intercala(vetor_impar, tam_impar, vetor_par, tam_par);
    cout << "\nVetor impar + par: ";
    for(i = 0; i < tam_par + tam_impar; i++)
        cout << result[i] << " ";
    result = intercala(vetor_impar, tam_impar, vetor_impar, tam_impar);
    cout << "\nVetor impar + impar: ";
    for(i = 0; i < tam_impar*2; i++)
        cout << result[i] << " ";

    return 0;
}

int* intercala(int *vet1, int tam1, int *vet2, int tam2){
    int tamResult = tam1 + tam2;
    int vetResult[tamResult];
    int i;

    for(i = 0; i < tamResult; i+=2){
        cout << ".";
        if(i/2 < tam1)
            vetResult[i] = vet1[i/2];
        else
            vetResult[i] = vet2[i/2];

        if(i/2 < tam2)
            vetResult[i+1] = vet2[i/2];
        else
            vetResult[i+1] = vet1[i/2];
    }

    cout << "-";
    return vetResult;
}