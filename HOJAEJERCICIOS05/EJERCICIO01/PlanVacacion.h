//
// Created by c0d3r on 02/05/2025.
//

#ifndef PLANVACACION_H
#define PLANVACACION_H

#include "Boleto.h"
#include "Hotel.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Clase PlanVacacion que hereda de Boleto y Hotel
class PlanVacacion : public Boleto, public Hotel
{
private:
    string nombrePlan;
    vector<Boleto> boletosAdicionales; // Lista de boletos adicionales
    vector<Hotel> hoteles; // Lista de hoteles asociados al plan
    string fechaInicio;
    string fechaFin;

public:
    // Constructor con parametros
    PlanVacacion(string nombrePlan, string fechaInicio, string fechaFin)
        : nombrePlan(nombrePlan), fechaInicio(fechaInicio), fechaFin(fechaFin)
    {
    }

    void agregarBoleto(const Boleto& boleto)
    {
        boletosAdicionales.push_back(boleto);
    }

    void agregarHotel(const Hotel& hotel)
    {
        hoteles.push_back(hotel);
    }

    // Getters
    string getNombrePlan() const { return nombrePlan; }
    string getFechaInicio() const { return fechaInicio; }
    string getFechaFin() const { return fechaFin; }

    vector<Boleto> getBoletosAdicionales() const { return boletosAdicionales; }
    vector<Hotel> getHoteles() const { return hoteles; }

    // Metodo para mostrar la informacion del plan de vacaciones
    void mostrarInformacion()
    {
        cout << "Nombre del plan: " << nombrePlan << endl;
        cout << "Fecha de inicio: " << fechaInicio << endl;
        cout << "Fecha de fin: " << fechaFin << endl;
        cout << "Boletos adicionales:" << endl;
        for (auto& boleto : boletosAdicionales)
        {
            boleto.mostrarInformacion();
            cout << endl;
        }
        cout << "Hoteles asociados:" << endl;
        for (auto& hotel : hoteles)
        {
            hotel.mostrarInformacion();
            cout << endl;
        }
    }
};

#endif //PLANVACACION_H
