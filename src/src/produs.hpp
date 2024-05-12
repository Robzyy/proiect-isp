#pragma once

#include <iostream>

class Produs {
private:
    int idProdus;
    std::string nume;
    float pret;
    std::string descriere;
    std::string categorie;

public:
    // Constructor
    Produs(int idProdus, std::string nume, float pret, std::string descriere, std::string categorie)
    {
        this->idProdus = idProdus;
        this->nume = nume;
        this->pret = pret;
        this->descriere = descriere;
        this->categorie = categorie;
    }
    float getPret() const { return pret; }
    std::string getNume() const { return nume; }
    std::string getDescriere() const { return descriere; }
    // Function to display product details
    void afiseazaDate() const
    {
        std::cout << "Id produs: " << idProdus << std::endl;
        std::cout << "Nume: " << nume << std::endl;
        std::cout << "Pret: " << pret << std::endl;
        std::cout << "Descriere: " << descriere << std::endl;
        std::cout << "Categorie: " << categorie << std::endl;
    }
    friend bool operator==(const Produs& p1, const Produs& p2)
    {
        return (p1.idProdus == p2.idProdus);
    }
};
