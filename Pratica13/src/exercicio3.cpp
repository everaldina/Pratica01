#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Produto{
    string nome[20];
    float preco;
    string cod[14];
};

bool addProduto(vector<Produto> estoque, string nome, int qntd, float preco); // retorna true se o produto foi adicionado
string geraCodigo(int n);
bool checkCodigo(vector<Produto> estoque, string cod);
void attEstoque(vector<Produto> &estoque, string nome, int mov);
float valorTotalEstoque(vector<Produto> &estoque){
    float total = 0;
    for( Produto &prod : estoque){
        total += prod.preco * prod.quantidade;
    }
    return total;
}

void listEstoque(vector<Produto> &estoque){
    int i = 1;
    cout << "\tProduto\t\tQuantidade\tPreco\n";
    for( Produto &prod : estoque){
        cout << i++ << "-\t" << prod.nome << "\t\t" << prod.quantidade << "\t\tR$" << prod.preco << endl;
    }
}

void menu(){
    int opt;
    cout << "1- Adicionar produto\n";
    cout << "2- Atualizar estoque\n";
    cout << "3- Listar estoque\n";
    cout << "4- Valor total do estoque\n";
    cout << "5- Sair\n";

    cout << "Opcao: ";
    cin >> opt;

    switch(opt){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            cout << "Valor total do estoque: R$" << valorTotalEstoque(estoque) << endl;
            break;
        case 5:
            break;
        default:
            cout << "Opcao invalida!\n";
            break;
    }
}

int main(){
    vector<Produto> estoque;

    estoque.push_back(addProduto("Arroz", 10, 10.0));
    estoque.push_back(addProduto("Feijao", 10, 10.0));
    estoque.push_back(addProduto("Carne", 10, 10.0));

    listEstoque(estoque);

    cout << "\nValor total do estoque: R$" << valorTotalEstoque(estoque) << endl;

    attEstoque(estoque, "Arroz", -5);

    cout << endl;

    listEstoque(estoque);

    cout << "\nValor total do estoque: R$" << valorTotalEstoque(estoque) << endl;

    return 0;
}

Produto iniciaProduto(string nome, string cod, float preco){
    Produto p;
    if(qntd >=0 && preco >= 0 && nome != ""){
        p.nome = nome;
        p.quantidade = qntd;
        p.preco = preco;
    }
    return p;
}

bool addProduto(vector<Produto> estoque, string nome, int qntd, float preco){
    Produto p;
    if(qntd >=0 && preco >= 0 && nome != ""){
        p.nome = nome;
        p.quantidade = qntd;
        p.preco = preco;
        estoque.push_back(p);
        return true;
    }
    return false;
}

void attEstoque(vector<Produto> &estoque, string nome, int mov){
    for( Produto &prod : estoque){
        if(prod.nome == nome){
            prod.quantidade = (prod.quantidade+mov < 0) ? 0 : prod.quantidade+=mov;
            return;
        }
    }
}