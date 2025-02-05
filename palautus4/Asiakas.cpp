#include "Asiakas.h"

Asiakas::Asiakas(const std::string& nimi, double pankkitilinSaldo, double luottoraja)
    : nimi(nimi), pankkitili(nimi, pankkitilinSaldo), luottotili(nimi, 0.0, luottoraja) {
    std::cout << "Asiakkuus luotu " << nimi << "\n";
    showSaldo();
}

void Asiakas::showSaldo() const {
    std::cout << nimi << "\n";
    pankkitili.printAccountInfo();
    luottotili.printAccountInfo();
    std::cout << "\n";
}

bool Asiakas::talletus(double amount) {
    return pankkitili.deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return pankkitili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    return luottotili.deposit(amount);
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas& vastaanottaja) {
    if (amount <= 0 || !pankkitili.withdraw(amount)) return false;
    return vastaanottaja.talletus(amount);
}
