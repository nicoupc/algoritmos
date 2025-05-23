### Explicación del diseño

1. **Clase `ArregloManager`**:
    - Representa el manejo del arreglo.
    - Contiene un arreglo estático privado y métodos públicos para realizar las operaciones.
    - Métodos:
        - `insertarDato`: Agrega un dato al final del arreglo.
        - `eliminarPorIndice`: Elimina un dato en una posición específica.
        - `eliminarPorValor`: Busca y elimina un dato por su valor.
        - `buscarDato`: Devuelve el índice de un dato.
        - `insertarEnPosicion`: Inserta un dato en una posición específica.
        - `actualizarDato`: Modifica un dato en una posición específica.
        - `mostrarArreglo`: Imprime el contenido del arreglo.
        - `ordenarArreglo`: Ordena el arreglo.
        - `mostrarTamano`: Muestra la cantidad de datos cargados.
        - `estaVacio` y `estaLleno`: Verifican si el arreglo está vacío o lleno.

2. **`main()`**:
    - Muestra un menú para interactuar con las funcionalidades de la clase.

---

### Código

```cpp
#include <iostream>
#include <algorithm> // Para std::sort
using namespace std;

// Clase que maneja un arreglo simple
class ArregloManager {
private:
    int arreglo[100]; // Arreglo estático con capacidad de 100 elementos
    int tamano;       // Cantidad actual de elementos en el arreglo

public:
    // Constructor por defecto
    ArregloManager() : tamano(0) {}

    // Insertar un dato al final del arreglo
    void insertarDato(int dato) {
        if (estaLleno()) {
            cout << "El arreglo está lleno. No se puede insertar más datos." << endl;
            return;
        }
        arreglo[tamano] = dato;
        tamano++;
        cout << "Dato " << dato << " insertado." << endl;
    }

    // Eliminar un dato por índice
    void eliminarPorIndice(int indice) {
        if (indice < 0 || indice >= tamano) {
            cout << "Índice inválido." << endl;
            return;
        }
        for (int i = indice; i < tamano - 1; i++) {
            arreglo[i] = arreglo[i + 1];
        }
        tamano--;
        cout << "Dato en el índice " << indice << " eliminado." << endl;
    }

    // Eliminar un dato por valor
    void eliminarPorValor(int valor) {
        for (int i = 0; i < tamano; i++) {
            if (arreglo[i] == valor) {
                eliminarPorIndice(i);
                cout << "Dato " << valor << " eliminado." << endl;
                return;
            }
        }
        cout << "Dato " << valor << " no encontrado." << endl;
    }

    // Buscar un dato y devolver su índice
    int buscarDato(int valor) {
        for (int i = 0; i < tamano; i++) {
            if (arreglo[i] == valor) {
                return i;
            }
        }
        return -1; // No encontrado
    }

    // Insertar un dato en una posición específica
    void insertarEnPosicion(int dato, int posicion) {
        if (estaLleno()) {
            cout << "El arreglo está lleno. No se puede insertar más datos." << endl;
            return;
        }
        if (posicion < 0 || posicion > tamano) {
            cout << "Posición inválida." << endl;
            return;
        }
        for (int i = tamano; i > posicion; i--) {
            arreglo[i] = arreglo[i - 1];
        }
        arreglo[posicion] = dato;
        tamano++;
        cout << "Dato " << dato << " insertado en la posición " << posicion << "." << endl;
    }

    // Actualizar un dato en una posición específica
    void actualizarDato(int posicion, int nuevoValor) {
        if (posicion < 0 || posicion >= tamano) {
            cout << "Posición inválida." << endl;
            return;
        }
        arreglo[posicion] = nuevoValor;
        cout << "Dato en la posición " << posicion << " actualizado a " << nuevoValor << "." << endl;
    }

    // Mostrar el contenido del arreglo
    void mostrarArreglo() {
        if (estaVacio()) {
            cout << "El arreglo está vacío." << endl;
            return;
        }
        cout << "Contenido del arreglo: ";
        for (int i = 0; i < tamano; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }

    // Ordenar el arreglo en orden ascendente
    void ordenarArreglo() {
        sort(arreglo, arreglo + tamano);
        cout << "Arreglo ordenado." << endl;
    }

    // Mostrar el tamaño actual del arreglo
    void mostrarTamano() {
        cout << "El arreglo tiene " << tamano << " elementos." << endl;
    }

    // Verificar si el arreglo está vacío
    bool estaVacio() {
        return tamano == 0;
    }

    // Verificar si el arreglo está lleno
    bool estaLleno() {
        return tamano == 100;
    }
};

// Función principal con menú
int main() {
    ArregloManager manager;
    int opcion;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Insertar dato\n";
        cout << "2. Eliminar por índice\n";
        cout << "3. Eliminar por valor\n";
        cout << "4. Buscar dato\n";
        cout << "5. Insertar en una posición\n";
        cout << "6. Actualizar dato\n";
        cout << "7. Mostrar arreglo\n";
        cout << "8. Ordenar arreglo\n";
        cout << "9. Mostrar tamaño\n";
        cout << "10. Validar si está vacío\n";
        cout << "11. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int dato;
                cout << "Ingrese el dato a insertar: ";
                cin >> dato;
                manager.insertarDato(dato);
                break;
            }
            case 2: {
                int indice;
                cout << "Ingrese el índice a eliminar: ";
                cin >> indice;
                manager.eliminarPorIndice(indice);
                break;
            }
            case 3: {
                int valor;
                cout << "Ingrese el valor a eliminar: ";
                cin >> valor;
                manager.eliminarPorValor(valor);
                break;
            }
            case 4: {
                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                int indice = manager.buscarDato(valor);
                if (indice != -1) {
                    cout << "Dato encontrado en el índice " << indice << "." << endl;
                } else {
                    cout << "Dato no encontrado." << endl;
                }
                break;
            }
            case 5: {
                int dato, posicion;
                cout << "Ingrese el dato a insertar: ";
                cin >> dato;
                cout << "Ingrese la posición: ";
                cin >> posicion;
                manager.insertarEnPosicion(dato, posicion);
                break;
            }
            case 6: {
                int posicion, nuevoValor;
                cout << "Ingrese la posición a actualizar: ";
                cin >> posicion;
                cout << "Ingrese el nuevo valor: ";
                cin >> nuevoValor;
                manager.actualizarDato(posicion, nuevoValor);
                break;
            }
            case 7:
                manager.mostrarArreglo();
                break;
            case 8:
                manager.ordenarArreglo();
                break;
            case 9:
                manager.mostrarTamano();
                break;
            case 10:
                if (manager.estaVacio()) {
                    cout << "El arreglo está vacío." << endl;
                } else {
                    cout << "El arreglo no está vacío." << endl;
                }
                break;
            case 11:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 11);

    return 0;
}
```