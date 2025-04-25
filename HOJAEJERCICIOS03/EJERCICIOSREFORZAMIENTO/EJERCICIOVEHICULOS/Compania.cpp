//
// Created by c0d3r on 24/04/2025.
//

#include "Compania.h"

Compania::Compania(const string& nombre) : nombre_(nombre)
{
}

string Compania::getNombre() const
{
    return nombre_;
}
