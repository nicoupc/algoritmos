//
// Created by c0d3r on 17/04/2025.
//

/**
*2 La empresa La Lechera SAC preocupada por el problema ocasionado por el conglomerado
Nestle S.A, ha realizado una encuesta a nivel de Lima sobre la percepcion del cliente respecto
a la leche vendida por la compañia en los supermercados. La encuesta puntua de muy mala
(1) a muy buena (5) la percepcion respecto al contenido de la leche que la compañia vende
en los supermercados.
A fin de procesar a la mayor velocidad posible la informacion se le ha pedido elaborar un
programa en C++ que permita procesar la encuesta. Si se sabe que de la encuesta
interesan los siguientes datos.
Encuesta:
- DNI encuestado
- Leche preferida tipo: [1, 2, 3, 4]
El programa debe realizar los siguientes:
- Generar los datos aleatoriamente para:
- DNI (numero de 4 digitos).
- Leche preferida (entre 1 y 4).
- Mostrar para cada encuetando su leche preferida
DNI Leche
- Dado el DNI, eliminar el encuestado y la leche de su preferencia.
- Mostrar el nuevo arreglo
En la construccion de su programa debera:
- Implementar un menu con tres opciones: Generar, Mostrar, Eliminar.
*/

#include <iostream>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()
#include <vector>
#include <algorithm>
using namespace std;

// Clase Encuesta
class Encuesta
{
private:
    int dni;
    int lechePreferida;

public:
    Encuesta(int dni, int lechePreferida)
    {
        this->dni = dni;
        this->lechePreferida = lechePreferida;
    }

    int getDni() { return dni; }
    int getLechePreferida() { return lechePreferida; }

    void mostrar()
    {
        cout << "DNI: " << dni << ", Leche Preferida: " << lechePreferida << endl;
    }
};

// Funcion para generar un numero aleatorio entre min y max
int generarNumeroAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Funcion para mostrar el menu
void mostrarMenu()
{
    cout << "\n****** MENU ******\n";
    cout << "1. Generar Encuestas\n";
    cout << "2. Mostrar Encuestas\n";
    cout << "3. Eliminar Encuesta por DNI\n";
    cout << "4. Salir\n";
}

// Generar encuestas aleatorias
void generarEncuestas(vector<Encuesta>& encuestas)
{
    int cantidad;
    cout << "Ingrese la cantidad de encuestas a generar: ";
    cin >> cantidad;
    encuestas.clear(); // Limpiar el vector antes de agregar nuevas encuestas

    for (int i = 0; i < cantidad; i++)
    {
        int dni = generarNumeroAleatorio(1000, 9999); // DNI aleatorio de 4 digitos
        int lechePreferida = generarNumeroAleatorio(1, 4); // Leche preferida entre 1 y 4
        encuestas.push_back(Encuesta(dni, lechePreferida));
    }

    cout << endl;
    cout << cantidad << " encuestas generadas.\n";
}

// Mostrar encuestas
void mostrarEncuestas(vector<Encuesta>& encuestas)
{
    cout << "\n****** ENCUESTAS ******\n";
    for (auto& encuesta : encuestas)
    {
        encuesta.mostrar();
    }
}

// Eliminar encuesta por DNI
void eliminarEncuesta(vector<Encuesta>& encuestas)
{
    int dni;
    cout << "Ingrese el DNI de la encuesta a eliminar: ";
    cin >> dni;

    // Usar remove_if para eliminar la encuesta con el DNI especificado
    // y luego borrar el elemento del vector
    auto it = remove_if(encuestas.begin(), encuestas.end(), [dni](Encuesta& encuesta)
    {
        return encuesta.getDni() == dni;
    });

    if (it != encuestas.end())
    {
        encuestas.erase(it, encuestas.end());
        cout << endl;
        cout << "Encuesta con DNI " << dni << " eliminada.\n";
    }
    else
    {
        cout << "No se encontro ninguna encuesta con DNI " << dni << ".\n";
    }
}

int main()
{
    srand(time(0)); // Inicializar la semilla para numeros aleatorios
    vector<Encuesta> encuestas;
    int opcion;

    do
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            generarEncuestas(encuestas);
            break;
        case 2:
            mostrarEncuestas(encuestas);
            break;
        case 3:
            eliminarEncuesta(encuestas);
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
        }
    }
    while (opcion != 4);

    return 0;
}
