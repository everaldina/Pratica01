#include <iostream>
#include <ctime>

using namespace std;

struct Passagem{
    string nome;
    char tipo; // ida RJ --> SP (0) ou volta RJ <-- SP (1)
    int poltrona = 0;
    time_t data = mkdtemp;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
}

int main(){
    [40]

    return 0;
}