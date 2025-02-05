#include "Pankkitili.h"

Pankkitili::Pankkitili(const std::string& nimi, double alkuSaldo)
    : omistaja(nimi), saldo(alkuSaldo) {
    std::cout << "Pankkitili luotu " << omistaja << ":lle\n";
}

bool Pankkitili::deposit(double amount) {
    if (amount <= 0) return false;
    saldo += amount;
    return true;
}

bool Pankkitili::withdraw(double amount) {
    if (amount <= 0 || amount > saldo) return false;
    saldo -= amount;
    return true;
}

double Pankkitili::getBalance() const {
    return saldo;
}

void Pankkitili::printAccountInfo() const {
    std::cout << "Kayttotilin saldo " << std::fixed << std::setprecision(2) << saldo << "\n";
}
