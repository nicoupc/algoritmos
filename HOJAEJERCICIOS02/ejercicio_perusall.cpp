//
// Created by c0d3r on 12/04/2025.
//

/**
*
El planeta Tierra esta siendo amenazado por seres de otras galaxias. Se le solicita diseñar un sistema para gestionar
alianzas temporales entre superheroes y villanos usando relaciones de asociacion (POO). En este universo, los
personajes pueden unirse para misiones especificas, pero mantienen sus identidades y habilidades independientes.
Entidades a implementar:
Clase Superheroe:
-Atributos: nombre, poderPrincipal, debilidad (string).
-Metodos: unirseAMision(), mostrarInfo().
Clase Villano:
Atributos: alias, objetivoSiniestro, nivelAmenaza
Metodos: proponerAlianza() sabotear().
Clase Mision:
Atributos: codigo, descripcion, esCritica (bool).
Metodos: agregarParticipante(), iniciarMision().
Relaciones de asociacion:
-Un Superheroe o Villano puede asociarse a una Mision sin pertenecer a ella permanentemente y para ello puede
usar una lista de participantes dentro de Mision.
-La Mision utiliza las habilidades de los personajes, pero no los controla.
Simule una mision donde 1 villano y 2 superheroes se alian contra una amenaza mayor. Muestra como interactuan
durante la mision.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Superheroe
{
private:
    string nombre;
    string poderPrincipal;
    string debilidad;

public:
    Superheroe(string n, string p, string d) : nombre(n), poderPrincipal(p), debilidad(d)
    {
    }

    string getNombre() { return nombre; }

    void unirseAMision()
    {
        cout << nombre << " se une a la mision con su poder principal: " << poderPrincipal << endl;
    }

    void mostrarInfo()
    {
        cout << "Superheroe: " << nombre << ", Poder Principal: " << poderPrincipal << ", Debilidad: " << debilidad <<
            endl;
    }
};

class Villano
{
private:
    string alias;
    string objetivoSiniestro;
    int nivelAmenaza;

public:
    Villano(string a, string o, int n) : alias(a), objetivoSiniestro(o), nivelAmenaza(n)
    {
    }

    string getAlias() { return alias; }

    void proponerAlianza()
    {
        cout << alias << " propone una alianza temporal para enfrentar una amenaza mayor" << endl;
    }

    void sabotear()
    {
        cout << "Oh no! " << alias << " intenta sabotear la mision!" << endl;
    }

    void mostrarInfo()
    {
        cout << "Villano: " << alias << ", Objetivo: " << objetivoSiniestro << ", Nivel de Amenaza: " << nivelAmenaza <<
            endl;
    }
};

class Mision
{
private:
    string codigo;
    string descripcion;
    bool esCritica;
    vector<string> participantes;

public:
    Mision(string c, string d, bool e) : codigo(c), descripcion(d), esCritica(e)
    {
    }

    void agregarParticipante(string p)
    {
        participantes.push_back(p);
        cout << p << " se ha agregado a la mision." << endl;
    }

    void iniciarMision()
    {
        cout << "Iniciando mision: " << codigo << ", Descripcion: " << descripcion << endl;
        cout << "Participantes: ";
        for (const auto& p : participantes)
        {
            cout << p << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Crear superheroes
    Superheroe sp1("Superman", "Vuelo", "Kryptonita");
    Superheroe sp2("Ironman", "Tecnologia", "Ninguna");

    // Mostrar info de superheroes
    sp1.mostrarInfo();
    sp2.mostrarInfo();

    // Crear villano
    Villano v1("Thanos", "Dominar el mundo", 10);

    // Mostrar info de villano
    v1.mostrarInfo();

    cout << endl;

    // Crear mision
    Mision m1("4V3NG3RS", "Defender el planeta de una invasion alienigena", true);

    // Mostrar info de mision
    sp1.unirseAMision();
    m1.agregarParticipante(sp1.getNombre());

    sp2.unirseAMision();
    m1.agregarParticipante(sp2.getNombre());

    v1.proponerAlianza();
    m1.agregarParticipante(v1.getAlias());

    cout << endl;
    m1.iniciarMision();

    // Simular sabotaje
    cout << endl;
    v1.sabotear();

    return 0;
}
