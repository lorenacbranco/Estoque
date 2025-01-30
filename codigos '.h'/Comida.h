#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

#include "Produto.h"
#include "Ingrediente.h"
#include <vector>
#include <string>
#include <iostream>

class Comida : public Produto {
private:
    int tempoPreparo;
    std::string tipo;
    std::vector<Ingrediente> ingredientes;
    std::vector<std::string> ingredientesNomes;  // Novo atributo para armazenar os nomes dos ingredientes

public:
    // Construtor atualizado para aceitar ingredientes como vetor de strings
    Comida(bool disponibilidade, double preco, std::string nome, int tempoPreparo, std::string tipo, std::vector<std::string> ingredientesNomes);

    void detalhes() const override;
    void PrecoPorTipo();
    void fazerPedido();
    void adicionarIngrediente(const Ingrediente& ingrediente);

    int getPreparo() const;
    void setPreparo(int novoPreparo);

    std::string getTipo() const;
    void setTipo(std::string novoTipo);

    // Novo método para acessar os nomes dos ingredientes
    std::vector<std::string> getIngredientesNomes() const;
};

#endif // COMIDA_H_INCLUDED
