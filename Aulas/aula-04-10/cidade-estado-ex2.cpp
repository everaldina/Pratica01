#include <iostream>
#include <string>   
#include <vector>

using namespace std;


class Cidade{
    private:
        string nome;
    public:
        Cidade(string nome = ""){
            this->nome = nome;
        }

        void setNome(string nome){
            this->nome = nome;
        }

        string getNome(){
            return nome;
        }
};

class Estado{
    private:
        string nome;
        string uf;
        vector<Cidade> cidades;
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

        vector<Cidade> getCidades(){
            return cidades;
        }
        void setCidades(vector<Cidade> cidades){
            this->cidades = cidades;
        }
        void setCidade(int index, Cidade cidade){
            cidades.at(index) = cidade;
        }
        bool addCidade(Cidade cidade){
            int index = buscCidade(cidade.getNome());

            if (index == -1){
                cidades.push_back(cidade);
                return true;
            }else{
                return false;
            }
        }

        int buscCidade(string cidade){
            for(int i = 0; i < cidades.size(); i++){
                if(cidades.at(i).getNome() == cidade)
                    return i;
            }
            return -1;
        }

        void listaCidades(){
            for(Cidade c : cidades){
                cout << c.getNome() << endl;
            }
        }

        string toString(){
            return nome + " - " + uf;
        }
};

int main(){
    vector<Estado> estados;
    bool continuar = true, achou;
    string cidade, uf, estado;
    

    cout << "Cadastro de estados: " << endl;
    while(continuar){
        cout << "Digite o nome do estado: ";
        getline(cin, estado);
        cout << "Digite a UF do estado: ";
        getline(cin, uf);

        for (Estado e : estados){
            if(e.getNome() == estado){
                cout << "Estado já cadastrado" << endl;
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
        cout << endl;
    }

    cout << "\n\nCadastro de cidades: " << endl;
    continuar = true;
    for (Estado e : estados){
        while(continuar){
            cout << "Deseja cadastrar uma cidade em "<< e.toString() << " (0/1)? ";
            cin >> continuar;
            cin.ignore();
            cout << endl; 
            if(continuar){
                cout << "Digite o nome da cidade: ";
                getline(cin, cidade);
                e.addCidade(cidade);
            }else
                break;
        }
    }


    cout << "\n\nEstados cadastrados: " << endl;
    for(Estado e : estados){
        cout << e.getNome() << " - " << e.getUf() << endl;
    }
    cout << "\nCidades cadastradas: " << endl;
    for(Estado e  : estados){
        e.listaCidades();
        cout << endl;
    }

    return 0;
}