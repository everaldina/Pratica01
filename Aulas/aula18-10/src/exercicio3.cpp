#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>

class Lista{
    private:
        vector<T> lista;
    public:

        vector<T> getLista(){
            return lista;
        }

        void adicionarItem(T elemento){
            lista.push_back(elemento);
        }

        bool removerItem(T elemento){
            for(int i = 0; i < lista.size(); i++){
                if(lista[i] == elemento){
                    lista.erase(lista.begin() + i);
                    return true;
                }
            }
            return false;
        }

        void imprimirLista(){
            for(int i = 0; i < lista.size(); i++){
                cout << lista[i] << endl;
            }
        }

};

int main(){
    Lista<int> listaInt;
    Lista<string> listaString;
    Lista<float> listaFloat;

    // lista int
    cout << "Lista int: " << endl;
    listaInt.adicionarItem(1);
    listaInt.adicionarItem(2);
    listaInt.adicionarItem(3);
    listaInt.adicionarItem(4);
    
    listaInt.imprimirLista();

    listaInt.removerItem(2);
    listaInt.removerItem(4);
    listaInt.removerItem(10);

    cout << "Nova Lista: " << endl;
    listaInt.imprimirLista();


    // lista string
    cout << "\nLista string: " << endl;
    listaString.adicionarItem("alfabeto");
    listaString.adicionarItem("casa");
    listaString.adicionarItem("carro");
    listaString.adicionarItem("cachorro");

    listaString.imprimirLista();

    listaString.removerItem("casa");
    listaString.removerItem("papagaio");
    listaString.removerItem("carro");

    cout << "Nova Lista: " << endl;
    listaString.imprimirLista();


    // lista float  
    cout << "\nLista float: " << endl;
    listaFloat.adicionarItem(1.1);
    listaFloat.adicionarItem(2);
    listaFloat.adicionarItem(3.1415);
    listaFloat.adicionarItem(4.5);

    listaFloat.imprimirLista();

    listaFloat.removerItem(2.01);
    listaFloat.removerItem(0);
    listaFloat.removerItem(1.11);
    listaFloat.removerItem(3.1415);

    cout << "Nova Lista: " << endl;
    listaFloat.imprimirLista();



    return 0;
}