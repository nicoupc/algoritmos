//
// Created by c0d3r on 24/04/2025.
//

#include "Motor.h"

Motor::Motor(const string& tipo, int potencia) : tipo_(tipo), potencia_(potencia)
{
}

void Motor::mostrarInfo() const
{
    cout << "Tipo de motor: " << tipo_ << ", Potencia: " << potencia_ << " HP" << endl;
}
