#include <iostream>
#include <string>

using namespace std;

string codifica(string s);
string decodifica(string s);

int main(){
    string txt = "Estruturas de Dados";
    string mod = codifica(txt);

    cout << "Texto original: " << txt << endl;
    cout << "Texto codificado: " << mod << endl;
    cout << "Texto decodificado: " << decodifica(mod) << endl;  

    return 0;
}

string codifica(string s){
    string codificada = "";

    for(char ch : s){
        if(ch == 'z')
            codificada.push_back('a');
        else if(ch == 'Z')
            codificada.push_back('A');
        else if(isalpha(ch))
            codificada.push_back(ch+1);
        else
            codificada.push_back(ch);
    }
    return codificada;
}

string decodifica(string s){
    string decodificada = "";

    for(char ch : s){
        if(ch == 'a')
            decodificada.push_back('z');
        else if(ch == 'A')
            decodificada.push_back('Z');
        else if(isalpha(ch))
            decodificada.push_back(ch-1);
        else
            decodificada.push_back(ch);
    }
    return decodificada;
}