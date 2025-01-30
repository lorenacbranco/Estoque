#include <iostream>
#include <vector>
#include <map>
#include "Comida.h"
#include "Ingrediente.h"
#include "Bebida.h"

using namespace std;

int main() {
    // Criando um mapa para armazenar ingredientes
    map<string, Ingrediente> ingredientes = {
        {"Blend de hamburguer", Ingrediente(10, "Blend de Hamburguer", "Carne", true)},
        {"Mucarela", Ingrediente(12, "Mucarela", "Queijo", true)},
        {"Tiras de bacon", Ingrediente(35, "Tiras de Bacon", "Carne", true)},
        {"Alface", Ingrediente(10, "Alface", "Verdura", true)},
        {"Tomate", Ingrediente(7, "Tomate", "Verdura", true)},
        {"Cebola caramelizada", Ingrediente(10, "Cebola Caramelizada", "Verdura", true)},
        {"Molho barbecue", Ingrediente(43, "Molho Barbecue", "Molho", true)},
        {"Pao brioche", Ingrediente(10, "Pao Brioche", "Pao", true)}
    };

    // Criando comidas e seus ingredientes
    vector<Comida> comidas = {
        Comida(true, 33.90, "Johnny Cash Burguer", 15, "Blend MVK",
            {"Blend de hamburguer", "Mucarela", "Tiras de bacon", "Alface", "Tomate", "Cebola caramelizada", "Molho barbecue", "Pao brioche"})
    };

    // Adicionando ingredientes as comidas
    for (auto &comida : comidas) {
        for (const string &nomeIngrediente : comida.getIngredientesNomes()) {
            if (ingredientes.find(nomeIngrediente) != ingredientes.end()) {
                comida.adicionarIngrediente(ingredientes[nomeIngrediente]);
            }
        }
    }

    // Criando bebidas
    vector<Bebida> bebidas = {
        Bebida(true, 4.50, "Agua", 350),
        Bebida(true, 7.90, "Suco", 450),
        Bebida(true, 7.90, "Coca-cola lata", 350),
        Bebida(true, 13.90, "Milk-shake", 500)
    };

    // Exibindo comidas e bebidas
    cout << "Cardapio de Comidas:\n";
    for (const auto &comida : comidas) {
        comida.detalhes();
        cout << "----------------------\n";
    }

    cout << "\nCardapio de Bebidas:\n";
    for (const auto &bebida : bebidas) {
        bebida.detalhes();
        cout << "----------------------\n";
    }

    return 0;
}
