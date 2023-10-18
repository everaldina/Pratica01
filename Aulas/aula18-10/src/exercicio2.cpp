#include <iostream>
#include <string>

using namespace std;

class Desenhavel{
    public:
        virtual void desenhar() = 0;
};

class Circulo : public Desenhavel{
    public:
        void desenhar(){
            cout << "Desenhando circulo." << endl;
        }
};

class Retangulo : public Desenhavel{
    public:
        void desenhar(){
            cout << "Desenhando retangulo." << endl;
        }
};

class Triangulo : public Desenhavel{
    public:
        void desenhar(){
            cout << "Desenhando triangulo." << endl;
        }
};

int main(){
    Desenhavel* forma;

    Circulo c;
    Retangulo r;
    Triangulo t;

    forma = &c;
    forma->desenhar();

    forma = &r;
    forma->desenhar();

    forma = &t;
    forma->desenhar();



    return 0;
}