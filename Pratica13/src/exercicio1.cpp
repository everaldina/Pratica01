#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const int POLTRONAS = 40;
const int VIAGENS_DIA = 5;
const float PRECO_PASSAGEM = 80.0;

struct Passagem{
    string nome;
    bool tipo; // ida RJ --> SP (0) ou volta RJ <-- SP (1)
    int poltrona;
    int ano;
    short int mes;
    short int dia;
    short int hora;
    short int min;
};

int main(){
    vector<Passagem[40]> onibus;



    return 0;
}

void addOnibus(vector<Passagem[40]> &onibus, char tipo, short int dia, short int mes, int ano, short int hora, short int min){
    int countViagens = 0;


}

bool iniciarOnibus(Passagem &passagens, char tipo, short int dia, short int mes, int ano, short int hora, short int min){
    int i;

    if(dia>=1 && mes>=1 && mes<=12 && hora<=24 && hora>=0 && min>=0 && min<=59){
        if((mes == 2 && isBissexto(ano) && dia<=29) || // caso fevereiro e ano bissexto
            (mes == 2 && dia<=28) || // caso fevereiro e ano bissexto
            ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && dia<=31) || //meses com 31 dias
            ((mes==4 || mes==6 || mes==9 || mes==11) && dia<=30)) // meses com 30 dias
            {
            for(i=0; i<POLTRONAS; i++){
                passagens.poltrona = i;
                passagens.tipo = tipo;
                passagens.min = min;
                passagens.hora = hora;
                passagens.dia = dia;
                passagens.mes = mes;
                passagens.ano = ano;
            }
            return true;
        }
        return false;
    }
    return false;

}

bool isBissexto(short int ano){
    if(( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0)
        return true;
    else
        return false;
}