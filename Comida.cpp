#include <iostream>
#include <string>
#include <vector>
#include "Comida.h"

using namespace std;

// Construtor
Comida::Comida(bool disponibilidade, double preco, string nome, int tempoPreparo, string tipo)
    : Produto(disponibilidade, preco, nome), tempoPreparo(tempoPreparo), tipo(tipo) {}

    //Metodos

// Exibe os detalhes das comidas
void Comida::detalhes() const {
    Produto::detalhes();
    cout << "Tempo de Preparo: " << tempoPreparo << endl;
    cout << "Tipo............: " << tipo << endl;
}

// Define os preços de acordo com a classificação da comida
void Comida::PrecoPorTipo() {
    if (tipo == "Acompanhamentos") {
        setPreco(27.90);
    }
    else if (tipo == "Blend MVK") {
        setPreco(33.90);
    }
    else if (tipo == "Hamburguer Double Smash") {
        setPreco(34.90);
    }
    else if (tipo == "Hamburguer Smash") {
        setPreco(22.90);
    }
    else if (tipo == "Blend Frango") {
        setPreco(30.90);
    }
    else if (tipo == "Sanduiches") {
        setPreco(28.90);
    }
    else if (tipo == "Cachorro Quente") {
        setPreco(23.90);
    }
}

//Adiciona ingredientes
void Comida::adicionarIngrediente(const Ingrediente& ingrediente) {
    ingredientes.push_back(ingrediente);
}

//Subtrai a quantidade de ingredientes
void Comida::fazerPedido() {
    for (Ingrediente& ing : ingredientes) {
        int quantidade = ing.getQuantidadeI();
        if (quantidade > 0) {
            // Subtrai uma unidade do ingrediente
            ing.setQuantidadeI(quantidade - 1);
            cout << "Ingrediente " << ing.getNomeI() << " agora tem " << ing.getQuantidadeI() << " unidades restantes." << endl;
        } else {
            cout << "Ingrediente " << ing.getNomeI() << " está fora de estoque." << endl;
        }
    }
}

// Getters e Setters
int Comida::getPreparo() const {
    return tempoPreparo;
}

void Comida::setPreparo(int novoPreparo) {
    if (novoPreparo >= 0) {
        tempoPreparo = novoPreparo;
    } else {
        cout << "Erro: tempo de preparo inválido!" << endl;
    }
}

string Comida::getTipo() const {
    return tipo;
}

void Comida::setTipo(string novoTipo) {
    tipo = novoTipo;
    PrecoPorTipo();
}
