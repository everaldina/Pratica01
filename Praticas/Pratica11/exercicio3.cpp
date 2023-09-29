#include <iostream>

using namespace std;

void ordena4(float &var1, float &var2, float &var3, float &var4);

int main(){
    float f1 = 2.0, f2 = -1.0, f3 = 0.0, f4 = 1.4;

    cout << "Antes: \n";
    cout << f1 << " | " << f2 << " | " << f3 << " | " << f4 << endl;
    ordena4(f1, f2, f3, f4); 
    cout << "Depois: \n";
    cout << f1 << " | " << f2 << " | " << f3 << " | " << f4 << endl;

    return 0;
}

void ordena4(float &var1, float &var2, float &var3, float &var4){
    float aux;

    if(var1 > var2){
        aux = var1;
        var1 = var2;
        var2 = aux;
    }
    if(var2 > var3){
        if(var1 > var3){
            aux = var1;
            var1 = var3;
            var3 = aux;
        }
        aux = var2;
        var2 = var3;
        var3 = aux;
    }
    if(var3 > var4){
        if(var2 > var4){
            if(var1 > var4){
                aux = var1;
                var1 = var4;
                var4 = aux;
            }
            aux = var2;
            var2 = var4;
            var4 = aux;
        }
        aux = var3;
        var3 = var4;
        var4 = aux;
    }

}