#include <iostream>
#include <string>
using namespace std;

string intersectString(string A, string B);

int main(){
    string A = "String 1 teste"; 
    string B = "teste de instersecao 12";
    string C = intersectString(A, B);

    cout << "String A: " << A << endl;
    cout << "String B: " << B << endl;

    cout << "Caracteres em comum: " << C << endl;



    return 0;
}

string intersectString(string A, string B){
    string intersect = "";

    for(char ch : A){
        if(B.find(ch) != string::npos && intersect.find(ch) == string::npos)
            intersect.push_back(ch);
    }

    return intersect;
}