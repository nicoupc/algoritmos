//
// Created by c0d3r on 23/04/2025.
//

#include "Persona.h"

using namespace std;

// Constructor con parámetros
Persona::Persona(const string& nombre, const string& dni): nombre_(nombre), dni_(dni)
{
}

void Persona::saltar() const
{
    cout << nombre_ << " haz 50 mariposas" << endl;
}

void Persona::piernas() const
{
    cout << nombre_ << " haz 50 ranas" << endl;
}

void Persona::descansar() const
{
    cout << nombre_ << " toma agua y descansa 10 minutos" << endl;
}

void Persona::setNombre(string nombre)
{
    this->nombre_ = nombre;
}

string Persona::getNombre() const
{
    return nombre_;
}

void Persona::setDni(string dni)
{
    this->dni_ = dni;
}

string Persona::getDni() const
{
    return dni_;
}

void Persona::mostrar() const
{
    cout << "Nombre: " << nombre_ << endl;
    cout << "DNI: " << dni_ << endl;
}
