### Organización de la clase

1. **Clase `VectorManager`**:
    - Representa el manejo del vector.
    - Contiene un vector privado y métodos públicos para realizar las operaciones.
    - Métodos:
        - `insertarElemento`: Agrega un elemento al vector.
        - `eliminarPorIndice`: Elimina un elemento en una posición específica.
        - `eliminarPorValor`: Busca y elimina un elemento por su valor.
        - `buscarElemento`: Devuelve el índice de un elemento.
        - `mostrarVector`: Imprime el contenido del vector.
        - `ordenarVector`: Ordena el vector.
        - `actualizarValor`: Modifica un valor en una posición específica.
        - `mostrarTamano`: Muestra el tamaño del vector.
        - `estaVacio`: Verifica si el vector está vacío.
        - `recorrerVector`: Recorre el vector con diferentes bucles.
        - `accederElemento`: Usa `.at()` para evitar errores de rango.

2. **`main()`**:
    - Muestra un menú para interactuar con las funcionalidades de la clase.

---

### Código

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Para sort
#include <stdexcept> // Para manejar excepciones con .at()
using namespace std;

// Clase que maneja un vector y sus operaciones
class VectorManager {
private:
    vector<int> vec; // Vector privado

public:
    // Agregar un elemento al vector
    void insertarElemento(int valor) {
        vec.push_back(valor);
        cout << "Elemento " << valor << " insertado." << endl;
    }

    // Eliminar un elemento por índice
    void eliminarPorIndice(int indice) {
        if (indice >= 0 && indice < vec.size()) {
            vec.erase(vec.begin() + indice);
            cout << "Elemento en el índice " << indice << " eliminado." << endl;
        } else {
            cout << "Índice inválido." << endl;
        }
    }

    // Eliminar un elemento por valor
    void eliminarPorValor(int valor) {
        auto it = find(vec.begin(), vec.end(), valor);
        if (it != vec.end()) {
            vec.erase(it);
            cout << "Elemento " << valor << " eliminado." << endl;
        } else {
            cout << "Valor no encontrado." << endl;
        }
    }

    // Buscar un elemento y devolver su índice
    int buscarElemento(int valor) {
        auto it = find(vec.begin(), vec.end(), valor);
        if (it != vec.end()) {
            return distance(vec.begin(), it);
        }
        return -1; // No encontrado
    }

    // Mostrar el contenido del vector
    void mostrarVector() {
        if (vec.empty()) {
            cout << "El vector está vacío." << endl;
        } else {
            cout << "Contenido del vector: ";
            for (int val : vec) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    // Ordenar el vector
    void ordenarVector() {
        sort(vec.begin(), vec.end());
        cout << "Vector ordenado." << endl;
    }

    // Actualizar un valor en una posición específica
    void actualizarValor(int indice, int nuevoValor) {
        if (indice >= 0 && indice < vec.size()) {
            vec[indice] = nuevoValor;
            cout << "Valor actualizado en el índice " << indice << "." << endl;
        } else {
            cout << "Índice inválido." << endl;
        }
    }

    // Mostrar el tamaño del vector
    void mostrarTamano() {
        cout << "El vector tiene " << vec.size() << " elementos." << endl;
    }

    // Verificar si el vector está vacío
    bool estaVacio() {
        return vec.empty();
    }

    // Recorrer el vector con diferentes bucles
    void recorrerVector() {
        cout << "Usando for clásico:" << endl;
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        cout << "Usando range-based for:" << endl;
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;

        cout << "Usando while:" << endl;
        size_t i = 0;
        while (i < vec.size()) {
            cout << vec[i] << " ";
            i++;
        }
        cout << endl;
    }

    // Acceder a un elemento usando .at() para evitar errores
    void accederElemento(int indice) {
        try {
            cout << "Elemento en el índice " << indice << ": " << vec.at(indice) << endl;
        } catch (out_of_range& e) {
            cout << "Error: Índice fuera de rango." << endl;
        }
    }
};

// Función principal con menú
int main() {
    VectorManager manager;
    int opcion;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Eliminar por índice\n";
        cout << "3. Eliminar por valor\n";
        cout << "4. Buscar elemento\n";
        cout << "5. Mostrar vector\n";
        cout << "6. Ordenar vector\n";
        cout << "7. Actualizar valor\n";
        cout << "8. Mostrar tamaño\n";
        cout << "9. Validar si está vacío\n";
        cout << "10. Recorrer vector\n";
        cout << "11. Acceder a un elemento\n";
        cout << "12. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                cout << "Ingrese un valor: ";
                cin >> valor;
                manager.insertarElemento(valor);
                break;
            }
            case 2: {
                int indice;
                cout << "Ingrese el índice: ";
                cin >> indice;
                manager.eliminarPorIndice(indice);
                break;
            }
            case 3: {
                int valor;
                cout << "Ingrese el valor: ";
                cin >> valor;
                manager.eliminarPorValor(valor);
                break;
            }
            case 4: {
                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                int indice = manager.buscarElemento(valor);
                if (indice != -1) {
                    cout << "Valor encontrado en el índice " << indice << endl;
                } else {
                    cout << "Valor no encontrado." << endl;
                }
                break;
            }
            case 5:
                manager.mostrarVector();
                break;
            case 6:
                manager.ordenarVector();
                break;
            case 7: {
                int indice, nuevoValor;
                cout << "Ingrese el índice: ";
                cin >> indice;
                cout << "Ingrese el nuevo valor: ";
                cin >> nuevoValor;
                manager.actualizarValor(indice, nuevoValor);
                break;
            }
            case 8:
                manager.mostrarTamano();
                break;
            case 9:
                if (manager.estaVacio()) {
                    cout << "El vector está vacío." << endl;
                } else {
                    cout << "El vector no está vacío." << endl;
                }
                break;
            case 10:
                manager.recorrerVector();
                break;
            case 11: {
                int indice;
                cout << "Ingrese el índice: ";
                cin >> indice;
                manager.accederElemento(indice);
                break;
            }
            case 12:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 12);

    return 0;
}
```