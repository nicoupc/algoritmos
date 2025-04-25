//
// Created by c0d3r on 18/04/2025.
//

#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "Vehiculo.h"
#include <iostream>
#include <string>
using namespace std;

// Herencia: Automovil hereda de Vehiculo
class Automovil : public Vehiculo
{
private:
    int puertas_; // Número de puertas del automóvil
    string tipo_; // Tipo de automóvil (por ejemplo, "sedán", "SUV")

public:
    // Constructor
    Automovil(const string& marca, const string& modelo, const Motor& motor, int puertas, const string& tipo);

    // Métodos de la clase
    void mostrarInfo() const; // Muestra la información del automóvil
};

#endif //AUTOMOVIL_H
