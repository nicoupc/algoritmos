//
// Created by c0d3r on 24/04/2025.
//

#include "Motocicleta.h"

Motocicleta::Motocicleta(const string& marca, const string& modelo, const Motor& motor, bool tieneSidecar)
    : Vehiculo(marca, modelo, motor), tieneSidecar_(tieneSidecar)
{
}

void Motocicleta::mostrarInfo() const
{
    cout << "Tipo de vehiculo: Motocicleta" << endl;
    Vehiculo::mostrarInfo(); // Muestra la información del vehículo base
    cout << "Tiene sidecar? " << (tieneSidecar_ ? "Si" : "No") << endl;
}
