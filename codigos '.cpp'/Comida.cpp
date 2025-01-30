#include "Comida.h"
using namespace std;


// Construtor
Comida::Comida(bool disponibilidade, double preco, string nome, int tempoPreparo, string tipo, vector<string> ingredientesNomes)
    : Produto(disponibilidade, preco, nome), tempoPreparo(tempoPreparo), tipo(tipo), ingredientesNomes(ingredientesNomes) {}

// Exibe detalhes da comida
void Comida::detalhes() const {
    Produto::detalhes();
    cout << "Tempo de Preparo: " << tempoPreparo << " minutos" << endl;
    cout << "Tipo............: " << tipo << endl;

    cout << "Ingredientes:" << endl;
    for (const auto& ingrediente : ingredientes) {
        cout << "- " << ingrediente.getNomeI() << " (Quantidade Disponivel: " << ingrediente.getQuantidadeI() << ")" << endl;
    }
}

// Adiciona um ingrediente ao prato
void Comida::adicionarIngrediente(const Ingrediente& ingrediente) {
    ingredientes.push_back(ingrediente);
}

// Método para fazer o pedido (reduzir estoque)
void Comida::fazerPedido() {
    cout << endl << "Pedido realizado! Atualizando estoque de ingredientes..." << endl;
    for (auto& ingrediente : ingredientes) {
        if (ingrediente.getQuantidadeI() > 0) {
            ingrediente.setQuantidadeI(ingrediente.getQuantidadeI() - 1);
        } else {
            cout << "Aviso: Ingrediente " << ingrediente.getNomeI() << " está em falta!" << endl;
            disponibilidade = false;
        }
    }
}

// Método para obter os nomes dos ingredientes
vector<string> Comida::getIngredientesNomes() const {
    return ingredientesNomes;
}

// Getters e Setters
int Comida::getPreparo() const { return tempoPreparo; }
void Comida::setPreparo(int novoPreparo) { tempoPreparo = novoPreparo; }

string Comida::getTipo() const { return tipo; }
void Comida::setTipo(string novoTipo) { tipo = novoTipo; }
