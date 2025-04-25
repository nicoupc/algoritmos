//
// Created by c0d3r on 23/04/2025.
//

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;


class Persona
{
private:
    string nombre_;
    string dni_;

public:
    // Constructor con parámetros
    Persona(const string& nombre, const string& dni);

    // Métodos de la clase
    void saltar() const;
    void piernas() const;
    void descansar() const;

    // Métodos de acceso (getters y setters)
    void setNombre(string nombre);
    string getNombre() const;

    void setDni(string dni);
    string getDni() const;

    void mostrar() const;
};


#endif //PERSONA_H
