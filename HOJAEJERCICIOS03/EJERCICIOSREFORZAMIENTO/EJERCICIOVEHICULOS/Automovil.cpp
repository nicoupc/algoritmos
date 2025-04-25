//
// Created by c0d3r on 24/04/2025.
//

#include "Automovil.h"

Automovil::Automovil(const string& marca, const string& modelo, const Motor& motor, int puertas, const string& tipo)
    : Vehiculo(marca, modelo, motor), puertas_(puertas), tipo_(tipo)
{
}

void Automovil::mostrarInfo() const
{
    cout << "Tipo de vehículo: Automovil" << endl;
    Vehiculo::mostrarInfo(); // Muestra la información del vehículo base
    cout << "Numero de puertas: " << puertas_ << endl;
    cout << "Tipo de automovil: " << tipo_ << endl;
}
