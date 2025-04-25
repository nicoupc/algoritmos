//
// Created by c0d3r on 18/04/2025.
//

#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <string>
using namespace std;

class Motor
{
private:
    string tipo_; // Tipo de motor (por ejemplo, "eléctrico", "combustión")
    int potencia_; // Potencia del motor en caballos de fuerza (HP)

public:
    // Constructor
    Motor(const string& tipo, int potencia);

    // Métodos de la clase
    void mostrarInfo() const;
};

#endif //MOTOR_H
