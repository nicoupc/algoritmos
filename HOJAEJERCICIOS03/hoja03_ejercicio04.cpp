//
// Created by c0d3r on 17/04/2025.
//

/**
*Considerando el siguiente diagrama de clases codificar:
▪ Teniendo el diagrama de clases implemente use .hpp y CPP
a) Clase Animal, constructores, destructor, métodos de comportamiento.
b) Clase Diagnóstico, constructores, destructor, métodos de comportamiento.
c) Clase Personal, constructores, destructor, métodos de comportamiento.
d) Implementación de relaciones entre clases (instancias)
▪ Los diagnósticos deben ser almacenados en un recolector de objetos
▪ Implementación de pruebas mediante reportes
1. Use un menú de opciones:
[1.Insertar Personal, 2.Insertar Animal, 3. Realizar Diagnóstico, 4.Reportes, 5.Salir]
2. Logra recolectar los diagnósticos en un recolector de objetos
3. Muestre el reporte de diagnósticos.
4. Muestre el reporte del animal con sus respectivos
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ANIMAL
{
private:
    string nombre;
    string tipo;
    int edad;

public:
    ANIMAL(string nom, string tip, int ed)
        : nombre(nom), tipo(tip), edad(ed)
    {
    }

    void mostrar()
    {
        cout << "Nombre del animal: " << nombre << ", Tipo: " << tipo
            << ", Edad: " << edad << endl;
    }

    void setNombre(string nom) { nombre = nom; }
    void setTipo(string tip) { tipo = tip; }
    void setEdad(int ed) { edad = ed; }

    string getNombre() { return nombre; }
    string getTipo() { return tipo; }
    int getEdad() { return edad; }
};

class PERSONAL
{
private:
    string nombre;
    string apellidos;
    string fechaContratacion;

public:
    PERSONAL(string nom, string ape, string fecha)
        : nombre(nom), apellidos(ape), fechaContratacion(fecha)
    {
    }

    void mostrar()
    {
        cout << "Nombre del personal: " << nombre << ", Apellidos: " << apellidos
            << ", Fecha de contratacion: " << fechaContratacion << endl;
    }

    void setNombre(string nom) { nombre = nom; }
    void setApellidos(string ape) { apellidos = ape; }
    void setFechaContratacion(string fecha) { fechaContratacion = fecha; }

    string getNombre() { return nombre; }
    string getApellidos() { return apellidos; }
    string getFechaContratacion() { return fechaContratacion; }
};

class DIAGNOSTICO
{
private:
    string fecha;
    string descripcion;
    ANIMAL animal;
    PERSONAL personal;

public:
    DIAGNOSTICO(string fecha, string desc, ANIMAL ani, PERSONAL per)
        : fecha(fecha), descripcion(desc), animal(ani), personal(per)
    {
    }

    void mostrar()
    {
        cout << "Fecha del diagnostico: " << fecha << ", Descripcion: " << descripcion
            << endl;
        personal.mostrar();
        animal.mostrar();
    }

    void setFecha(string f) { fecha = f; }
    void setDescripcion(string desc) { descripcion = desc; }

    string getFecha() { return fecha; }
    string getDescripcion() { return descripcion; }
};

class RECOLECTOR
{
private:
    vector<DIAGNOSTICO> diagnosticos;

public:
    void agregarDiagnostico(DIAGNOSTICO diag)
    {
        diagnosticos.push_back(diag);
    }

    void mostrarDiagnosticos()
    {
        for (auto& diag : diagnosticos)
        {
            diag.mostrar();
            cout << "-------------------------" << endl;
        }
    }
};

void mostrarMenu()
{
    cout << "\n****** MENU ******\n";
    cout << "1. Insertar Personal\n";
    cout << "2. Insertar Animal\n";
    cout << "3. Realizar Diagnostico\n";
    cout << "4. Reportes\n";
    cout << "5. Salir\n";
}

void insertarPersonal(vector<PERSONAL>& personal)
{
    string nombre, apellidos, fecha;
    cout << "Ingrese el nombre del personal: ";
    cin >> nombre;
    cout << "Ingrese los apellidos del personal: ";
    cin >> apellidos;
    cout << "Ingrese la fecha de contratacion (DD/MM/AAAA): ";
    cin >> fecha;

    PERSONAL nuevoPersonal(nombre, apellidos, fecha);
    personal.push_back(nuevoPersonal);

    // Mostrar el personal registrado
    cout << "Personal registrado correctamente:\n";
    for (auto& p : personal)
    {
        p.mostrar();
    }
}

void insertarAnimal(vector<ANIMAL>& animales)
{
    string nombre, tipo;
    int edad;
    cout << "Ingrese el nombre del animal: ";
    cin >> nombre;
    cout << "Ingrese el tipo de animal: ";
    cin >> tipo;
    cout << "Ingrese la edad del animal: ";
    cin >> edad;

    ANIMAL nuevoAnimal(nombre, tipo, edad);
    animales.push_back(nuevoAnimal);

    // Mostrar el animal registrado
    cout << "Animal registrado correctamente:\n";
    for (auto& a : animales)
    {
        a.mostrar();
    }
}

void realizarDiagnostico(RECOLECTOR& recolector, vector<ANIMAL>& animales, vector<PERSONAL>& personal)
{
    // Verificar si hay animales y personal registrados
    if (animales.empty() || personal.empty())
    {
        cout << "No hay animales o personal registrados." << endl;
        return;
    }

    // Solicitar datos del diagnostico
    string fecha, descripcion;
    cout << "Ingrese la fecha del diagnostico (DD/MM/AAAA): ";
    cin >> fecha;
    cout << "Ingrese la descripcion del diagnostico: ";
    cin.ignore();
    getline(cin, descripcion);

    // Seleccionar animal
    cout << "Seleccione un animal:\n";
    for (int i = 0; i < animales.size(); i++)
    {
        cout << i << ". " << animales[i].getNombre() << endl;
    }
    int indexAnimal;
    cout << "Ingrese el indice del animal (0 a " << animales.size() - 1 << "): ";
    cin >> indexAnimal;
    if (indexAnimal < 0 || indexAnimal >= animales.size())
    {
        cout << "Indice invalido." << endl;
        return;
    }
    ANIMAL animalSeleccionado = animales[indexAnimal];

    // Seleccionar personal
    cout << "Seleccione un personal:\n";
    for (int i = 0; i < personal.size(); i++)
    {
        cout << i << ". " << personal[i].getNombre() << endl;
    }
    int indexPersonal;
    cout << "Ingrese el indice del personal (0 a " << personal.size() - 1 << "): ";
    cin >> indexPersonal;
    if (indexPersonal < 0 || indexPersonal >= personal.size())
    {
        cout << "Indice invalido." << endl;
        return;
    }
    PERSONAL personalSeleccionado = personal[indexPersonal];

    // Crear el diagnostico
    DIAGNOSTICO nuevoDiagnostico(fecha, descripcion, animalSeleccionado, personalSeleccionado);
    recolector.agregarDiagnostico(nuevoDiagnostico);
    cout << "Diagnostico registrado correctamente." << endl;
}

void mostrarReportes(RECOLECTOR& recolector)
{
    cout << "\n****** REPORTES ******\n";
    recolector.mostrarDiagnosticos();
}

int main()
{
    vector<PERSONAL> personal;
    vector<ANIMAL> animales;
    RECOLECTOR recolector;

    int opcion;
    do
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            insertarPersonal(personal);
            break;
        case 2:
            insertarAnimal(animales);
            break;
        case 3:
            realizarDiagnostico(recolector, animales, personal);
            break;
        case 4:
            mostrarReportes(recolector);
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }
    }
    while (opcion != 5);

    return 0;
}
