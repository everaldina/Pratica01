#include <iostream>
#include <ctime>
#include <vector>
#include <string>

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
int buscaViagem(vector<Onibus> &registros, short int dia, short int mes, int ano, short int hora, short int min, char tipo);
bool addPassageiro(vector<Onibus> &registros, Passagem passageiro, bool tipo);

// funcoes passagem
bool validarPassagem(string nome, string cpf, int idade, short int poltrona, short int min, short int hora, short int dia, short int mes, short int ano);
bool iniciarPassagem(Passagem &passageiro, string nome, string cpf, int idade, short int poltrona, short int min, short int hora, short int dia, short int mes, short int ano);
bool verificarCPF(string CPF);
string formatCPF(string CPF);
string cpfToNum(string CPF);

// funcoes teste
float totalArrecadado(vector<Onibus> &registros, short int dia, short int mes, int ano, short int hora, short int min, char tipo);
float totalArrecadado(vector<Onibus> &registros, short int mes, int ano);
string nomePassageiro(vector<Onibus> &registros, short int dia, short int mes, int ano, short int hora, short int min, char tipo, short int poltrona);
void horarioMaisRentavel(vector<Onibus> &registros, Hora &horaIdaRentavel, Hora &horaVotaRentavel);
float mediaIdade(vector<Onibus> &registros);

int main(){
    vector<Onibus> resgistroOnibus;

    // iniciando onibus
    cout << "add onibus 1: " << addOnibus(resgistroOnibus, 0, 21, 5, 2022, 10, 30) << endl; // 3 pessoas
    cout << "add onibus 2: " << addOnibus(resgistroOnibus, 1, 21, 5, 2022, 10, 30) << endl; // 2 pessoas
    cout << "add onibus 3: " << addOnibus(resgistroOnibus, 1, 21, 5, 2022, 10, 40) << endl; // 3 pessoas // mais lucrativo volta
    
    cout << "add onibus 4: " << addOnibus(resgistroOnibus, 1, 25, 5, 2022, 21, 50) << endl; // 1 pessoa
    cout << "add onibus 5: " << addOnibus(resgistroOnibus, 0, 25, 6, 2022, 21, 50) << endl; // 2 pessoa
    cout << "add onibus 6: " << addOnibus(resgistroOnibus, 0, 25, 6, 2022, 20, 0) << endl;  // 1 pessoa 
    cout << "add onibus 7: " << addOnibus(resgistroOnibus, 0, 25, 6, 2022, 10, 20) << endl; // 4 pessoa // mais lucrativo ida
    cout << endl;

    // adcionando passagens
    Passagem pass[16];
    string nomes[16] = {"João", "Maria", "Clara", "Carlos", "Jon", "Marcos", "Ana", 
                        "Joana", "Pedro", "Paulo", "Lucas", "Lucia", "Luis", "Luisa", 
                        "Larissa", "Larissa"};
    int idades[16] = {20, 19, 30, 31, 10, 31, 42, 27, 20, 19, 30, 31, 10, 31, 42, 27}; // media de idade = 26.25

    // adicionando passageiros
    for(int i = 0; i< 16;i++){
        switch (i){
            // onibus 1
            case 0:
            case 1:
            case 2:
                cout << "Adicionando passagem" << i<< ": " << iniciarPassagem(pass[i], nomes[i], "123.456.789-10", idades[i], i+1, 30, 10, 21, 5, 2022);
                break;
            // onibus 2
            case 3:
            case 4:
                cout << "Adicionando passagem" << i<< ": " << iniciarPassagem(pass[i], nomes[i], "123.456.789-10", idades[i], i+1, 30, 10, 21, 5, 2022);
                break;
            // onibus 3
            case 5:
            case 6:
            case 7:
                cout << "Adicionando passagem" << i<< ": " << iniciarPassagem(pass[i], nomes[i], "123.456.789-10", idades[i], i+1, 40, 10, 21, 5, 2022);
                break;
            // onibus 4
            case 8:
                cout << "Adicionando passagem" << i<< ": " << iniciarPassagem(pass[i], nomes[i], "123.456.789-10", idades[i], i+1, 50, 21, 25, 5, 2022);
                break;
            // onibus 5
            case 9:
            case 10:
                cout << "Adicionando passagem" << i<< ": " << iniciarPassagem(pass[i], nomes[i], "123.456.789-10", idades[i], i+1, 50, 21, 25, 6, 2022);
                break;
            // onibus 6
            case 11:
                cout << "Adicionando passagem" << i<< ": " << iniciarPassagem(pass[i], nomes[i], "123.456.789-10", idades[i], i+1, 0, 20, 25, 6, 2022);
                break;
            // onibus 7
            case 12:
            case 13:
            case 14:
            case 15:
                cout << "Adicionando passagem" << i<< ": " << iniciarPassagem(pass[i], nomes[i], "123.456.789-10", idades[i], i+1, 20, 10, 25, 6, 2022);
                break;
        }
        cout << endl << endl;
    }

    // adicionando passageiros aos onibus
    for(int i = 0; i< 16;i++){
        switch (i){
            // onibus 1
            case 0:
            case 1:
            case 2:
                cout << "Adicionando passageiro" << i<< ": " << addPassageiro(resgistroOnibus, pass[i], 0);
                break;
            // onibus 2, 3, 4
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                cout << "Adicionando passageiro" << i<< ": " << addPassageiro(resgistroOnibus, pass[i], 1);
                break;
            // onibus 5, 6, 7
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                cout << "Adicionando passageiro" << i<< ": " << addPassageiro(resgistroOnibus, pass[i], 0);
                break;
        }
        cout << endl << endl;
    }

    //1. Qual o total arrecadado para uma determinada viagem.
    cout << "Viagem 1 - qntdPassageiros = " << resgistroOnibus[0].qntdPassagens << 
            " | Total arregadado: " << totalArrecadado(resgistroOnibus, 21, 5, 2022, 10, 30, 0) << endl; // 3 pessoas * 80
    cout << "Viagem 2 - qntdPassageiros = " << resgistroOnibus[1].qntdPassagens << 
            " | Total arregadado: " <<  totalArrecadado(resgistroOnibus, 21, 5, 2022, 10, 30, 1) << endl; // 2 pessoas * 80
    cout << "Viagem 3 - qntdPassageiros = " << resgistroOnibus[2].qntdPassagens << 
            " | Total arregadado: " << totalArrecadado(resgistroOnibus, 21, 5, 2022, 10, 40, 1) << endl; // 3 pessoas * 80
    cout << "Viagem 4 - qntdPassageiros = " << resgistroOnibus[3].qntdPassagens << 
            " | Total arregadado: " <<  totalArrecadado(resgistroOnibus, 25, 5, 2022, 21, 50, 1) << endl; // 1 pessoa * 80
    cout << "Viagem 5 - qntdPassageiros = " << resgistroOnibus[4].qntdPassagens << 
            " | Total arregadado: " <<  totalArrecadado(resgistroOnibus, 25, 6, 2022, 21, 50, 0) << endl; // 2 pessoa * 80
    cout << "Viagem 6 - qntdPassageiros = " << resgistroOnibus[5].qntdPassagens << 
            " | Total arregadado: " << totalArrecadado(resgistroOnibus, 25, 6, 2022, 20, 0, 0) << endl; // 1 pessoa * 80
    cout << "Viagem 7 - qntdPassageiros = " << resgistroOnibus[6].qntdPassagens << 
            " | Total arregadado: " << totalArrecadado(resgistroOnibus, 25, 6, 2022, 10, 20, 0) << endl; // 4 pessoa * 80

    //2. Qual o total arrecadado em um determinado mês.
    cout << "Total arregadado em maio de 2022: " << totalArrecadado(resgistroOnibus, 5, 2022) << endl; // onibus 1 (3 pessoas), 2 (2 pessoas) e 3 (3 pessoas) e 4 (1 pessoa)
    cout << "Total arregadado em junho de 2022: " << totalArrecadado(resgistroOnibus, 6, 2022) << endl << endl; // 5 (2 pessoas), 6 (1 pessoa) e 7 (4 pessoas)

    //3. Qual o nome do passageiro de uma determinada poltrona P de uma determinada viagem.
    // mostrando passageiros dos onibus 1,
    string nome;
    for (int i = 0; i < POLTRONAS; i++){
        nome = nomePassageiro(resgistroOnibus, 21, 5, 2022, 10, 30, 0, i+1);
        if (nome != "")
            cout << "Onibus 1 - poltrona " << i+1 << ": " << nome << endl;
    }
    // mostrando passageitos dos onibus 4
    for (int i = 0; i < POLTRONAS; i++){
        nome = nomePassageiro(resgistroOnibus, 25, 5, 2022, 21, 50, 1, i+1);
        if (nome != "")
            cout << "Onibus 4 - poltrona " << i+1 << ": " << nome << endl;
    }
    // mostrando passageitos dos onibus 7
    for (int i = 0; i < POLTRONAS; i++){
        nome = nomePassageiro(resgistroOnibus, 25, 6, 2022, 10, 20, 0, i+1);
        if (nome != "")
            cout << "Onibus 7 - poltrona " << i+1 << ": " << nome << endl;
    }
    cout << endl << endl; 

    //4. Qual o horário de viagem mais rentável.
    Hora horaIdaRentavel, horaVotaRentavel;
    horarioMaisRentavel(resgistroOnibus, horaIdaRentavel, horaVotaRentavel);
    cout << "Horario mais rentavel ida: " << horaIdaRentavel.hora << ":" << horaIdaRentavel.min << endl;
    cout << "Horario mais rentavel volta: " << horaVotaRentavel.hora << ":" << horaVotaRentavel.min << endl << endl;

    //5. Qual a média de idade dos passageiros.
    float media = mediaIdade(resgistroOnibus);
    cout << "Media de idade dos passageiros: " << media << endl << endl;

    return 0;
}

// 1
float totalArrecadado(vector<Onibus> &registros, short int dia, short int mes, int ano, short int hora, short int min, char tipo){
    int indice = buscaViagem(registros, dia, mes, ano, hora, min, tipo);
    if(indice != -1){
        return registros[indice].qntdPassagens * PRECO_PASSAGEM;
    }
    return -1;
}

// 2
float totalArrecadado(vector<Onibus> &registros, short int mes, int ano){
    float total = 0;
    for(Onibus p : registros){
        if(p.passageiros[0].data.mes == mes && p.passageiros[0].data.ano == ano){
            total += p.qntdPassagens * PRECO_PASSAGEM;
        }
    }
    return total;
}

// 3
string nomePassageiro(vector<Onibus> &registros, short int dia, short int mes, int ano, short int hora, short int min, char tipo, short int poltrona){
    int indice = buscaViagem(registros, dia, mes, ano, hora, min, tipo);
    if(indice != -1){
        return registros[indice].passageiros[poltrona-1].nome;
    }
    return "";
}

// 4
void horarioMaisRentavel(vector<Onibus> &registros, Hora &horaIdaRentavel, Hora &horaVotaRentavel){
    int i, maiorIda = 0, maiorVolta = 0, rent;
    short int horaI, minI, horaV, minV;

    for(i=0; i<registros.size(); i++){
        rent = registros[i].qntdPassagens;
        if(registros[i].tipo == 0 && rent > maiorIda){
            maiorIda = registros[i].qntdPassagens;
            horaI = registros[i].passageiros[0].hora.hora;
            minI = registros[i].passageiros[0].hora.min;
        }else if(registros[i].tipo == 1 && rent > maiorVolta){
            maiorVolta = registros[i].qntdPassagens;
            horaV = registros[i].passageiros[0].hora.hora;
            minV = registros[i].passageiros[0].hora.min;
        }
    }
    iniciarHora(horaIdaRentavel, horaI, minI);
    iniciarHora(horaVotaRentavel, horaV, minV);
}

// 5
float mediaIdade(vector<Onibus> &registros){
    int i, qntdPassageiros = 0;
    float soma = 0;
    for(i = 0; i<registros.size(); i++){
        for(Passagem p : registros[i].passageiros){
            if(p.poltrona != 0){
                soma += p.idade;
                qntdPassageiros++;
            }
        }
    }
    return soma/qntdPassageiros;
}


bool addOnibus(vector<Onibus> &registros, char tipo, short int dia, short int mes, int ano, short int hora, short int min){
    int countViagens = 0;
    Onibus oni;
    bool valido;

    for(Onibus p : registros){
        if(p.passageiros[0].data.dia == dia && p.passageiros[0].data.mes == mes && p.passageiros[0].data.ano == ano){
            if(p.tipo == tipo){
                if(p.passageiros[0].hora.hora == hora && p.passageiros[0].hora.min == min)
                    return false;
                else
                    countViagens++;
            }
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

int buscaViagem(vector<Onibus> &registros, short int dia, short int mes, int ano, short int hora, short int min, char tipo){
    int i;
    for(i = 0; i<registros.size(); i++){
        if(registros[i].passageiros[0].data.dia == dia && registros[i].passageiros[0].data.mes == mes && registros[i].passageiros[0].data.ano == ano){
            if(registros[i].passageiros[0].hora.hora == hora && registros[i].passageiros[0].hora.min == min){
                if(registros[i].tipo == tipo)
                    return i;
            }
        }
    }
    // caso nao encontre, retorna indice -1
    return -1;
}

bool addPassageiro(vector<Onibus> &registros, Passagem passageiro, bool tipo){
    int indice = buscaViagem(registros, passageiro.data.dia, passageiro.data.mes, passageiro.data.ano, passageiro.hora.hora, passageiro.hora.min, tipo);
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