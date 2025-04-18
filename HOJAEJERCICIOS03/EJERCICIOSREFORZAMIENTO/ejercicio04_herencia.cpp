//
// Created by c0d3r on 18/04/2025.
//

/**
*EJERCICIO 4 - HERENCIA
Crea una clase base llamada Animal con un atributo nombre y un metodo virtual
emitirSonido(). Luego, crea dos clases derivadas: Perro y Gato, que hereden de Animal y
proporcionen sus propias implementaciones específicas del metodo emitirSonido().
Escribe el código en C++ para crear objetos de las clases derivadas y llamar a su metodo
emitirSonido() para observar el polimorfismo.
*/

#include <iostream>
#include <string>
using namespace std;

class ANIMAL
{
protected:
    string nombre;

public:
    ANIMAL(string n) : nombre(n)
    {
    }

    virtual void emitirSonido() const = 0; // Metodo virtual puro

    virtual ~ANIMAL()
    {
    } // Destructor virtual para permitir la limpieza adecuada
};

class PERRO : public ANIMAL
{
public:
    PERRO(string n) : ANIMAL(n)
    {
    }

    void emitirSonido() const override
    {
        cout << nombre << " dice: Guau!" << endl;
    }
};

class GATO : public ANIMAL
{
public:
    GATO(string n) : ANIMAL(n)
    {
    }

    void emitirSonido() const override
    {
        cout << nombre << " dice: Miau!" << endl;
    }
};

int main()
{
    ANIMAL* miPerro = new PERRO("Firulais");
    ANIMAL* miGato = new GATO("Michi");

    miPerro->emitirSonido();
    miGato->emitirSonido();

    delete miPerro;
    delete miGato;

    return 0;
}
