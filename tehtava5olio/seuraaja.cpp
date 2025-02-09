#include "seuraaja.h"

seuraaja::seuraaja(std::string n) : nimi(n)
{
    std::cout << "Luodaan seuraaja " << nimi << std::endl;
}

void seuraaja::paivitys(const std::string &viesti) const
{
    std::cout << nimi << " sai viestin " << viesti << std::endl;
}

std::string seuraaja::getNimi() const
{
    return nimi;
}
