#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>  // Para o uso de lista de ingredientes
#include "Produto.h"  //classe Produto
#include "Ingrediente.h"  //classe Ingrediente

using namespace std;

class Comida : public Produto {
private:
    int tempoPreparo;  // Tempo medio de preparo em minutos
    string tipo;  // Tipo da comida (se e acompanhamento, hamberguer, etc)
    vector<Ingrediente> ingredientes;  // Lista de ingredientes (usando vector de Ingrediente)
public:
    Comida(bool disponibilidade, double preco, string nome, int tempoPreparo, string tipo); // Construtor

    // Metodos
    void detalhes() const override;
    void PrecoPorTipo(); // Define os precos de acordo com a classificacao da comida
    void adicionarIngrediente(const Ingrediente& ingrediente);  //Adiciona ingredientes na comida
    void fazerPedido();  //Subtrai a quantidade de ingredientes

    // Getters e Setters
    int getPreparo() const;
    void setPreparo(int novoPreparo);
    string getTipo() const;
    void setTipo(string novoTipo);
};

#endif // COMIDA_H_INCLUDED
