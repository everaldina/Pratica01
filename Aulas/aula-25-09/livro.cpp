#include <iostream>
#include <string>

using namespace std;


class Data{
    private:
        short int dia;
        short int mes;
        int ano;

        bool validarData(short int dia, short int mes, int ano){
            if (ano < 0 || mes < 1 || mes > 12 || dia <1){
                return false;
            }
            if (mes == 2){
                if (isBissexto(ano)){
                    if (dia > 29)
                        return false;
                }
                else if (dia > 28){
                    return false;
                }
            }else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia >30)
                return false;
            else if(dia > 31)
                return false;
            return true;
        }
    public:
        Data(short int _dia, short int _mes, int _ano){
            if(validarData(_dia, _mes, _ano)){
                dia = _dia;
                mes = _mes;
                ano = _ano;
            }else{
                cout << "Data inválida" << endl;
                dia = 0;
                mes = 0;
                ano = 0;
            }
        }
        Data(){
            dia = 0;
            mes = 0;
            ano = 0;
        }

        string exibirData(){
            return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
        }

        bool isBissexto(int ano){
            if (ano % 4 == 0 && ano % 100 != 0)
                return true;
            else if (ano % 400 == 0)
                return true;
            else
                return false;
        }
        bool isBissxto(){
            return isBissexto(ano);
        }

};

class Livro {
    private:
        string titulo;
        string autor;
        Data publicacao;
        int edicao;
        Data dataEdicao;
        string editora;
        string isbn;
        string genero;

        bool validarISBN(string isbn){
            if (isbn.length() != 13)
                return false;
            for (char ch : isbn){
                if (!isdigit(ch))
                    return false;
            }
            return true;
        }

        string printISBN(string isbn){
            string str = "";
            for (int i = 0; i < 13; i++){
                str += isbn[i];
                if (i == 2 || i == 4 || i == 7 || i == 11)
                    str += "-";
            }
            return str;
        }


    public:
        // Construtor da classe Livro
        Livro(string _titulo, string _autor, Data _publicacao, string _isbn, int _edicao, string _editora, Data _dataEdicao, string _genero){
            titulo = _titulo;
            autor= _autor;
            publicacao= _publicacao;
            edicao = _edicao;
            dataEdicao = _dataEdicao;
            editora = _editora;
            if(validarISBN(_isbn))
                isbn = _isbn;
            else{
                isbn = "00000000000000000";
                cout << "ISBN inválido" << endl;
            }
            genero = _genero;

        }

        // Método para exibir informações do livro
        void exibirInformacoes() {
            cout << titulo << " - " << autor << endl;
            cout << edicao << "ª edição - " << dataEdicao.exibirData() << endl;
            cout << "Lançamento: " << publicacao.exibirData()<< endl;
            cout << "Editora: " << editora << endl;
            cout << "ISBN: " << printISBN(isbn) << endl;
            cout << "Gênero: " << genero << endl;

        }

};

int main() {
    // Criando objetos livro1 e livro2
    Data data1(1, 1, 1954), data2(26, 6, 1997), data3(1, 1, 2021);
    Livro livro1("O Senhor dos Anéis", "J.R.R. Tolkien", data1, "9780618574365", 1, "Allen & Unwin", data2, "Fantasia");
    Livro livro2("Harry Potter e a Pedra Filosofal", "JK Rowling", data3, "9788532529399", 1, "Rocco", data3, "Fantasia");
    // Exibindo informações dos livros
    cout << "Informações do livro1:" << endl;
    livro1.exibirInformacoes();

    cout << "\nInformações do livro2:" << endl;
    livro2.exibirInformacoes();

    return 0;
}