//
// Created by c0d3r on 18/04/2025.
//

#ifndef VEHICULO_H
#define VEHICULO_H

#include "Motor.h"
#include <iostream>
#include <string>
using namespace std;

class Vehiculo
{
private:
    string marca_;
    string modelo_;
    Motor motor_; // Composición: un vehículo tiene un motor

public:
    // Constructor
    Vehiculo(const string& marca, const string& modelo, const Motor& motor);

    // Métodos de la clase
    void mostrarInfo() const; // Muestra la información del vehículo
};


#endif //VEHICULO_H
