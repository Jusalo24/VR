#include "Asiakas.h"

int main() {
    Asiakas aapeli("Aapeli", 0.0, 1000.0);
    aapeli.talletus(250.0);
    aapeli.luotonNosto(150.0);
    aapeli.showSaldo();

    Asiakas bertta("Bertta", 0.0, 1000.0);
    aapeli.tiliSiirto(50.0, bertta);
    bertta.showSaldo();

    return 0;
}
