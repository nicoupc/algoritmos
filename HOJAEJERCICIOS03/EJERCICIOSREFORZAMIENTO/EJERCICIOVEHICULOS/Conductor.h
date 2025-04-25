//
// Created by c0d3r on 18/04/2025.
//

#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Vehiculo.h"
#include <iostream>
#include <string>
using namespace std;

class Conductor
{
private:
    string nombre_; // Nombre del conductor

public:
    // Constructor
    Conductor(const string& nombre);

    // Metodo para asignar un vehículo al conductor
    void asignarVehiculo(const Vehiculo& vehiculo) const; // Dependencia: el conductor usa el vehículo temporalmente
};

#endif //CONDUCTOR_H
