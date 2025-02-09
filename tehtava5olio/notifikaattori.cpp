#include "notifikaattori.h"

notifikaattori::notifikaattori()
{
    std::cout << "Luodaan notifikaattori" << std::endl;
}

void notifikaattori::lisaa(seuraaja *uusi)
{
    std::cout << "Notifikaattori lisaa seuraajan " << uusi->getNimi() << std::endl;
    uusi->next = seuraajat;
    seuraajat = uusi;
}

void notifikaattori::poista(seuraaja *poista)
{
    std::cout << "Notifikaattori poistaa seuraajan " << poista->getNimi() << std::endl;
    seuraaja *nykyinen = seuraajat;
    seuraaja *edellinen = nullptr;

    while (nykyinen != nullptr)
    {
        if (nykyinen == poista)
        {
            if (edellinen == nullptr)
            {
                seuraajat = nykyinen->next;
            }
            else
            {
                edellinen->next = nykyinen->next;
            }
            return;
        }
        edellinen = nykyinen;
        nykyinen = nykyinen->next;
    }
}

void notifikaattori::tulosta() const
{
    std::cout << "Notifikaattorin seuraajat:" << std::endl;
    seuraaja *nykyinen = seuraajat;

    while (nykyinen != nullptr)
    {
        std::cout << nykyinen->getNimi() << std::endl;
        nykyinen = nykyinen->next;
    }
}

void notifikaattori::postita(const std::string &viesti) const
{
    std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;
    seuraaja *nykyinen = seuraajat;
    while (nykyinen != nullptr)
    {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
