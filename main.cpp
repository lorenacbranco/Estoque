#include <iostream>
#include <string>
#include <vector>
#include "Comida.h"
#include "Ingrediente.h"
#include "Bebida.h"

using namespace std;

int main(){
    //Ingredientes

    //Verduras
    Ingrediente alface(10, "Alface", "Verdura", true);
    Ingrediente cebola(5, "Cebola", "Verdura", true);
    Ingrediente cebolaCaramelizada(10, "Cebola Caramelizada", "Verdura", true);
    Ingrediente cebolaRoxa(10, "Cebola Roxa", "Verdura", true);
    Ingrediente cebolinha(10, "Cebolinha", "Verdura", true);
    Ingrediente picles(10, "Picles", "Verdura", true);
    Ingrediente tomate(7, "Tomate", "Verdura", true);

    //Carnes
    Ingrediente blendFrangoEmp(8, "Blend de Frango Empanado", "Carne", true);
    Ingrediente blendHamburguer(10, "Blend de Hamburger", "Carne", true);
    Ingrediente blendVegano(10, "Blend Vegano", "Carne", true);
    Ingrediente costelinha(20, "Costelinha Suina", "Carne", true);
    Ingrediente salsicha(10, "Salsicha Viena", "Carne", true);
    Ingrediente sobrecoxaFrango(5, "Sobrecoxa de Frango", "Carne", true);
    Ingrediente tirasBacon(35, "Tiras de Bacon", "Carne", true);
    Ingrediente tirasFrango(30, "Tiras de Peito de Frango", "Carne", true);

    //Acompanhamentos
    Ingrediente batataFina(9, "Batata Fina", "Acompanhamento", true);
    Ingrediente crispy(11, "Crispy de Cebola", "Acompanhamento", true);
    Ingrediente dryreb(50, "Dry Reb", "Acompanhamento", true);
    Ingrediente farofaBacon(25, "Farofa de Bacon", "Acompanhamento", true);
    Ingrediente gergelim(9, "Gergelim", "Acompanhamento", true);
    Ingrediente empanamento(11, "Ingredientes para Empanamento", "Acompanhamento", true);
    Ingrediente pastel(25, "Massa de Pastel", "Acompanhamento", true);

    //Molhos
    Ingrediente ketchup(40, "Ketchup", "Molho", true);
    Ingrediente ketchupGoiabada(32, "Ketchup Goiabada", "Molho", true);
    Ingrediente maionese(40, "Maionese Temperada", "Molho", true);
    Ingrediente island(22, "Molho 100 Island", "Molho", true);
    Ingrediente barbecue(43, "Molho Barbecue", "Molho", true);
    Ingrediente parmesao(49, "Molho Parmesão", "Molho", true);

    //Queijos
    Ingrediente creamCheese(6, "Cream Cheese", "Molho", true);
    Ingrediente cheddar(24, "Cheddar Cremoso", "Molho", true);
    Ingrediente mucarela(12, "Mucarela", "Molho", true);
    Ingrediente provolone(6, "provolone", "Molho", true);

    //Paes
    Ingrediente american(10, "American Bread", "Pao", true);
    Ingrediente brioche(10, "Brioche", "Pao", true);
    Ingrediente paoGergelim(10, "Pao com Gergelim", "Pao", true);
    Ingrediente hotdog(10, "Pao de Hot Dog", "Pao", true);
    Ingrediente macio(10, "Macio", "Pao", true);

    //Bebidas


}
