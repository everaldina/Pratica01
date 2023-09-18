#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Empregado{
    string nome = "";
    string sobrenome = "";
    int anoNascimento = 0;
    string RG = "";
    int anoAdmissao = 0;
    float salario = 0.0;
} empregados[50];

void Reajuste_dez_porcento(Empregado* empregados, int qntd);
void printEmpregados(Empregado* empregados, int qntd);

int main(){
    int qntd = 0;
    bool cont = true;
    char ch;

    // adiciona empregados
    do{ 
        cout << "Nome do empregado: ";
        cin >> empregados[qntd].nome;
        cout << "Sobrenome do empregado: ";
        cin >> empregados[qntd].sobrenome;

        do{ // checa se ano de nascimento eh valido
            cout << "Ano de nascimento: ";
            cin >> empregados[qntd].anoNascimento;
            if(empregados[qntd].anoNascimento < 0)
                cout << "Ano de nascimento invalido!" << endl;
        }while(empregados[qntd].anoNascimento < 0);

        cout << "RG: ";
        cin >> empregados[qntd].RG;
        do{ // checa se ano de admissao eh valido
            cout << "Ano de admissao: ";
            cin >> empregados[qntd].anoAdmissao;
            if(empregados[qntd].anoAdmissao < empregados[qntd].anoNascimento)
                cout << "Ano de admissao invalido!" << endl;
        }while(empregados[qntd].anoAdmissao <= empregados[qntd].anoNascimento);
        
        do{ // checa se salario eh valido
            cout << "Salario: ";
            cin >> empregados[qntd].salario;
            if(empregados[qntd].salario <= 0)
                cout << "Salario invalido!" << endl;
        }while(empregados[qntd].salario <=0);
        qntd++;

        cout << "\nDeseja continuar (s/n)? ";
        cin >> ch;
        ch = tolower(ch);
        cont = (ch == 's') ? true : false;
    }while(cont);

    cout << endl << "Empregados cadastrados: " << endl;
    printEmpregados(empregados, qntd);

    Reajuste_dez_porcento(empregados, qntd);
    cout << endl << "\nSalarios atualizados:" << endl;
    printEmpregados(empregados, qntd);

    return 0;
}

void Reajuste_dez_porcento(Empregado* empregados, int qntd){
    int i;

    for (i=0; i<qntd; i++)
        empregados[i].salario *= 1.1;
}

void printEmpregados(Empregado* empregados, int qntd){
    int i;

    for(i=0; i<qntd; i++)
        cout << empregados[i].nome << " " << empregados[i].sobrenome << " |\tNasc: " << empregados[i].anoNascimento << "\tRG: " << empregados[i].RG << "\tAdmissao: " << empregados[i].anoAdmissao << "\tSalario: " << fixed << setprecision(2)<< empregados[i].salario << endl;
}