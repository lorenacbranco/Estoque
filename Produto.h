#ifndef CLASSES_EDOO_H_INCLUDED
#define CLASSES_EDOO_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Produto {
protected:
    double preco;       // Pre�o do produto
private:
    string nome;        // Nome do produto

public:
    bool disponibilidade; // Disponibilidade do produto

    Produto(bool disponibilidade, double preco, string nome); // Construtor

    // M�todos
    virtual void detalhes() const; // Exibe as informa��es do produto

    // Getters e Setters
    double getPreco() const;
    void setPreco(double novoPreco);

    string getNome() const;
    void setNome(string novoNome);
};

#endif
