#ifndef INGREDIENTE_H_INCLUDED
#define INGREDIENTE_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Ingrediente {
private:
    int quantidadeI;  // Quantidade do ingrediente
    string nomeI;     // Nome do ingrediente
    string tipoI;     // Classificação do ingrediente
public:
    bool disponibilidadeI;    // Disponibilidade do ingrediente

    Ingrediente(int quantidadeI, string nomeI, string tipoI, bool disponibilidadeI); // Construtor

    // Metodos
    void detalhesI() const;  // Exibe as informacoes do ingrediente
    void NaoDisponivelI();   // Muda o operador para false ou true de acordo com a quantidade de ingredientes

    // Getters e Setters
    int getQuantidadeI() const;
    void setQuantidadeI(int novaQuantidadeI);

    string getNomeI() const;
    void setNomeI(string novoNomeI);

    string getTipoI() const;
    void setTipoI(string novoTipoI);
};

#endif // INGREDIENTE_H_INCLUDED
