#ifndef CLASSES_EDOO_H_INCLUDED
#define CLASSES_EDOO_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Ingrediente {
private:
    int quantidadeI;  //Quantidade do Ingrediente
    string nomeI;    // Nome do Ingrediente
    string tipoI;    // Classifica��o do Ingrediente
public:
    bool disponibilidadeI;    // Disponibilidade do Ingrediente

    Ingrediente(int quantidadeI, string nomeI, string tipoI, bool disponibilidadeI); // Construtor

    // M�todos
    virtual void detalhesI() const; // Exibe as informa��es do ingrediente
    void NaoDisponivelI(); // Muda o operador para false ou true de acordo com a quantidade de ingredientes

    // Getters e Setters
    int getQuantidadeI() const;
    void setQuantidadeI(int novaQuantidadeI);

    string getNomeI() const;
    void setNomeI(string novoNomeI);

    string getTipoI() const;
    void setTipoI(string novoTipoI);
};

#endif
