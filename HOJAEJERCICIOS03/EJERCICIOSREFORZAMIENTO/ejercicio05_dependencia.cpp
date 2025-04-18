//
// Created by c0d3r on 18/04/2025.
//

/**
*EJERCICIO 5 - DEPENDENCIA
Considera un Pasajero que utiliza un Taxi para viajar en Lurigancho-Chosica. La clase
Pasajero tiene un mtodo viajarEnTaxi() que toma un objeto Taxi como argumento. La
acción de viajar depende de la existencia de un Taxi, pero el Pasajero y el Taxi son entidades
separadas con ciclos de vida independientes. Modela esta relación de dependencia y
escribe el código en C++ que permita a un pasajero viajar en un taxi.
*/

#include <iostream>
#include <string>
using namespace std;

class TAXI
{
private:
    string placa;
    string modelo;
    string color;

public:
    TAXI(string p, string m, string c) : placa(p), modelo(m), color(c)
    {
    }

    void mostrarInformacion()
    {
        cout << "Taxi con placa " << placa << ", modelo " << modelo << ", color " << color << endl;
    }
};

class PASAJERO
{
private:
    string nombre;

public:
    PASAJERO(string n) : nombre(n)
    {
    }

    // Dependencia: el pasajero necesita un taxi para viajar
    void viajarEnTaxi(TAXI& taxi)
    {
        cout << nombre << " esta viajando en: ";
        taxi.mostrarInformacion();
    }
};

int main()
{
    // Crear un objeto TAXI
    TAXI taxi("ABC123", "Toyota", "Rojo");

    // Crear un objeto PASAJERO
    PASAJERO pasajero("Juan Perez");

    // El pasajero viaja en el taxi
    pasajero.viajarEnTaxi(taxi);

    return 0;
}
