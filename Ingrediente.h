#ifndef INGREDIENTE_H_INCLUDED
#define INGREDIENTE_H_INCLUDED

#include <string>
#include <iostream>

class Ingrediente {
private:
    int quantidadeI;
    std::string nomeI;
    std::string tipoI;

public:
    bool disponibilidadeI;

    // Construtor PADRÃO sem argumentos (necessário para o vetor)
    Ingrediente();

    // Construtor normal
    Ingrediente(int quantidadeI, std::string nomeI, std::string tipoI, bool disponibilidadeI);

    void detalhesI() const;
    void NaoDisponivelI();

    int getQuantidadeI() const;
    void setQuantidadeI(int novaQuantidadeI);

    std::string getNomeI() const;
    void setNomeI(std::string novoNomeI);

    std::string getTipoI() const;
    void setTipoI(std::string novoTipoI);
};

#endif // INGREDIENTE_H_INCLUDED
