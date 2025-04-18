//
// Created by c0d3r on 16/04/2025.
//

/**
 *EJERCICIO 2- Agregación
*En el zoologico de Lurigancho, cada Jaula puede contener varios Animales. Sin embargo,
un Animal puede existir independientemente de una Jaula (por ejemplo, podría estar en
tránsito o en un área de cuidado especial). Modela esta relacion de agregacion y escribe el
codigo en C++ que permita crear jaulas, animales, agregar animales a jaulas y mostrar los
animales que hay en una jaula.
*/

#include <iostream> // Para cout y cin
#include <string> // Para string
#include <vector> // Para vector
using namespace std;

class ANIMAL
{
private:
    string nombre; // Nombre del animal
    string especie; // Especie del animal

public:
    ANIMAL(string nombre, string especie) : nombre(nombre), especie(especie)
    {
    } // Constructor con parámetros

    void mostrarInformacion() const
    {
        cout << "Nombre: " << nombre << ", Especie: " << especie << endl;
    }
};

class JAULA
{
private:
    string codigo; // Código de la jaula
    vector<ANIMAL*> animales; // Vector de punteros a objetos AMINAL

public:
    JAULA(string codigo) : codigo(codigo)
    {
    } // Constructor con parámetros

    void agregarAnimal(ANIMAL* animal)
    {
        animales.push_back(animal); // Agrega el puntero al animal al vector
    }

    void mostrarAnimalesEnJaula() const
    {
        cout << "Jaula " << codigo << " contiene los siguientes animales:" << endl;
        for (const auto& animal : animales)
        {
            animal->mostrarInformacion(); // Muestra la información de cada animal
        }
    }
};

int main()
{
    ANIMAL leon("Simba", "Leon");
    ANIMAL tigre("Rajah", "Phantera tigris");
    ANIMAL mono("Coco", "Simia");

    JAULA jaulaFelinos("F-01");
    JAULA jaulaPrimates("P-02");

    jaulaFelinos.agregarAnimal(&leon);
    jaulaFelinos.agregarAnimal(&tigre);
    jaulaPrimates.agregarAnimal(&mono);

    cout << "\nInformacion de las jaulas:\n";
    jaulaFelinos.mostrarAnimalesEnJaula();
    cout << endl;
    jaulaPrimates.mostrarAnimalesEnJaula();
    cout << endl;

    return 0;
}
