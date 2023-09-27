#include <iostream>

using namespace std;

int* intercala(int *vet1, int tam1, int *vet2, int tam2);

int main(){
    int i, tam_impar = 5, tam_par = 2;
    int vetor_impar[tam_impar] = {1,2,3, 4, 6};
    int vetor_par[tam_par] = {5,0};
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
    int *vetResult = new int[tamResult];
    int count1 = 0, count2 = 0;
    int i;

    for(i = 0; i < tamResult; i+=2){
        if(count1 < tam1){
            vetResult[i] = vet1[count1];
            count1++;
        }else if(count2 < tam2){
            vetResult[i] = vet2[count2];
            count2++;
        }

        if(count2 < tam2){
            vetResult[i+1] = vet2[count2];
            count2++;
        }else if(count1 < tam1){
            vetResult[i+1] = vet1[count1];
            count1++;
        }

    }

    return vetResult;
}