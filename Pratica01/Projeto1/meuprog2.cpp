#include <iostream>

using namespace std;

int main(){
    int numA, numB;

    cout << "Digite um numero inteiro A: ";
    cin >> numA;
    cout << "Digite um numero inteiro B: ";
    cin >> numB;
    
    cout << endl << "Resultado" << endl;
    cout << "Soma = " << numA + numB << endl;
    cout << "Subtração = " << numA - numB << endl;
    cout << "Multiplicação = " << numA * numB << endl;
    if (numB !=0){
        cout << "Divisao = " << numA / numB;
        cout << endl << "Resto = " << numA % numB << endl;
    }
    else
        cout << "Divisao Invalida" << endl;

    return 0;
}