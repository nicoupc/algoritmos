### Cheatsheet: Guía Rápida para Usar Vectores en C++

Este cheatsheet es un sistema básico con funcionalidades comunes para practicar el uso de vectores en C++. Cada
funcionalidad incluye una breve explicación y un ejemplo.

---

#### **Menú Principal**

1. **Insertar elementos en un vector**
2. **Eliminar elementos por índice**
3. **Eliminar elementos por valor**
4. **Buscar elementos en un vector**
5. **Mostrar los elementos del vector**
6. **Ordenar el vector**
7. **Actualizar un valor en cierta posición**
8. **Saber el tamaño del vector**
9. **Validar que el vector no esté vacío**
10. **Usar bucles con vectores**
11. **Evitar errores comunes**
12. **Salir**

---

### **1. Insertar elementos en un vector**

Agrega un elemento al final del vector.

```cpp
#include <vector>
#include <iostream>
using namespace std;

void insertarElemento(vector<int>& vec, int valor) {
    vec.push_back(valor);
    cout << "Elemento " << valor << " insertado." << endl;
}
```

---

### **2. Eliminar elementos por índice**

Elimina un elemento en una posición específica.

```cpp
void eliminarPorIndice(vector<int>& vec, int indice) {
    if (indice >= 0 && indice < vec.size()) {
        vec.erase(vec.begin() + indice);
        cout << "Elemento en el índice " << indice << " eliminado." << endl;
    } else {
        cout << "Índice inválido." << endl;
    }
}
```

---

### **3. Eliminar elementos por valor**

Busca y elimina el primer elemento que coincida con el valor dado.

```cpp
void eliminarPorValor(vector<int>& vec, int valor) {
    auto it = find(vec.begin(), vec.end(), valor);
    if (it != vec.end()) {
        vec.erase(it);
        cout << "Elemento " << valor << " eliminado." << endl;
    } else {
        cout << "Valor no encontrado." << endl;
    }
}
```

---

### **4. Buscar elementos en un vector**

Devuelve el índice del primer elemento que coincida con el valor dado.

```cpp
int buscarElemento(const vector<int>& vec, int valor) {
    auto it = find(vec.begin(), vec.end(), valor);
    if (it != vec.end()) {
        return distance(vec.begin(), it);
    }
    return -1; // No encontrado
}
```

---

### **5. Mostrar los elementos del vector**

Imprime todos los elementos del vector.

```cpp
void mostrarVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
```

---

### **6. Ordenar el vector**

Ordena los elementos del vector en orden ascendente.

```cpp
#include <algorithm>

void ordenarVector(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    cout << "Vector ordenado." << endl;
}
```

---

### **7. Actualizar un valor en cierta posición**

Cambia el valor de un elemento en una posición específica.

```cpp
void actualizarValor(vector<int>& vec, int indice, int nuevoValor) {
    if (indice >= 0 && indice < vec.size()) {
        vec[indice] = nuevoValor;
        cout << "Valor actualizado en el índice " << indice << "." << endl;
    } else {
        cout << "Índice inválido." << endl;
    }
}
```

---

### **8. Saber el tamaño del vector**

Muestra cuántos elementos tiene el vector.

```cpp
void mostrarTamano(const vector<int>& vec) {
    cout << "El vector tiene " << vec.size() << " elementos." << endl;
}
```

---

### **9. Validar que el vector no esté vacío**

Verifica si el vector tiene elementos antes de operar.

```cpp
bool estaVacio(const vector<int>& vec) {
    return vec.empty();
}
```

---

### **10. Usar bucles con vectores**

Ejemplo de bucles para recorrer un vector.

```cpp
void recorrerVector(const vector<int>& vec) {
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
```

---

### **11. Evitar errores comunes**

- **Usar `.at()` en lugar de `[]` para evitar accesos fuera de rango.**

```cpp
void accederElemento(const vector<int>& vec, int indice) {
    try {
        cout << "Elemento en el índice " << indice << ": " << vec.at(indice) << endl;
    } catch (out_of_range& e) {
        cout << "Error: Índice fuera de rango." << endl;
    }
}
```

- **Validar índices antes de usar `.erase()`.**

---

### **12. Salir**

Finaliza el programa.

```cpp
cout << "Saliendo del programa..." << endl;
```

---

### **Ejemplo de Uso Completo**

Este es un ejemplo de cómo implementar el menú principal.

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Para sort
using namespace std;

// Funciones aquí (copiar las anteriores)

int main() {
    vector<int> vec;
    int opcion;

    do {
        cout << "\nMenu:\n";
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
        cout << "11. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                cout << "Ingrese un valor: ";
                cin >> valor;
                insertarElemento(vec, valor);
                break;
            }
            case 2: {
                int indice;
                cout << "Ingrese el índice: ";
                cin >> indice;
                eliminarPorIndice(vec, indice);
                break;
            }
            case 3: {
                int valor;
                cout << "Ingrese el valor: ";
                cin >> valor;
                eliminarPorValor(vec, valor);
                break;
            }
            case 4: {
                int valor;
                cout << "Ingrese el valor a buscar: ";
                cin >> valor;
                int indice = buscarElemento(vec, valor);
                if (indice != -1) {
                    cout << "Valor encontrado en el índice " << indice << endl;
                } else {
                    cout << "Valor no encontrado." << endl;
                }
                break;
            }
            case 5:
                mostrarVector(vec);
                break;
            case 6:
                ordenarVector(vec);
                break;
            case 7: {
                int indice, nuevoValor;
                cout << "Ingrese el índice: ";
                cin >> indice;
                cout << "Ingrese el nuevo valor: ";
                cin >> nuevoValor;
                actualizarValor(vec, indice, nuevoValor);
                break;
            }
            case 8:
                mostrarTamano(vec);
                break;
            case 9:
                if (estaVacio(vec)) {
                    cout << "El vector está vacío." << endl;
                } else {
                    cout << "El vector no está vacío." << endl;
                }
                break;
            case 10:
                recorrerVector(vec);
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