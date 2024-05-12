#pragma once

#include <iostream>
#include <string>

enum class Locatie {
    Bucuresti,
    Cluj,
    Constanta,
    TarguJiu,
    Iasi,
    Brasov,
    Calarasi,
    Ploiesti,
    Galati
};

class Depozit {
private:
    std::string nume;
    // TODO: class Angajat manager; // Creaza clasa Angajat
    float profitAnual;
};