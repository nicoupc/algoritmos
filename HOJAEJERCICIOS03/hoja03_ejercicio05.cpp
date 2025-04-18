//
// Created by c0d3r on 17/04/2025.
//

/**
*Usted viendo la acogida de empresas que brindan servicio de delivery “Mapi” y “Glopo”
por medio de un aplicativo, decide emprender su negocio del cual se encargará de
supervisar a todos los motorizados a nivel nacional que realicen delivery. Para ello usted
tendrá la opción de ingresar los datos de los motorizados, eliminarlos, mostrar el total y
visualizar los motorizados por empresas.
Considere S/.1.5 por kilómetro recorrido.

Clase: Motorizado
Atributos: Nombre, Apellido, Placa, kilometraje, Empresa
Método: Precio

Clase: ListaMotorizados
Atributos: Motorizado, numero_motorizados
Método: agregar_motorizado, eliminar_motorizado, motorizados_mapi,
motorizados_glopo. Motorizados_totales

Se mostrará un menú.
MENU
1.- Agregar Motorizado
2.- Eliminar Motorizado
3.- Mostrar Todos los Motorizados
4.- Motorizados Mapi
5.- Motorizados Glopo
6.- Salir
Seleccione la opción:

Al mostrar los motorizados de Glopo se debería visualizar lo siguiente:
Ejemplo:
Nombre Apellido Placa Kilometraje Precio Empresa
Juan Domingo 0342-BA 12 S/.18 Glopo
Use Clases y No utilice la clase <vector>
*/

#include <iostream>
#include <string>
#include <iomanip> // for std::setw and std::setprecision
using namespace std;

class MOTORIZADO
{
private:
    string nombre;
    string apellido;
    string placa;
    float kilometraje;
    string empresa;

public:
    MOTORIZADO()
    {
    }

    MOTORIZADO(string n, string a, string p, float k, string e)
        : nombre(n), apellido(a), placa(p), kilometraje(k), empresa(e)
    {
    }

    float precio()
    {
        return kilometraje * 1.5;
    }

    void mostrar()
    {
        cout << setw(15) << nombre
            << setw(15) << apellido
            << setw(15) << placa
            << setw(15) << kilometraje
            << setw(15) << fixed << setprecision(2) << precio()
            << setw(15) << empresa << endl;
    }

    string getEmpresa()
    {
        return empresa;
    }
};

class LISTAMOTORIZADOS
{
private:
    MOTORIZADO motorizados[100]; // Array estático de motorizados
    int numero_motorizados;

public:
    LISTAMOTORIZADOS()
    {
        numero_motorizados = 0;
    }

    void agregar_motorizado()
    {
        string nombre, apellido, placa, empresa;
        float kilometraje;

        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> apellido;
        cout << "Ingrese la placa: ";
        cin >> placa;
        cout << "Ingrese el kilometraje: ";
        cin >> kilometraje;
        cout << "Ingrese la empresa (Mapi/Glopo): ";
        cin >> empresa;

        motorizados[numero_motorizados] = MOTORIZADO(nombre, apellido, placa, kilometraje, empresa);
        numero_motorizados++;
        cout << "Motorizado agregado correctamente." << endl;
    }

    void eliminar_motorizado()
    {
        string placa;
        cout << "Ingrese la placa del motorizado a eliminar: ";
        cin >> placa;

        for (int i = 0; i < numero_motorizados; i++)
        {
            if (motorizados[i].getEmpresa() == placa)
            {
                for (int j = i; j < numero_motorizados - 1; j++)
                {
                    motorizados[j] = motorizados[j + 1];
                }
                numero_motorizados--;
                cout << "Motorizado eliminado correctamente." << endl;
                return;
            }
        }
        cout << "Motorizado no encontrado." << endl;
    }

    void mostrar_motorizados()
    {
        cout << setw(15) << "Nombre"
            << setw(15) << "Apellido"
            << setw(15) << "Placa"
            << setw(15) << "Kilometraje"
            << setw(15) << "Precio"
            << setw(15) << "Empresa" << endl;
        for (int i = 0; i < numero_motorizados; i++)
        {
            motorizados[i].mostrar();
        }
    }

    void mostrar_motorizados_empresa(string empresa)
    {
        cout << setw(15) << "Nombre"
            << setw(15) << "Apellido"
            << setw(15) << "Placa"
            << setw(15) << "Kilometraje"
            << setw(15) << "Precio"
            << setw(15) << "Empresa" << endl;
        for (int i = 0; i < numero_motorizados; i++)
        {
            if (motorizados[i].getEmpresa() == empresa)
            {
                motorizados[i].mostrar();
            }
        }
    }
};

void menu()
{
    cout << "\n****** MENU ******" << endl;
    cout << "1.- Agregar Motorizado" << endl;
    cout << "2.- Eliminar Motorizado" << endl;
    cout << "3.- Mostrar Todos los Motorizados" << endl;
    cout << "4.- Motorizados Mapi" << endl;
    cout << "5.- Motorizados Glopo" << endl;
    cout << "6.- Salir" << endl;
}

int main()
{
    LISTAMOTORIZADOS lista;
    int opcion;

    do
    {
        menu();
        cout << "Seleccione la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            lista.agregar_motorizado();
            break;
        case 2:
            lista.eliminar_motorizado();
            break;
        case 3:
            lista.mostrar_motorizados();
            break;
        case 4:
            cout << "Motorizados de Mapi:" << endl;
            lista.mostrar_motorizados_empresa("Mapi");
            break;
        case 5:
            cout << "Motorizados de Glopo:" << endl;
            lista.mostrar_motorizados_empresa("Glopo");
            break;
        case 6:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    }
    while (opcion != 6);

    return 0;
}
