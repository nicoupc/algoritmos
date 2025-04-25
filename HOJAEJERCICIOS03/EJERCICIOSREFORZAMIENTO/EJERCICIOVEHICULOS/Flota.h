//
// Created by c0d3r on 18/04/2025.
//

#ifndef FLOTA_H
#define FLOTA_H

#include "Vehiculo.h"
#include "Compania.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Flota
{
private:
    Compania compania_; // Composición: la flota pertenece a una compañía
    vector<Vehiculo*> vehiculos_; // Vector de punteros a vehículos (agregación: la flota contiene vehículos)

public:
    // Constructor
    Flota(const Compania& compania);

    // Metodo para agregar un vehículo a la flota
    void agregarVehiculo(Vehiculo* vehiculo);

    // Metodo para mostrar la información de la flota
    void mostrarInfo() const;
};

#endif //FLOTA_H
