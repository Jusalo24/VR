#include "Luottotili.h"

Luottotili::Luottotili(const std::string& nimi, double alkuSaldo, double luottoRaja)
    : Pankkitili(nimi, alkuSaldo), luottoRaja(luottoRaja) {
    std::cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << "\n";
}

bool Luottotili::withdraw(double amount) {
    if (amount <= 0 || (saldo - amount) < -luottoRaja) return false;
    saldo -= amount;
    return true;
}

bool Luottotili::deposit(double amount) {
    if (amount <= 0) return false;
    saldo += amount;
    return true;
}

void Luottotili::printAccountInfo() const {
    std::cout << "Luottotilin saldo " << std::fixed << std::setprecision(2) << saldo + luottoRaja << "\n";
}
