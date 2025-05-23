### Cheatsheet: Guía Rápida para Resolver Ejercicios de Programación en C++

Este cheatsheet es un sistema básico con funcionalidades comunes que te ayudarán a practicar y resolver ejercicios de
programación. Cada funcionalidad incluye una breve explicación y un ejemplo.

---

#### **Menú Principal**

1. **Mostrar el arreglo**
2. **Insertar un valor en una posición específica**
3. **Eliminar un valor por índice**
4. **Eliminar un valor por coincidencia**
5. **Buscar un valor en el arreglo**
6. **Ordenar el arreglo (de menor a mayor)**
7. **Validar entradas del usuario**
8. **Salir**

---

### **1. Mostrar el arreglo**

Muestra todos los elementos del arreglo.

```cpp
void mostrarArreglo(const int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
```

---

### **2. Insertar un valor en una posición específica**

Permite insertar un valor en una posición dada, desplazando los elementos hacia la derecha.

```cpp
void insertarEnPosicion(int arr[], int &tam, int valor, int pos, int capacidad) {
    if (pos < 0 || pos > tam || tam >= capacidad) {
        cout << "Posición inválida o arreglo lleno." << endl;
        return;
    }
    for (int i = tam; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = valor;
    tam++;
}
```

---

### **3. Eliminar un valor por índice**

Elimina un valor en una posición específica, desplazando los elementos hacia la izquierda.

```cpp
void eliminarPorIndice(int arr[], int &tam, int indice) {
    if (indice < 0 || indice >= tam) {
        cout << "Índice inválido." << endl;
        return;
    }
    for (int i = indice; i < tam - 1; i++) {
        arr[i] = arr[i + 1];
    }
    tam--;
}
```

---

### **4. Eliminar un valor por coincidencia**

Busca un valor en el arreglo y lo elimina si lo encuentra.

```cpp
void eliminarPorValor(int arr[], int &tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == valor) {
            eliminarPorIndice(arr, tam, i);
            cout << "Valor eliminado." << endl;
            return;
        }
    }
    cout << "Valor no encontrado." << endl;
}
```

---

### **5. Buscar un valor en el arreglo**

Busca un valor y devuelve su índice si lo encuentra.

```cpp
int buscarValor(const int arr[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1; // No encontrado
}
```

---

### **6. Ordenar el arreglo (de menor a mayor)**

Ordena los elementos del arreglo usando el algoritmo de burbuja.

```cpp
void ordenarArreglo(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

---

### **7. Validar entradas del usuario**

Evita errores al ingresar datos no válidos.

```cpp
int leerEntero(const string &mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada inválida
            cout << "Entrada inválida. Intente de nuevo." << endl;
        } else {
            return valor;
        }
    }
}
```

---

### **8. Salir**

Finaliza el programa.

```cpp
cout << "Saliendo del programa..." << endl;
```

---

### **Ejemplo de Uso Completo**

Este es un ejemplo de cómo implementar el menú principal.

```cpp
#include <iostream>
#include <limits> // Para std::numeric_limits
using namespace std;

// Funciones aquí (copiar las anteriores)

int main() {
    const int CAPACIDAD = 100;
    int arreglo[CAPACIDAD];
    int tam = 0;
    int opcion;

    do {
        cout << "\nMenu:\n";
        cout << "1. Mostrar el arreglo\n";
        cout << "2. Insertar un valor\n";
        cout << "3. Eliminar por índice\n";
        cout << "4. Eliminar por valor\n";
        cout << "5. Buscar un valor\n";
        cout << "6. Ordenar el arreglo\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarArreglo(arreglo, tam);
                break;
            case 2: {
                int valor = leerEntero("Ingrese el valor: ");
                int pos = leerEntero("Ingrese la posición: ");
                insertarEnPosicion(arreglo, tam, valor, pos, CAPACIDAD);
                break;
            }
            case 3: {
                int indice = leerEntero("Ingrese el índice: ");
                eliminarPorIndice(arreglo, tam, indice);
                break;
            }
            case 4: {
                int valor = leerEntero("Ingrese el valor a eliminar: ");
                eliminarPorValor(arreglo, tam, valor);
                break;
            }
            case 5: {
                int valor = leerEntero("Ingrese el valor a buscar: ");
                int indice = buscarValor(arreglo, tam, valor);
                if (indice != -1) {
                    cout << "Valor encontrado en el índice " << indice << endl;
                } else {
                    cout << "Valor no encontrado." << endl;
                }
                break;
            }
            case 6:
                ordenarArreglo(arreglo, tam);
                cout << "Arreglo ordenado." << endl;
                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}
```
