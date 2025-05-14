//
// Created by c0d3r on 02/05/2025.
//

#ifndef BOLETO_H
#define BOLETO_H

#include <iostream>
#include <string>
using namespace std;

class Boleto
{
private:
    string origen;
    string destino;
    string fecha;
    float precio;

public:
    // Constructor por defecto
    Boleto()
    {
        origen = "";
        destino = "";
        fecha = "";
        precio = 0.0;
    }

    // Constructor con parametros
    Boleto(string origen, string destino, string fecha, float precio)
    {
        this->origen = origen;
        this->destino = destino;
        this->fecha = fecha;
        this->precio = precio;
    }

    // Getters
    string getOrigen() const { return origen; }
    string getDestino() const { return destino; }
    string getFecha() const { return fecha; }
    float getPrecio() const { return precio; }

    // Mostramos la informacion del boleto
    void mostrarInformacion()
    {
        cout << "Origen: " << origen
            << ", Destino: " << destino
            << ", Fecha: " << fecha
            << ", Precio: $" << precio << endl;
    }
};

#endif //BOLETO_H
