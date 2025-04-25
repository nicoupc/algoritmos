//
// Created by c0d3r on 24/04/2025.
//

#include "Vehiculo.h"

Vehiculo::Vehiculo(const string& marca, const string& modelo, const Motor& motor)
    : marca_(marca), modelo_(modelo), motor_(motor)
{
}

void Vehiculo::mostrarInfo() const
{
    cout << "Marca: " << marca_ << endl;
    cout << "Modelo: " << modelo_ << endl;
    motor_.mostrarInfo(); // Muestra la información del motor
}
