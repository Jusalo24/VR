#include "seuraaja.h"
#include "notifikaattori.h"

int main()
{
    seuraaja *A = new seuraaja("Seuraaja A");
    seuraaja *B = new seuraaja("Seuraaja B");
    seuraaja *C = new seuraaja("Seuraaja C");

    notifikaattori *N = new notifikaattori();


    N->lisaa(A);
    N->lisaa(B);
    N->lisaa(C);


    N->tulosta();


    N->postita("Tama on viesti 1");


    N->poista(B);


    N->postita("Tama on viesti 2");


    delete A;
    delete B;
    delete C;
    delete N;

    return 0;
}
