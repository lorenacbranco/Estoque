#include <iostream>
#include <string>
using namespace std;

#include "Ingrediente.h"

// Construtor padrao (necessário para o vetor)
Ingrediente::Ingrediente()
    : quantidadeI(0), nomeI(""), tipoI(""), disponibilidadeI(false) {}

// Construtor normal
Ingrediente::Ingrediente(int quantidadeI, std::string nomeI, std::string tipoI, bool disponibilidadeI)
    : quantidadeI(quantidadeI), nomeI(nomeI), tipoI(tipoI), disponibilidadeI(disponibilidadeI) {}

// Exibe os detalhes do produto
void Ingrediente::detalhesI() const {
    cout << "Disponibilidade: " << disponibilidadeI << endl;
    cout << "Quantidade.....: " << quantidadeI << endl;
    cout << "Ingrediente....: " << nomeI << endl;
    cout << "Classifica��o..: " << tipoI << endl;
}

// Muda o operador para false ou true de acordo com a quantidade de ingredientes
void Ingrediente::NaoDisponivelI() {
    if (quantidadeI == 0) {
        disponibilidadeI = false;
    } else if (quantidadeI > 0) {
        disponibilidadeI = true;
    }
}

// Getters e Setters
int Ingrediente::getQuantidadeI() const {
    return quantidadeI;
}

void Ingrediente::setQuantidadeI(int novaQuantidadeI) {
    if (novaQuantidadeI>= 0) {
        quantidadeI = novaQuantidadeI;
        NaoDisponivelI();
    } else {
        cout << "Erro: quantidade invalida!" << endl;
    }
}

string Ingrediente::getNomeI() const {
    return nomeI;
}

void Ingrediente::setNomeI(string novoNomeI) {
    nomeI = novoNomeI;
}

string Ingrediente::getTipoI() const {
    return tipoI;
}

void Ingrediente::setTipoI(string novoTipoI) {
    tipoI = novoTipoI;
}
