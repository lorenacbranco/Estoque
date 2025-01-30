#include "Comida.h"

// Construtor atualizado para aceitar nomes de ingredientes
Comida::Comida(bool disponibilidade, double preco, std::string nome, int tempoPreparo, std::string tipo, std::vector<std::string> ingredientesNomes)
    : Produto(disponibilidade, preco, nome), tempoPreparo(tempoPreparo), tipo(tipo), ingredientesNomes(ingredientesNomes) {}

// Exibe detalhes da comida
void Comida::detalhes() const {
    Produto::detalhes();
    std::cout << "Tempo de Preparo: " << tempoPreparo << " minutos" << std::endl;
    std::cout << "Tipo............: " << tipo << std::endl;

    std::cout << "Ingredientes:\n";
    for (const auto& ingrediente : ingredientes) {
        std::cout << "- " << ingrediente.getNomeI() << " (Quantidade Disponível: " << ingrediente.getQuantidadeI() << ")\n";
    }
}

// Adiciona um ingrediente ao prato
void Comida::adicionarIngrediente(const Ingrediente& ingrediente) {
    ingredientes.push_back(ingrediente);
}

// Método para fazer o pedido (reduzir estoque)
void Comida::fazerPedido() {
    std::cout << "\nPedido realizado! Atualizando estoque de ingredientes...\n";
    for (auto& ingrediente : ingredientes) {
        if (ingrediente.getQuantidadeI() > 0) {
            ingrediente.setQuantidadeI(ingrediente.getQuantidadeI() - 1);
        } else {
            std::cout << "Aviso: Ingrediente " << ingrediente.getNomeI() << " está em falta!\n";
            disponibilidade = false;
        }
    }
}

// Novo método para obter os nomes dos ingredientes
std::vector<std::string> Comida::getIngredientesNomes() const {
    return ingredientesNomes;
}

// Getters e Setters
int Comida::getPreparo() const { return tempoPreparo; }
void Comida::setPreparo(int novoPreparo) { tempoPreparo = novoPreparo; }

std::string Comida::getTipo() const { return tipo; }
void Comida::setTipo(std::string novoTipo) { tipo = novoTipo; }
