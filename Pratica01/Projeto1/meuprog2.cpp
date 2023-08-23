#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float numA, numB;

    cout << "Digite um numero real A: ";
    cin >> numA;
    cout << "Digite um numero real B: ";
    cin >> numB;
    
    cout << fixed;
    cout << setprecision(1);
    cout << endl << "Resultado" << endl;
    cout << "Soma = " << numA + numB << endl;
    cout << "Subtração = " << numA - numB << endl;
    cout << "Multiplicação = " << numA * numB << endl;
    if (numB !=0){
        cout << "Divisao = " << numA / numB << endl;
    }
    else
        cout << "Divisao Invalida" << endl;

    return 0;
}