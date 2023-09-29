#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const int POLTRONAS = 40;
const int VIAGENS_DIA = 5;
const float PRECO_PASSAGEM = 80.0;


struct Data{
    short int dia;
    short int mes;
    int ano;
};

struct Hora{
    short int hora;
    short int min;
};
struct Passagem{
    string nome;
    string cpf;
    int idade;
    short int poltrona;
    Data data;
    Hora hora;
};

struct Onibus{
    Passagem passageiros[POLTRONAS];
    int qntdPassagens = 0;
    bool tipo; // ida RJ --> SP (0) ou volta RJ <-- SP (1)
};

// funcoes de validacao data hora
bool iniciarData(Data &data, short int dia, short int mes, int ano);
bool validarData(short int dia, short int mes, int ano);
bool iniciarHora(Hora &horario, short int hora, short int min);
bool validarHora(short int hora, short int min);
bool isBissexto(short int ano);

// funcoes de onibus
bool addOnibus(vector<Onibus> &registros, char tipo, short int dia, short int mes, int ano, short int hora, short int min);
bool iniciarOnibus(Onibus &onibus, char tipo, short int dia, short int mes, int ano, short int hora, short int min);
int buscaViagem(vector<Onibus> &registros, short int dia, short int mes, int ano, char tipo);
bool addPassageiro(vector<Onibus> &registros, Passagem passageiro, bool tipo);

// funcoes passagem
bool validarPassagem(string nome, string cpf, int idade, short int poltrona, short int min, short int hora, short int dia, short int mes, short int ano);
bool iniciarPassagem(Passagem &passageiro, string nome, string cpf, int idade, short int poltrona, short int min, short int hora, short int dia, short int mes, short int ano);
bool verificarCPF(string CPF);
string formatCPF(string CPF);
string cpfToNum(string CPF);

int main(){
    vector<Onibus> resgistroOnibus;



    return 0;
}

bool addOnibus(vector<Onibus> &registros, char tipo, short int dia, short int mes, int ano, short int hora, short int min){
    int countViagens = 0;
    Onibus oni;
    bool valido;

    for(Onibus p : registros){
        if(p.passageiros[0].data.dia == dia && p.passageiros[0].data.mes == mes && p.passageiros[0].data.ano == ano){
            if(p.tipo == tipo)
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
    Data data;
    Hora horario;

    if(iniciarData(data, dia, mes, ano) && iniciarHora(horario, hora, min)){
        onibus.tipo = tipo;
        for(i=0; i<POLTRONAS; i++){
            onibus.passageiros[i].poltrona = 0; // todas as poltronas vazias
            onibus.passageiros[i].data = data;
            onibus.passageiros[i].hora = horario;
        }
        return true;
    }else{
        onibus.tipo = tipo;
        for(i=0; i<POLTRONAS; i++){
            onibus.passageiros[i].poltrona = 0;
            onibus.passageiros[i].data = data;
            onibus.passageiros[i].hora = horario;
        }
        return false;   
    }

}

int buscaViagem(vector<Onibus> &registros, short int dia, short int mes, int ano, char tipo){
    int i;
    for(i = 0; i<registros.size(); i++){
        if(registros[i].passageiros[0].data.dia == dia && registros[i].passageiros[0].data.mes == mes && registros[i].passageiros[0].data.ano == ano){
            if(registros[i].tipo == tipo)
                return i;
        }
    }
    // caso nao encontre, retorna indice -1
    return -1;
}

bool addPassageiro(vector<Onibus> &registros, Passagem passageiro, bool tipo){
    int indice = buscaViagem(registros, passageiro.data.dia, passageiro.data.mes, passageiro.data.ano, tipo);
    if(indice != -1){
        if(registros[indice].passageiros[passageiro.poltrona].poltrona == 0){
            registros[indice].passageiros[passageiro.poltrona] = passageiro;
            registros[indice].qntdPassagens++;
            return true;
        }
    }
    return false;
}

bool validarPassagem(string nome, string cpf, int idade, short int poltrona, short int min, short int hora, short int dia, short int mes, short int ano){
    if(idade >= 0 && poltrona >= 1 && poltrona <= POLTRONAS){
        if(validarData(dia, mes, ano) && validarHora(hora, min) && verificarCPF(cpfToNum(cpf))){
            return true;
        }
    }
    return false;
}

bool iniciarPassagem(Passagem &passageiro, string nome, string cpf, int idade, short int poltrona, short int min, short int hora, short int dia, short int mes, short int ano){
    if(validarPassagem(nome, cpf, idade, poltrona, min, hora, dia, mes, ano)){
        passageiro.nome = nome;
        passageiro.cpf = cpf;
        passageiro.idade = idade;
        passageiro.poltrona = poltrona;
        iniciarData(passageiro.data, dia, mes, ano);
        iniciarHora(passageiro.hora, hora, min);
        return true;
    }else{
        passageiro.nome = "";
        passageiro.cpf = "";
        passageiro.idade = 0;
        passageiro.poltrona = 0;
        iniciarData(passageiro.data, 0, 0, 0);
        iniciarHora(passageiro.hora, 0, 0);
        return false;
    }
}

bool verificarCPF(string CPF){
    if(CPF.length() == 11){ // apenas numeros
        for(char ch : CPF){
            if(!isdigit(ch))
                return false;
        }
        return true;
    }
    return false;
}

string cpfToNum(string CPF){
    string cpfNum = "";
    for(char ch : CPF){
        if(isdigit(ch))
            cpfNum += ch;
    }
    return cpfNum;
}

string formatCPF(string CPF){
    string cpfFormat = "";
    for(int i=0; i<CPF.length(); i++){
        if(i==3 || i==6){
            cpfFormat += '.';
        }else if(i==9){
            cpfFormat += '-';
        }
        cpfFormat += CPF[i];
    }
    return cpfFormat;
}

bool iniciarData(Data &data, short int dia, short int mes, int ano){
    if(validarData(dia, mes, ano)){
        data.dia = dia;
        data.mes = mes;
        data.ano = ano;
        return true;
    }else{
        data.dia = 0;
        data.mes = 0;
        data.ano = 0;
        return false;
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

bool iniciarHora(Hora &horario, short int hora, short int min){
    if(validarHora(hora, min)){
        horario.hora = hora;
        horario.min = min;
        return true;
    }else{
        horario.hora = 0;
        horario.min = 0;
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