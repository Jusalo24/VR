#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "Pankkitili.h"
#include "Luottotili.h"

class Asiakas {
private:
    std::string nimi;
    Pankkitili pankkitili;
    Luottotili luottotili;

public:
    Asiakas(const std::string& nimi, double pankkitilinSaldo, double luottoraja);
    void showSaldo() const;
    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);
    bool tiliSiirto(double amount, Asiakas& vastaanottaja);
};

#endif
