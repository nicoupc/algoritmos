//
// Created by c0d3r on 18/04/2025.
//

/**
*EJERCICIO DE REPASO
Imagina un sistema para gestionar vehículos. Tenemos una clase base vehículo con
atributos comunes. Los vehículos pueden tener un Motor (composición: un vehículo tiene
un Motor esencial para su existencia). Un Conductor puede depender de un vehículo para
realizar su trabajo (dependencia: el conductor usa el vehículo temporalmente). Un
vehículo pertenece a una compañía (asociación: una compañía puede tener muchos
vehículos, y un vehículo pertenece a una compañía). Diferentes tipos de vehículos (como
Automovil y Motocicleta) heredan de vehículo y pueden tener características específicas.
Una Compañía puede agrupar varios vehículos en una Flota (agregación: la flota contiene
vehículos, pero los vehículos pueden existir independientemente).
*/

#include <iostream>
#include <string>
#include "Flota.h"
#include "Compania.h"
#include "Conductor.h"
#include "Motor.h"
#include "Automovil.h"
#include "Motocicleta.h"
using namespace std;

int main()
{
    // Crear un motor
    Motor motor1("electrico", 150);
    Motor motor2("combustion", 200);

    // Crear vehículos
    Automovil auto1("Toyota", "Corolla", motor1, 4, "sedan");
    Motocicleta moto1("Harley Davidson", "Street 750", motor2, true);

    // Crear una compañía
    Compania compania("Compania de Transporte");

    // Crear una flota y agregar vehículos
    Flota flota(compania);
    flota.agregarVehiculo(&auto1);
    flota.agregarVehiculo(&moto1);

    // Mostrar información de la flota
    flota.mostrarInfo();

    // Crear un conductor y asignar un vehículo
    Conductor conductor("Juan Perez");
    conductor.asignarVehiculo(auto1);

    return 0;
}
