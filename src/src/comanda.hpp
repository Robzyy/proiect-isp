#pragma once

#include "produs.hpp"
#include <iostream>
#include <string>
#include <vector>

enum class MetodaPlata {
    CardBancar,
    Ramburs,
    Credit,
    Unknown
};

enum class StatusComanda {
    Plasata,
    Platita,
    Procesata,
    Livrata,
    Unknown
};

class Comanda {
private:
    int id;
    std::vector<Produs*> listaProduse;
    StatusComanda status;
    MetodaPlata metodaPlata;
    std::string adresaLivrare;

    std::string statusAsString(const StatusComanda& status) const
    {
        switch (status) {
        case StatusComanda::Plasata:
            return "Plasata";
        case StatusComanda::Platita:
            return "Platita";
        case StatusComanda::Procesata:
            return "Procesata";
        case StatusComanda::Livrata:
            return "Livrata";
        case StatusComanda::Unknown:
            return "UNKNOWN_STATUS";
        }
    }

    std::string metodaPlataAsString(const MetodaPlata& metoda) const
    {
        switch (metoda) {
        case MetodaPlata::CardBancar:
            return "Card Bancar";
        case MetodaPlata::Ramburs:
            return "Ramburs";
        case MetodaPlata::Credit:
            return "Credit";
        case MetodaPlata::Unknown:
            return "UNKNOWN_PAYMENT_METHOD";
        }
    }

public:
    // Constructor
    Comanda(int id, std::vector<Produs*> listaProduse,
        StatusComanda statusComanda = StatusComanda::Unknown,
        MetodaPlata metodaPlata = MetodaPlata::Unknown,
        std::string adresaLivrare = "") //As fi mers pe default = NULL dar ok
        : id { id }
        , listaProduse { listaProduse }
        , status { statusComanda }
        , metodaPlata { metodaPlata }
        , adresaLivrare { adresaLivrare }
    {
    }

    // Function to display order details
    void afiseazaDate() const
    {
        std::cout << "Id comanda: " << id << std::endl;
        // std::cout << "Lista produse:" << std::endl;
        // for (const Produs* produs : listaProduse) {
        //     produs->afiseazaDate();
        // }
        std::cout << "Status comanda: " << statusAsString(status) << std::endl;
        std::cout << "Metoda de plata: " << metodaPlataAsString(metodaPlata) << std::endl;
        std::cout << "Adresa livrare: " << adresaLivrare << std::endl;
        std::cout << "Pret total: " << getPret() << " lei\n";
        std::cout << "Descriere: " << getDescriere() << std::endl
                  << std::endl;
    }

    // Function to calculate total price
    float getPret() const
    {
        float pretTotal = 0;
        for (const Produs* produs : listaProduse) {
            pretTotal += produs->getPret();
        }
        return pretTotal;
    }

    // Function to generate order description
    std::string getDescriere() const
    {
        std::string descriereComanda = "Comanda " + std::to_string(id) + ":\n";
        for (const Produs* produs : listaProduse) {
            descriereComanda += "- " + produs->getNume() + " (" + produs->getDescriere() + ")\n";
        }
        return descriereComanda;
    }

    // Function to add a product to the order
    void adaugaProdus(Produs* produs)
    {
        listaProduse.push_back(produs); // Adaugarea pointerului la produs in lista
    }

    void eliminaProdus(Produs* produs)
    {
        std::vector<Produs*>::iterator inceputLista = listaProduse.begin(), sfarsitLista = listaProduse.end();
        for (std::vector<Produs*>::iterator i = inceputLista; i < sfarsitLista; i++) {
            if (listaProduse[i - inceputLista] == produs) {
                listaProduse.erase(i);
                break;
            }
        }
    }
};
