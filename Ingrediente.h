#ifndef INGREDIENTE_H_INCLUDED
#define INGREDIENTE_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Ingrediente {
private:
    int quantidadeI;
    string nomeI;
    string tipoI;

public:
    bool disponibilidadeI;

    // Construtor padrao (necessário para o vetor)
    Ingrediente();

    // Construtor normal
    Ingrediente(int quantidadeI, string nomeI, string tipoI, bool disponibilidadeI);

    //Metodos

    void detalhesI() const;
    void NaoDisponivelI();

    //Getters e Setters
    int getQuantidadeI() const;
    void setQuantidadeI(int novaQuantidadeI);

    string getNomeI() const;
    void setNomeI(string novoNomeI);

    string getTipoI() const;
    void setTipoI(string novoTipoI);
};

#endif // INGREDIENTE_H_INCLUDED
