#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno{
    private:
        string nome;
        int numIndentificacao;
    public:
        Aluno(string nome = "", int numIndentificacao = 0){
            this->nome = nome;
            this->numIndentificacao = numIndentificacao;
        }

        string getNome(){
            return nome;
        }
        int getNumIdent(){
            return numIndentificacao;
        }
        void setNome(string nome){
            this->nome = nome;
        }
        void setNumIdent(int numIndentificacao){
            this->numIndentificacao = numIndentificacao;
        }

        void exibirAluno(){
            cout << "Nome: " << nome;
            cout << " | Numero de identificacao: " << numIndentificacao << endl;
        }
        
};

class Turma{
    private:
        vector<Aluno*> alunos;
    public:
        int buscAluno(int numIdent){
            for(int i = 0; i < alunos.size(); i++){
                if(alunos[i]->getNumIdent() == numIdent)
                    return i;
            }
            return -1;
        }

        bool addAluno(string nome, int numIdent){
            int index = buscAluno(numIdent);
            if(index == -1){
                Aluno aluno(nome, numIdent);
                alunos.insert(alunos.begin() + index, aluno);
                return true;
            }
            return false;
        }

        void listarAlunos(){
            for(int i = 0; i < alunos.size(); i++){
                alunos[i].exibirAluno();
            }
        }

};

int main(){
    Turma turma;
    Aluno a1(

    return 0;
}