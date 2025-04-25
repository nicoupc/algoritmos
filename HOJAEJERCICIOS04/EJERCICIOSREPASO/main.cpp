#include "Persona.h"
#include "iostream"
#include "string"
using namespace std;

int main()
{
    string nombre, dni;
    int opcion;

    cout << "****** BIENVENIDO AL GIMNASIO ******" << endl;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Ingrese su DNI: ";
    getline(cin, dni);
    cout << endl;

    Persona persona1(nombre, dni);

    do
    {
        cout << "Que quieres hacer?" << endl;
        cout << "1. Saltar" << endl;
        cout << "2. Piernas" << endl;
        cout << "3. Descansar" << endl;
        cout << "4. Cambiar nombre" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << endl;

        switch (opcion)
        {
        case 1:
            persona1.saltar();
            break;
        case 2:
            persona1.piernas();
            break;
        case 3:
            persona1.descansar();
            break;
        case 4:
            cout << "Ingrese el nuevo nombre: ";
            getline(cin, nombre);
            persona1.setNombre(nombre);
            cout << "Nombre cambiado a: " << persona1.getNombre() << endl;
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            return 0;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    }
    while (opcion != 5);

    return 0;
}
