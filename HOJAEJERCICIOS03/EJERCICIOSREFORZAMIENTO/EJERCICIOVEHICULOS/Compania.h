//
// Created by c0d3r on 18/04/2025.
//

#ifndef COMPANIA_H
#define COMPANIA_H

#include <iostream>
#include <string>
using namespace std;

class Compania
{
private:
    string nombre_; // Nombre de la compañía

public:
    // Constructor
    Compania(const string& nombre);

    // Métodos de la clase
    string getNombre() const; // Muestra la información de la compañía
};

#endif //COMPANIA_H
