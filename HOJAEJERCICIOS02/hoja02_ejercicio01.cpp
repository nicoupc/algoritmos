//
// Created by c0d3r on 12/04/2025.
//

/**
*Eclipse
Un nuevo eclipse se aproxima y los astronomos requieren un sistema que les permita
registrar los acontecimientos que se produjeron antes, durante y despues en los eclipses
ocurridos los ultimos 10 años. La informacion que se requiere manejar es la siguiente:
Tipo de eclipse (solar o lunar), Fecha, Hora (ejemplo: 100=1am, 300= 3am, 800=8am, 1200=12
del dia, 1400=2pm, etc), Sismos (si o no), Lluvias (si o no), Continente de mayor Visibilidad
(America del Sur, Europa, Africa, America del Norte, Asia)
Con esta informacion Pierre desarrollara una aplicacion y utilizara la tecnica de programacion
orientada a objetos (POO). El programa requiere tener lo siguiente:
a) Implementacion de una Clase para manejar la informacion descrita
a. La clase debe tener atributos como:
b) Tipo de Eclipse
c) Fecha
d) Hora
e) Sismos
f) Lluvias
g) Visibilidad
a. Los metodos que debe tener la clase quedaran bajo su criterio, dependiendo de la
necesidad del problema
h) Registro de Datos
i) Haciendo uso de arreglo dinamicos realice las implementaciones necesarias para
almacenar la informacion de “N” elementos
j) Modificar datos
k) Uso de componente y validacion del objeto a modificar
l) Eliminar un dato
m) Uso de componente y validacion del objeto a eliminar
n) Reporte de eclipses que fueron visibles en Europa
o) Reporte de eclipses que ocasionaron sismos
p) Reporte de eclipses que se produjeron en la noche
*/

#include <iostream> // Para cout y cin
#include <string> // Para string
#include <vector> // Para vector
using namespace std;

class ECLIPSE
{
private:
    string tipoEclipse; // Tipo de eclipse (solar o lunar)
    string fecha; // Fecha del eclipse
    int hora; // Hora del eclipse (ejemplo: 100=1am, 300=3am, etc)
    bool sismos; // Si hubo sismos (true o false)
    bool lluvias; // Si hubo lluvias (true o false)
    string continente; // Continente de mayor visibilidad

public:
    // Constructor por defecto
    ECLIPSE()
    {
        tipoEclipse = "";
        fecha = "";
        hora = 0;
        sismos = false;
        lluvias = false;
        continente = "";
    }

    // Constructor con parametros
    ECLIPSE(string tipo, string f, int h, bool s, bool l, string c)
    {
        tipoEclipse = tipo;
        fecha = f;
        hora = h;
        sismos = s;
        lluvias = l;
        continente = c;
    }

    // Metodos de acceso (getters y setters)
    string getTipoEclipse() { return tipoEclipse; }
    void setTipoEclipse(string tipo) { tipoEclipse = tipo; }

    string getFecha() { return fecha; }
    void setFecha(string f) { fecha = f; }

    int getHora() { return hora; }
    void setHora(int h) { hora = h; }

    bool getSismos() { return sismos; }
    void setSismos(bool s) { sismos = s; }

    bool getLluvias() { return lluvias; }
    void setLluvias(bool l) { lluvias = l; }

    string getContinente() { return continente; }
    void setContinente(string c) { continente = c; }

    // Metodo para mostrar informacion del eclipse
    string toString()
    {
        return "Tipo de Eclipse: " + tipoEclipse + "\nFecha: " + fecha + "\nHora: " + to_string(hora) +
            "\nSismos: " + (sismos ? "Si" : "No") + "\nLluvias: " + (lluvias ? "Si" : "No") +
            "\nContinente de Visibilidad: " + continente;
    }
};

void mostrarMenu()
{
    cout << "\n****** MENU ******\n";
    cout << "1. Registrar Eclipses\n";
    cout << "2. Mostrar Eclipses\n";
    cout << "3. Modificar Eclipses\n";
    cout << "4. Eliminar Eclipses\n";
    cout << "5. Reporte de Eclipses visibles en Europa\n";
    cout << "6. Reporte de Eclipses que ocasionaron sismos\n";
    cout << "7. Reporte de Eclipses que se produjeron en la noche\n";
    cout << "8. Salir\n";
}

void mostrarEclipses(vector<ECLIPSE>& eclipses)
{
    cout << "\n****** ECLIPSES REGISTRADOS ******\n";
    for (auto& eclipse : eclipses) // Usar referencia para evitar copias innecesarias
    {
        cout << eclipse.toString() << endl;
        cout << endl;
    }
}

void registrarEclipse(vector<ECLIPSE>& eclipses)
{
    string tipo, fecha, continente;
    int hora;
    bool sismos, lluvias;

    cout << "\nIngrese el tipo de eclipse (solar/lunar): ";
    cin >> tipo;
    cout << "Ingrese la fecha (dd/mm/aaaa): ";
    cin >> fecha;
    cout << "Ingrese la hora (ejemplo: 100=1am, 300=3am, etc): ";
    cin >> hora;
    cout << "Hubo sismos? (1 para si, 0 para no): ";
    cin >> sismos;
    cout << "Hubo lluvias? (1 para si, 0 para no): ";
    cin >> lluvias;
    cout <<
        "Ingrese el continente de mayor visibilidad (America del Sur, Europa, Africa, America del Norte, Asia): ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, continente); // Permite ingresar continentes con espacios

    ECLIPSE nuevoEclipse(tipo, fecha, hora, sismos, lluvias, continente); // Crear un nuevo objeto ECLIPSE
    eclipses.push_back(nuevoEclipse); // Agregar el eclipse al vector

    cout << "\nEclipse registrado:\n";
    cout << nuevoEclipse.toString() << endl;
}

void modificarEclipse(vector<ECLIPSE>& eclipses)
{
    mostrarEclipses(eclipses); // Mostrar eclipses registrados

    int index;
    cout << "Ingrese el indice del eclipse a modificar (0 a " << eclipses.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < eclipses.size())
    {
        string tipo, fecha, continente;
        int hora;
        bool sismos, lluvias;

        cout << "\nIngrese el nuevo tipo de eclipse (solar/lunar): ";
        cin >> tipo;
        cout << "Ingrese la nueva fecha (dd/mm/aaaa): ";
        cin >> fecha;
        cout << "Ingrese la nueva hora (ejemplo: 100=1am, 300=3am, etc): ";
        cin >> hora;
        cout << "Hubo sismos? (1 para si, 0 para no): ";
        cin >> sismos;
        cout << "Hubo lluvias? (1 para si, 0 para no): ";
        cin >> lluvias;
        cout <<
            "Ingrese el nuevo continente de mayor visibilidad (America del Sur, Europa, Africa, America del Norte, Asia): ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, continente); // Permite ingresar continentes con espacios

        eclipses[index].setTipoEclipse(tipo);
        eclipses[index].setFecha(fecha);
        eclipses[index].setHora(hora);
        eclipses[index].setSismos(sismos);
        eclipses[index].setLluvias(lluvias);
        eclipses[index].setContinente(continente);

        cout << "\nEclipse modificado:\n";
        cout << eclipses[index].toString() << endl;
    }
    else
    {
        cout << "Indice invalido." << endl;
    }
}

void eliminarEclipse(vector<ECLIPSE>& eclipses)
{
    mostrarEclipses(eclipses); // Mostrar eclipses registrados

    int index;
    cout << "Ingrese el indice del eclipse a eliminar (0 a " << eclipses.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < eclipses.size())
    {
        eclipses.erase(eclipses.begin() + index); // Eliminar el eclipse del vector
        cout << "Eclipse eliminado correctamente.\n";
    }
    else
    {
        cout << "Indice invalido." << endl;
    }
}


void reporteEclipsesEuropeos(vector<ECLIPSE>& eclipses)
{
    cout << "\n****** ECLIPSES VISIBLES EN EUROPA ******\n";
    for (auto& eclipse : eclipses)
    {
        if (eclipse.getContinente() == "Europa")
        {
            cout << eclipse.toString() << endl;
            cout << endl;
        }
    }
}

void reporteEclipsesSismos(vector<ECLIPSE>& eclipses)
{
    cout << "\n****** ECLIPSES QUE OCASIONARON SISMOS ******\n";
    for (auto& eclipse : eclipses)
    {
        if (eclipse.getSismos())
        {
            cout << eclipse.toString() << endl;
            cout << endl;
        }
    }
}

void reporteEclipsesNoche(vector<ECLIPSE>& eclipses)
{
    cout << "\n****** ECLIPSES QUE SE PRODUJERON EN LA NOCHE ******\n";
    for (auto& eclipse : eclipses)
    {
        if (eclipse.getHora() >= 1800) // Consideramos que la noche empieza a las 6pm (1800)
        {
            cout << eclipse.toString() << endl;
            cout << endl;
        }
    }
}

int main()
{
    int opcion;
    vector<ECLIPSE> eclipses; // Vector para almacenar los eclipses

    do
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarEclipse(eclipses);
            break;
        case 2:
            mostrarEclipses(eclipses);
            break;
        case 3:
            modificarEclipse(eclipses);
            break;
        case 4:
            eliminarEclipse(eclipses);
            break;
        case 5:
            reporteEclipsesEuropeos(eclipses);
            break;
        case 6:
            reporteEclipsesSismos(eclipses);
            break;
        case 7:
            reporteEclipsesNoche(eclipses);
            break;
        case 8:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente.\n";
        }
    }
    while (opcion != 8);

    return 0;
}
