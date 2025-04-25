//
// Created by c0d3r on 24/04/2025.
//

#include "Flota.h"

Flota::Flota(const Compania& compania) : compania_(compania)
{
}

void Flota::agregarVehiculo(Vehiculo* vehiculo)
{
    vehiculos_.push_back(vehiculo);
}

void Flota::mostrarInfo() const
{
    cout << "Informacion de la flota de la compania: ";
    cout << compania_.getNombre() << endl; // Muestra el nombre de la compañía
    cout << "Vehiculos en la flota:" << endl;
    for (const auto& vehiculo : vehiculos_)
    {
        vehiculo->mostrarInfo(); // Muestra la información de cada vehículo
        cout << "------------------------" << endl;
    }
}
