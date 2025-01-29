#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

#include "Produto.h" //Inclui a classe Produto

class Comida : public Produto{ //Define como heran�a de Produto
private:
    int tempoPreparo; //Tempo m�dio de preparo em minutos
    string tipo; //Tipo da comida (se � acompanhamento, se � hamb�rguer smash...)
public:

    Comida(bool disponibilidade, double preco, string nome, int tempoPreparo, string tipo); //Construtor

    //M�todos

    void detalhes() const override;
    void PrecoPorTipo(); //Define os pre�os de acordo com a classifica��o da comida


    // Getters e Setters
    int getPreparo() const;
    void setPreparo(int novoPreparo);

    string getTipo() const;
    void setTipo(string novoTipo);

};



#endif // COMIDA_H_INCLUDED
