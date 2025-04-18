//
// Created by c0d3r on 16/04/2025.
//

/**
*EJERCICIO 3- COMPOSICIoN
Considera un Automovil que se utiliza para el transporte en Lurigancho-Chosica. Cada
automovil tiene un Motor que es una parte esencial para su funcionamiento y no puede
existir independientemente del automovil. Modela esta relacion de composicion y escribe
el codigo en C++ que permita crear automoviles con su motor y mostrar la informacion del
automovil, incluyendo el tipo de motor.
*/

#include <iostream> // Para cout y cin
#include <string> // Para string
using namespace std;

class MOTOR
{
private:
    string tipo;

public:
    MOTOR(string t) : tipo(t)
    {
    } // Constructor con parametro

    void mostrarTipoMotor() const
    {
        cout << "Tipo de motor: " << tipo << endl;
    }
};

class AUTOMOVIL
{
private:
    string marca;
    string modelo;
    MOTOR motor; // Composicion: el automovil tiene un motor

public:
    AUTOMOVIL(string m, string mod, string tipoMotor) : marca(m), modelo(mod), motor(tipoMotor)
    {
    } // Constructor con parametros

    void mostrarInformacion() const
    {
        cout << "Marca: " << marca << ", Modelo: " << modelo << endl;
        motor.mostrarTipoMotor(); // Mostrar tipo de motor
    }
};

int main()
{
    AUTOMOVIL auto1("Toyota", "Corolla", "Gasolina");
    AUTOMOVIL auto2("Honda", "Civic", "Hibrido");
    AUTOMOVIL auto3("Ford", "Mustang", "Electrico");

    auto1.mostrarInformacion();
    auto2.mostrarInformacion();
    auto3.mostrarInformacion();

    return 0;
}
