#include <iostream>
#include <string>

using namespace std;

class ItemBiblioteca{
    private:
        string titulo;
        string autor;
        int numCopia;
    public:
        ItemBiblioteca(string titulo = "", string autor = "", int numCopia = 0){
            this->titulo = titulo;
            this->autor = autor;
            this->numCopia = numCopia;
        }

        void setTitulo(string titulo){
            this->titulo = titulo;
        }
        void setAutor(string autor){
            this->autor = autor;
        }
        void setNumCopia(int numCopia){
            this->numCopia = numCopia;
        }

        string getTitulo(){
            return titulo;
        }
        string getAutor(){
            return autor;
        }
        int getNumCopia(){
            return numCopia;
        }

};

class Livro : public ItemBiblioteca{
    private:
        string editora;
        int numPaginas;
    public:
        Livro(string titulo = "", string autor = "", int numCopia = 0, string editora = "", int numPaginas = 0) : ItemBiblioteca(titulo, autor, numCopia){
            this->editora = editora;
            this->numPaginas = numPaginas;
        }

        void setEditora(string editora){
            this->editora = editora;
        }
        void setNumPaginas(int numPaginas){
            this->numPaginas = numPaginas;
        }

        string getEditora(){
            return editora;
        }
        int getNumPaginas(){
            return numPaginas;
        }

        string toString(){
            return "Livro: " + getTitulo() + " - " + getAutor() + "\nNumero de copias: " + to_string(getNumCopia()) + "\nEditora: " + getEditora() + "\nNum. paginas: " + to_string(getNumPaginas());
        }
};

class DVD : public ItemBiblioteca{
    private:
        string diretor;
        int duracao;
    public:
        DVD(string titulo = "", string autor = "", int numCopia = 0, string diretor = "", int duracao = 0) : ItemBiblioteca(titulo, autor, numCopia){
            this->diretor = diretor;
            this->duracao = duracao;
        }

        void setDiretor(string diretor){
            this->diretor = diretor;
        }
        void setDuracao(int duracao){
            this->duracao = duracao;
        }

        string getDiretor(){
            return diretor;
        }
        int getDuracao(){
            return duracao;
        }

        string toString(){
            return "DVD: " + getTitulo() + " - " + getAutor() + "\nNumero de copias: " + to_string(getNumCopia()) + "\nDiretor: " + getDiretor() + "\nDuracao: " + to_string(getDuracao());
        }

};

int main(){

    // criando livros por construtor padrão
    Livro l1("O pequeno principe", "Antoine de Saint-Exupéry", 15, "Agir", 96);
    Livro l2("Harry Potter e a pedra filosofal", "J. K. Rowling");
    Livro l3;
    // atribuindo valores aos objetos l3 por meio de setters
    l3.setTitulo("O senhor dos aneis");
    l3.setAutor("J. R. R. Tolkien");
    l3.setNumCopia(10);
    l3.setEditora("Martins Fontes");
    l3.setNumPaginas(1024);

    // imprimindo obejtos livros
    cout << l1.toString() << endl << endl;
    cout << l2.toString() << endl << endl;
    cout << l3.toString() << endl << endl;

    // criando dvds por construtor padrão
    DVD d1("O senhor dos aneis", "Peter Jackson", 10, "Peter Jackson", 558);
    DVD d2("Harry Potter e a pedra filosofal", "Chris Columbus");
    DVD d3;
    // atribuindo valores aos objetos d3 por meio de setters
    d3.setTitulo("O pequeno principe");
    d3.setAutor("Mark Osborne");
    d3.setNumCopia(15);
    d3.setDiretor("Mark Osborne");
    d3.setDuracao(106);

    // imprimindo obejtos dvds
    cout << d1.toString() << endl << endl;
    cout << d2.toString() << endl << endl;
    cout << d3.toString() << endl << endl;

    return 0;
}