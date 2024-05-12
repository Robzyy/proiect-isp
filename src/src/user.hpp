#pragma once

#include "produs.hpp"
#include <iostream>
#include <string>
#include <vector>

class User {
private:
    int IDClient;
    std::string username;
    int age;
    std::string email;
    std::vector<Produs*> listaFavorite;
    // TODO: std::vector<lista facturi>

public:
    User(int id, std::string name, int userAge, std::string userEmail)
        : IDClient { id }
        , username { name }
        , age { userAge }
        , email { userEmail }
    {
    }

    void afiseazaDate()
    {
        std::cout << "Username: " << username << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Email: " << email << std::endl;
    }

    // Getters
    std::string getUsername() const { return username; }
    int getAge() const { return age; }
    std::string getEmail() const { return email; }

    // Setters
    void setUsername(std::string name) { username = name; }
    void setAge(int userAge) { age = userAge; }
    void setEmail(std::string userEmail) { email = userEmail; }

    // Lista favorite
    void adaugaFavorite(Produs* produs) { listaFavorite.push_back(produs); }
    void eliminaFavorite(Produs* produs) // IDEM comanda.hpp > Comanda::eliminaProdus()
    {
        std::vector<Produs*>::iterator inceputLista = listaFavorite.begin(), sfarsitLista = listaFavorite.end();
        for (std::vector<Produs*>::iterator i = inceputLista; i < sfarsitLista; i++) {
            if (listaFavorite[i - inceputLista] == produs) {
                listaFavorite.erase(i);
                break;
            }
        }
    }
};