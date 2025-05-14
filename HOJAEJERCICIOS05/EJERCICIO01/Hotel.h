//
// Created by c0d3r on 02/05/2025.
//

#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
using namespace std;

class Hotel
{
private:
    string nombre;
    string ubicacion;
    int estrellas;
    float precioPorNoche;

public:
    // Constructor por defecto
    Hotel()
    {
        nombre = "";
        ubicacion = "";
        estrellas = 0;
        precioPorNoche = 0.0;
    }

    // Constructor con parametros
    Hotel(string nombre, string ubicacion, int estrellas, float precioPorNoche)
    {
        this->nombre = nombre;
        this->ubicacion = ubicacion;
        this->estrellas = estrellas;
        this->precioPorNoche = precioPorNoche;
    }

    // Getters
    string getNombre() const { return nombre; }
    string getUbicacion() const { return ubicacion; }
    int getEstrellas() const { return estrellas; }
    float getPrecioPorNoche() const { return precioPorNoche; }

    // Mostramos la informacion del hotel
    void mostrarInformacion()
    {
        cout << "Nombre: " << nombre
            << ", Ubicacion: " << ubicacion
            << ", Estrellas: " << estrellas
            << ", Precio por Noche: $" << precioPorNoche << endl;
    }
};

#endif //HOTEL_H
