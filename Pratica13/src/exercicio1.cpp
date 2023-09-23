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

struct Onibus{
    Passagem poltronas[POLTRONAS];
    int qntdPassagens = 0;
};

// funcoes de validacao data hora
bool validarData(short int dia, short int mes, int ano);
bool validarHora(short int hora, short int min);
bool isBissexto(short int ano);

// funcoes de onibus
bool addOnibus(vector<Onibus> &registros, char tipo, short int dia, short int mes, int ano, short int hora, short int min);
bool iniciarOnibus(Onibus &onibus, char tipo, short int dia, short int mes, int ano, short int hora, short int min);

int main(){
    vector<Onibus> resgistroOnibus;



    return 0;
}

bool addOnibus(vector<Onibus> &registros, char tipo, short int dia, short int mes, int ano, short int hora, short int min){
    int countViagens = 0;
    Onibus oni;
    bool valido;

    for(Onibus p : registros){
        if(p.poltronas[0].dia == dia && p.poltronas[0].mes == mes && p.poltronas[0].ano == ano){
            if(p.poltronas[0].tipo == tipo)
                countViagens++;
        }
    }

    if(countViagens <= VIAGENS_DIA){
        valido = iniciarOnibus(oni, tipo, dia, mes, ano, hora, min);
        if(valido){
            registros.push_back(oni);
            return true;
        }
    }
    return false;
}

bool iniciarOnibus(Onibus &onibus, char tipo, short int dia, short int mes, int ano, short int hora, short int min){
    int i;

    if(validarData(dia, mes, ano) && validarHora(hora, min)){
        for(i=0; i<POLTRONAS; i++){
            onibus.poltronas->poltrona = i;
            onibus.poltronas->tipo = tipo;
            onibus.poltronas->min = min;
            onibus.poltronas->hora = hora;
            onibus.poltronas->dia = dia;
            onibus.poltronas->mes = mes;
            onibus.poltronas->ano = ano;
        }
        return true;
    }else{
        cout << "Data ou hora invalida" << endl;
    }
    return false;

}

bool validarData(short int dia, short int mes, int ano){
    if(dia>=1 && mes>=1 && mes<=12){
        if(mes == 2 && isBissexto(ano) && dia<=29) // caso fevereiro e ano bissexto
            return true;
        if(mes == 2 && dia<=28) // caso fevereiro e ano bissexto 
            return true;
        if((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && dia<=31) //meses com 31 dias
            return true;
        if((mes==4 || mes==6 || mes==9 || mes==11) && dia<=30) // meses com 30 dias
            return true;
        return false;
    }
    return false;
}

bool validarHora(short int hora, short int min){
    if(hora<=24 && hora>=0 && min>=0 && min<=59)
        return true;
    else
        return false;
}

bool isBissexto(short int ano){
    if(( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0)
        return true;
    else
        return false;
}