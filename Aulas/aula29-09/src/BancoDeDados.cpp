#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class BancoDeDados{
    public:
        static void salvarDados(vector<string> dados){
            // Abrindo um arquivo para escrita
            ofstream arquivo;
            //nomeArquivo = "dados.txt";

            arquivo.open("dados.txt", ios_base::out);

            // Verifica se o arquivo foi aberto corretamente
            if(arquivo.is_open()){
                for(string s : dados){
                    arquivo << s << endl;
                }
                arquivo.close();
            }else
                cout << "Erro ao abrir o arquivo" << endl;
        }

        static vector<string> recuperarDados(){
            vector<string> dados;

            // Abrindo um arquivo para leitura
            ifstream arquivo;
            //nomeArquivo = "dados.txt";
            arquivo.open("dados.txt", ios_base::in);

            // Verifica se o arquivo foi aberto corretamente
            if(arquivo.is_open()){
                string linha;
                while(arquivo.eof() == false){
                    getline(arquivo, linha);
                    dados.push_back(linha);
                }
                arquivo.close();
            }else
                cout << "Erro ao abrir o arquivo" << endl;
            return dados;
        }
};

int main(){
    vector<string> dados = {"Joao\n", "Maria Clara", "\nJose", " Ana\t", "Pedro"};
    vector<string> dadosRecuperados;
    //BancoDeDados::nomeArquivo = "dados.txt";

    BancoDeDados::salvarDados(dados);
    dadosRecuperados = BancoDeDados::recuperarDados();
    
    cout << "Dados recuperados: " << endl;
    for(string s : dadosRecuperados){
        cout << s;
    }

    return 0;
}