//
// Created by c0d3r on 02/05/2025.
//

#include "Boleto.h"
#include "Hotel.h"
#include "PlanVacacion.h"

void mostrarVacacionesEnIntervalo(const vector<PlanVacacion>& planes, const string& fechaInicio, const string& fechaFin)
{
    cout << "Planes de vacaciones entre " << fechaInicio << " y " << fechaFin << ":" << endl;
    for (const auto& plan : planes)
    {
        if (plan.getFechaInicio() >= fechaInicio && plan.getFechaFin() <= fechaFin)
        {
            cout << "Nombre del Plan: " << plan.getNombrePlan() << endl;
        }
    }
}

void mostrarVacacionesPorHotel(const vector<PlanVacacion>& planes, const string& nombreHotel)
{
    cout << "Planes de vacaciones en el hotel " << nombreHotel << ":" << endl;
    for (const auto& plan : planes)
    {
        for (const auto& hotel : plan.getHoteles())
        {
            if (hotel.getNombre() == nombreHotel)
            {
                cout << "Nombre del Plan: " << plan.getNombrePlan() << endl;
            }
        }
    }
}

void mostrarBoletosPorPlan(PlanVacacion& plan)
{
    cout << "Boletos del plan " << plan.getNombrePlan() << ":" << endl;
    for (auto& boleto : plan.getBoletosAdicionales())
    {
        boleto.mostrarInformacion();
        cout << endl;
    }
}

int main()
{
    // Creamos los boletos
    Boleto boleto1("Lima", "Cusco", "2025-06-01", 150.0);
    Boleto boleto2("Cusco", "Machu Picchu", "2025-06-10", 150.0);

    // Creamos los hoteles
    Hotel hotel1("Hotel A", "Cusco", 5, 200.0);
    Hotel hotel2("Hotel B", "Machu Picchu", 4, 180.0);

    // Crear un plan de vacaciones
    PlanVacacion planVacacionA("Vacaciones en Cusco", "2025-06-01", "2025-06-10");

    // Agregamos boletos y hoteles al plan de vacaciones
    planVacacionA.agregarBoleto(boleto1);
    planVacacionA.agregarBoleto(boleto2);

    planVacacionA.agregarHotel(hotel1);
    planVacacionA.agregarHotel(hotel2);

    // Creamos un vector de planes de vacaciones
    vector<PlanVacacion> planes;
    planes.push_back(planVacacionA);

    // Mostramos las vacaciones en un intervalo de fechas y por hotel
    mostrarVacacionesEnIntervalo(planes, "2025-06-01", "2025-06-10");
    cout << endl;

    // Mostramos las vacaciones por hotel
    mostrarVacacionesPorHotel(planes, "Hotel A");
    cout << endl;

    // Mostramos los boletos por plan de vacaciones
    mostrarBoletosPorPlan(planVacacionA);

    return 0;
}
