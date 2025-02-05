#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>
#include <iostream>
#include <iomanip>

class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    Pankkitili(const std::string& nimi, double alkuSaldo = 0.0);
    virtual ~Pankkitili() {}

    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    double getBalance() const;
    virtual void printAccountInfo() const;
};

#endif
