//
// Created by c0d3r on 18/04/2025.
//

#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include "Vehiculo.h"
#include <iostream>
#include <string>
using namespace std;

// Herencia: Motocicleta hereda de Vehiculo
class Motocicleta : public Vehiculo
{
private:
    bool tieneSidecar_; // Indica si la motocicleta tiene un sidecar

public:
    // Constructor
    Motocicleta(const string& marca, const string& modelo, const Motor& motor, bool tieneSidecar);

    // Métodos de la clase
    void mostrarInfo() const; // Muestra la información de la motocicleta
};

#endif //MOTOCICLETA_H
