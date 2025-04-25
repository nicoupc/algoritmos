//
// Created by c0d3r on 24/04/2025.
//

#include "Conductor.h"

Conductor::Conductor(const string& nombre) : nombre_(nombre)
{
}

void Conductor::asignarVehiculo(const Vehiculo& vehiculo) const
{
    cout << "El conductor " << nombre_ << " ha sido asignado al vehiculo:" << endl;
    vehiculo.mostrarInfo(); // Muestra la información del vehículo asignado
}
