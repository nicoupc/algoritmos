//
// Created by c0d3r on 16/04/2025.
//

/**
 *EJERCICIO 1- Asociación
*En una escuela de Lurigancho-Chosica, cada Estudiante pertenece a un solo Aula. Un Aula
puede tener varios Estudiantes. Modela esta relación de asociación unidireccional (desde
Estudiante hacia Aula) y escribe el código en C++ que permita crear estudiantes, aulas,
asignar estudiantes a aulas y mostrar el aula al que pertenece un estudiante.
*/

#include <iostream> // Para cout y cin
#include <string> // Para string
using namespace std;

class AULA
{
private:
    string nombre;

public:
    AULA(string nombre)
    {
        this->nombre = nombre;
    }

    string getNombre() const
    {
        return nombre;
    }
};

class ESTUDIANTE
{
private:
    string nombre;
    AULA* aula; // Puntero a un objeto AULA

public:
    ESTUDIANTE(string nombre)
    {
        this->nombre = nombre;
        this->aula = nullptr; // Inicialmente no tiene aula asignada
    }

    void asignarAula(AULA* aula)
    {
        this->aula = aula;
    }

    void mostrarAulaAsignada() const
    {
        if (aula != nullptr)
        {
            cout << "El estudiante " << nombre << " pertenece al aula: " << aula->getNombre() << endl;
        }
        else
        {
            cout << "El estudiante " << nombre << " no tiene aula asignada." << endl;
        }
    }
};

int main()
{
    AULA aulaPrimeroA("1ro A");
    AULA aulaSegundoB("2do B");

    ESTUDIANTE estudiante1("Juan Perez");
    ESTUDIANTE estudiante2("Maria Lopez");
    ESTUDIANTE estudiante3("Carlos Garcia");

    // Asignar estudiantes a aulas
    estudiante1.asignarAula(&aulaPrimeroA);
    estudiante2.asignarAula(&aulaSegundoB);
    estudiante3.asignarAula(&aulaPrimeroA);

    // Mostrar aula asignada a cada estudiante
    cout << "\nEstado de los estudiantes:\n";

    estudiante1.mostrarAulaAsignada();
    estudiante2.mostrarAulaAsignada();
    estudiante3.mostrarAulaAsignada();

    return 0;
}
