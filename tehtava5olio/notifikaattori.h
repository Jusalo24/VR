#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "seuraaja.h"
#include <iostream>
#include <string>

class notifikaattori
{
public:
    notifikaattori();
    void lisaa(seuraaja *uusi);
    void poista(seuraaja *poista);
    void tulosta() const;
    void postita(const std::string &viesti) const;

private:
    seuraaja *seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
