#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "Pankkitili.h"

class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(const std::string& nimi, double alkuSaldo, double luottoRaja);
    bool withdraw(double amount) override;
    bool deposit(double amount) override;
    void printAccountInfo() const override;
};

#endif
