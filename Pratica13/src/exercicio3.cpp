#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX_CAPACIDADE = 300;

struct Produto{
    string nome;
    float preco;
    string cod;
};

Produto iniciaProduto(string nome, float preco);
bool addProduto(vector<Produto> &estoque, string nome,  float preco); // retorna true se o produto foi adicionado
bool deleteProduto(vector<Produto> &estoque, string codigo); // retorna true se o produto foi excluido
Produto buscProduto(vector<Produto> estoque, string codigo); // retorna produto com nome "" caso nao exista produto
void listEstoque(vector<Produto> estoque);

string geraCodigo(int n); // gera um codigo com numerico de n digitos


int main(){
    vector<Produto> estoque;
    int opt;
    string input;
    float preco;
    Produto p;

    srand(time(NULL));

    do{
        cout << "1 - Adicionar produto\n";
        cout << "2 - Excluir produto\n";
        cout << "3 - Listar estoque\n";
        cout << "4 - Busca produto\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> opt;

        switch(opt){
            case 1:
                cin.ignore();
                cout << "\nDigite nome do produto: ";
                getline(cin, input);
                cout << "Digite preco: ";
                cin >> preco;

                cout << ((addProduto(estoque, input, preco))? "Produto adicionado.\n\n": "\n\n");
                break;
            case 2:
                cout << "\nDigite codigo do produto: ";
                cin >> input;

                cout << ((deleteProduto(estoque, input))? "Produto excluido.\n\n": "Produto nao encontrado.\n\n");
                break;
            case 3:
                listEstoque(estoque);
                break;
            case 4:
                cout << "\nDigite codigo do produto: ";
                cin >> input;

                p = buscProduto(estoque, input);
                input =  to_string(p.preco); // tranformando preco pra string

                // printando produto
                cout << ((p.nome != "")? "cod.:" + p.cod + " - " + p.nome + ": R$" + input.substr(0, input.find(".")+3) + "\n\n": 
                        "Produto nao encontrado.\n\n");
                break;
            case 5:
                break;
            default:
                cout << "Opcao invalida!\n";
                cout << "Opcao: ";
                cin >> opt;
                break;
        }
    }while(opt!=5); // menu so sai ao apertar opcao de sair

    return 0;
}

Produto iniciaProduto(string nome, float preco){
    Produto p;
    string aux(nome.substr(0, 20)); // inicia string de tamanho maximo 20 

    p.nome = aux;
    p.preco = (preco >= 0)? round(preco * 100) / 100 : 0.0; // preco com no maximo duas casas decimais
    p.cod = geraCodigo(13);

    return p;
}

string geraCodigo(int n){
    int i;
    char aux[n+1];

    for(i=0; i<n; i++){
        aux[i] = '0' + (rand()%10); // gera digito aleatorio entre 0-9
    }
    aux[n] = '\0'; // final da cadeia de caracteres
    string s(aux); // trasnforma cadeia em string
    return s;
}

bool addProduto(vector<Produto> &estoque, string nome, float preco){
    bool cont = false;

    // nao eh possivel armazenar mais do que a capacidade maxima
    if(estoque.size() < MAX_CAPACIDADE){ 
        Produto p = iniciaProduto(nome, preco); // inicia um produto com aparemetros
        do{ 
            // busca no estoque se ja existe produto com mesmo codigo ou nome
            for(Produto prod : estoque){ 
                if(prod.nome == p.nome){
                    cout << "Produto ja registrado.";
                    return false;
                }
                if(prod.cod == p.cod){
                    cont = true;
                    p.cod = geraCodigo(13); // se ja existe codigo gera outro
                    break;
                }else
                    cont = false;
            }
        }while(cont);
        estoque.push_back(p); // adicona produto
        return true;
    }
    cout << "Capacidade maxima atingida!!";
    return false;
}

bool deleteProduto(vector<Produto> &estoque, string codigo){
    // percorre estoque e se codigo for igual deleta o produto
    for(auto it = estoque.begin(); it != estoque.end(); it++){
        if(it->cod == codigo){ 
            estoque.erase(it);
            return true;
        }
    }
    return false;
}

Produto buscProduto(vector<Produto> estoque, string codigo){
    // inicia produto com nome "" que sera retorna caso nao seja encontrado produto
    Produto prod = {"", 0.0}; 


    for(Produto p : estoque){
        if(p.cod == codigo) // se codigo for igual retorne produto
            return p;
    }
    return prod;
}

void listEstoque(vector<Produto> estoque){
    cout << "\n\tCod.\t\tNome\t\tPreco\n";
    cout << "--------------------------------------------------------------\n";
    for( Produto prod : estoque){
        cout << prod.cod;
        cout << "\t" <<setw(20) << prod.nome;  // nome ocupa sempre 20 espacos na impressao
        cout << "\tR$" << fixed<< setprecision(2) << prod.preco << endl;
    }
    cout << endl;
}
