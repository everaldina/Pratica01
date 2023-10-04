#include <iostream>
#include <string>   
#include <vector>

using namespace std;

class Estado{
    private:
        string nome;
        string uf;
    public:
        Estado(string nome = "", string uf = ""){
            this->nome = nome;
            this->uf = uf;
        }

        void setNome(string nome){
            this->nome = nome;
        }
        void setUf(string uf){
            this->uf = uf;
        }

        string getNome(){
            return nome;
        }
        string getUf(){
            return uf;
        }
};

class Cidade{
    private:
        string nome;
        Estado *estado;
    public:
        Cidade(string nome = "", Estado *estado = nullptr){
            this->nome = nome;
            this->estado = estado;
        }

        void setNome(string nome){
            this->nome = nome;
        }
        void setEstado(Estado *estado){
            this->estado = estado;
        }

        string getNome(){
            return nome;
        }
        Estado *getEstado(){
            return estado;
        }
};

int main(){
    vector<Estado> estados;
    vector<Cidade> cidades;
    bool continuar = true, achou = false;
    string cidade, uf, estado;
    

    cout << "Cadastro de estados: " << endl;
    while(continuar){
        cout << "Digite o nome do estado: ";
        getline(cin, estado);
        cout << "Digite a UF do estado: ";
        getline(cin, uf);

        for (Estado e : estados){
            if(e.getNome() == estado){
                cout << "Estado ja cadastrado" << endl;
                achou = true;
                break;
            }
        }

        if(!achou)
            estados.push_back(Estado(estado, uf));
        achou = false;

        cout << "Deseja continuar (0/1)? ";
        cin >> continuar;
        cin.ignore();
    }

    cout << "\n\nCadastro de cidades: " << endl;
    continuar = true;
    while(continuar){
        string nome;
        cout << "Digite o nome da cidade: ";
        getline(cin, cidade);
        cout << "Digite o nome do estado: ";
        getline(cin, estado);

        for(Estado e : estados){
            if(e.getNome() == estado){
                for (Cidade c : cidades){
                    if(c.getNome() == cidade){
                        cout << "Cidade ja cadastrada" << endl;
                        achou = true;
                        break;
                    }
                }
                if(!achou)
                    cidades.push_back(Cidade(cidade, &e));
                break;
            }
        }
        
        achou = false;

        cout << "Deseja continuar (0/1)? ";
        cin >> continuar;
        cin.ignore();
    }


    cout << "\n\nEstados cadastrados: " << endl;
    for(Estado e : estados){
        cout << e.getNome() << " - " << e.getUf() << endl;
    }
    cout << "\nCidades cadastradas: " << endl;
    for(Cidade c : cidades){
        cout << c.getNome() << " - " << c.getEstado()->getNome() << endl;
    }

    return 0;
}