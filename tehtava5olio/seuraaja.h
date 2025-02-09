#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>
#include <iostream>

class seuraaja
{
private:
    std::string nimi;

public:
    seuraaja(std::string n);
    seuraaja *next = nullptr;
    std::string getNimi() const;
    void paivitys(const std::string &viesti) const;
};

#endif // SEURAAJA_H
