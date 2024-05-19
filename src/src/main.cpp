#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "comanda.hpp"
#include "listaProduse.h"
#include "produs.hpp"
#include "user.hpp"

void getChoice(int choice);

void afiseazaListaProduse()
{
    for (const auto& prod : listaProduse) {
        prod.afiseazaDate();
        std::cout<<"============================================================================\n";
    }
}

void signIn(std::string email = "")
{
    std::string pass {};
    std::cout << "========   Conectare   ========\n";
    std::cout << "E-mail: ";
    if (email != "") {
        std::cout << email << '\n';
    } else {
        std::cin >> email;
    }
    std::cout << "Parola: ";
    std::cin >> pass;
    std::string e, u, p; // Email, user, pass din fisier
    std::ifstream usersFile("users.txt");
    bool ok = false;
    while (usersFile >> e >> u >> p) {
        if (email == e && pass == p) {
            std::cout << "Ati fost autentificat.\n";
            ok = true;
            system("cls");
            afiseazaListaProduse();
        }
    }
    usersFile.close();
    if (!ok) {
        std::cout << "Eroare!\n";
        exit(EXIT_FAILURE);
    }
}

void createAccount()
{
    std::string email {}, user {}, pass {};
    std::cout << "========   Creeaza cont   ========\n";
    std::cout << "E-mail: ";
    std::cin >> email;
    std::cout << "Nume utilizator: ";
    std::cin >> user;
    std::cout << "Parola: ";
    std::cin >> pass;
    std::fstream usersFile("users.txt", std::ios::app);
    std::string e, u, p; // Email, user, pass din fisier
    while (usersFile >> e >> u >> p) {
        if (email == e) {
            std::cout << "Acest e-mail este deja folosit!\n";
            exit(EXIT_FAILURE);
        }
    }
    // Failbit triggered by while loop (Trying to read at EOF)
    // Needs clear in order for streams to work again
    usersFile.clear();
    usersFile << email + ' ' + user + ' ' + pass + '\n';
    usersFile.close();
    std::cout << "\nAti fost inregistrat!\n\n";
    signIn(email);
}

void getChoice(int choice = -1)
{
    if (choice == -1) {
        std::cout << "[1] Da, doresc sa ma loghez\n"
                     "[2] Nu, doresc sa imi creez un cont acum\n"
                     "[3] Anulare\n"
                     "[1/2/3]: ";
        std::cin >> choice;
    }
    switch (choice) {
    case 1:
        signIn();
        break;

    case 2:
        createAccount();
        break;

    case 3:
        std::cout << "\nLa revedere!\n";
        exit(EXIT_SUCCESS);

    default:
        std::cout << "Comanda necunoscuta!\n\n";
        getChoice();
    }
}

int main()
{
    // Create products
    // Produs produs1(1, "Laptop", 2500, "Laptop i7 cu 16GB RAM", "Electronice");
    // Produs produs2(2, "Telefon", 500, "Telefon mobil Android", "Electronice");
    // Produs p3(3, "Soundbar", 1300, "Soundbar Samsung HW-Q600C, 3.1.2, 360W, Bluetooth, Subwoofer Wireless, Dolby Atmos, Negru Titan", "Home Cinema & Audio");
    // std::cout << "\n";
    // // Create an order
    // Comanda comanda1(101, {&produs1, &produs1, &produs2, &p3, &p3, &produs1}, StatusComanda::Procesata, MetodaPlata::CardBancar, "Calarasi, preluare Bucuresti"); // Constructor cu parametrii optionali

    // Add products to the order using the 'adaugaProdus' function
    // comanda1.adaugaProdus(&produs1);
    // comanda1.adaugaProdus(&produs2);
    // comanda1.adaugaProdus(&p3);

    // comanda1.eliminaProdus(&p3);

    // comanda1.afiseazaDate();

    std::cout << "Bine ati venit la Homeden, primul magazin de mobila accesabil prin terminal!\n\n"
                 "Aveti deja un cont?\n";

    getChoice();
    return 0;
}