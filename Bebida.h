#ifndef BEBIDA_H_INCLUDED
#define BEBIDA_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

#include "Produto.h" //Inclui a classe Produto

class Bebida : public Produto{ //Define como heran�a de Produto
private:
    int tamanho; //Tamanho da bebida em ml

public:

     Bebida(bool disponibilidade, double preco, string nome, int tamanho)
        : Produto(disponibilidade, preco, nome), tamanho(tamanho) {} //Construtor chamando a classe produto

    //M�todo que exibe os detalhes da bebida
    void detalhes() const override;

    //Get e Set
    int getTamanho() const;
    void setTamanho(int novoTamanho);

};
#endif // BEBIDA_H_INCLUDED
