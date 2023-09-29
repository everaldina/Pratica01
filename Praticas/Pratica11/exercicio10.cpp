#include <iostream>
#include <string>
using namespace std;

int* findChar(string s, char ch, int &charCount);

int main(){
    string txt = "Teste de funcao posicoes DE CARACTERES";
    char ch = 'e';
    int charCount, i;
    int *indice = findChar(txt, ch, charCount); 

    cout << "Texto: " << txt << endl;  
    cout << "Incidencias de '" << ch << "': " << charCount << endl;
    cout << "Posicoes: ";

    for (i = 0; i < charCount; i++){
        cout << indice[i] << " ";
    }
    cout << endl;

    return 0;
}

int* findChar(string s, char ch, int &charCount){
    int *pos = new int[s.length()];
    int i = 0;

    charCount = 0;
    
    ch = tolower(ch);
    for (i = 0; i < s.length(); i++){
        if (tolower(s[i]) == ch){
            pos[charCount] = i;
            charCount++;
        }
    }

    return pos;
}