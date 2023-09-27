#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


class Ponto{
    float x, y, z;
    
    public:
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }
        float getZ(){
            return z;
        }

        void le_Ponto(){
            cout << "Digite as coordenadas do ponto: ";
            cin >> x >> y >> z;
        }

        string escreve_ponto(){
            return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
        }

        float distancia(Ponto p){
            return sqrt(pow(x-p.getX(), 2) + pow(y-p.getY(), 2) + pow(z-p.getZ(), 2));
        }
};

class Poligono{
    vector<Ponto> pontos;

    public:
        void le_pontos(){
            cout << "Criando um poligono!" << endl;
            char sn;
            do{
                Ponto p;
                p.le_Ponto();
                pontos.push_back(p);
                cout << "Deseja adicionar outro ponto? (s/n) ";
                cin >> sn;  
            }while(sn!='n');
        }

        void lista_pontos(){
            cout << "As coordenadas digitadas foram: " << endl;
            for (Ponto p : pontos){
                cout << p.escreve_ponto() << " ";
            }
        }

        float perimetro(){
            float per = 0;
            vector<Ponto>::iterator it2;
            Ponto p1;
            Ponto p2;

            for (auto it = pontos.begin(); it != pontos.end() -1; it++){
                it2 = it;
                advance(it2, 1);
                p1 = *it;
                p2 = *it2;
                per += p1.distancia(p2);
            }

            it2 = pontos.begin();
            p1 = *it2;
            per += p1.distancia(p2);
            return per;
        }
};


int main(){
    Poligono poli;

    poli.le_pontos();
    poli.lista_pontos();
    cout << endl << "Perimetro calculado: " << poli.perimetro() << endl;
    return 0;
}