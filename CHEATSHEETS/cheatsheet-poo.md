# Cheatsheet: Principios de Programación Orientada a Objetos (POO) y Relaciones entre Clases en C++

Este cheatsheet te ayudará a repasar los conceptos clave de la Programación Orientada a Objetos (POO) y las relaciones entre clases. Incluye explicaciones sencillas y ejemplos básicos en C++.

---

## **1. Principios de la POO**

### **1.1 Encapsulamiento**
- **Definición**: Esconder los datos internos de una clase y permitir el acceso solo a través de métodos públicos.
- **Ejemplo**: Piensa en una caja fuerte. Solo puedes acceder a su contenido con la llave correcta (métodos públicos).

```cpp
#include <iostream>
using namespace std;

class Persona {
private:
    string nombre; // Dato privado

public:
    void setNombre(string n) { // Método público para modificar el dato
        nombre = n;
    }

    string getNombre() { // Método público para acceder al dato
        return nombre;
    }
};

int main() {
    Persona p;
    p.setNombre("Juan");
    cout << "Nombre: " << p.getNombre() << endl;
    return 0;
}
```

---

### **1.2 Abstracción**
- **Definición**: Mostrar solo los detalles esenciales y ocultar la complejidad.
- **Ejemplo**: Como usar un control remoto. No necesitas saber cómo funciona internamente, solo qué botones presionar.

```cpp
#include <iostream>
using namespace std;

class Figura {
public:
    virtual void dibujar() = 0; // Método virtual puro (abstracción)
};

class Circulo : public Figura {
public:
    void dibujar() override {
        cout << "Dibujando un círculo." << endl;
    }
};

int main() {
    Circulo c;
    c.dibujar();
    return 0;
}
```

---

### **1.3 Herencia**
- **Definición**: Permitir que una clase (hija) herede atributos y métodos de otra clase (padre).
- **Ejemplo**: Un perro hereda características de un animal.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void comer() {
        cout << "El animal está comiendo." << endl;
    }
};

class Perro : public Animal {
public:
    void ladrar() {
        cout << "El perro está ladrando." << endl;
    }
};

int main() {
    Perro p;
    p.comer(); // Método heredado
    p.ladrar();
    return 0;
}
```

---

### **1.4 Polimorfismo**
- **Definición**: Permitir que un mismo método tenga diferentes comportamientos según el objeto.
- **Ejemplo**: Un animal puede hacer diferentes sonidos dependiendo de su tipo.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido." << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro ladra." << endl;
    }
};

int main() {
    Animal* a = new Perro();
    a->hacerSonido(); // Llama al método de Perro
    delete a;
    return 0;
}
```

---

## **2. Relaciones entre Clases**

### **2.1 Asociación**
- **Definición**: Una clase usa otra clase, pero no depende de ella.
- **Ejemplo**: Un profesor enseña a un estudiante.

```cpp
#include <iostream>
using namespace std;

class Estudiante {
public:
    void estudiar() {
        cout << "El estudiante está estudiando." << endl;
    }
};

class Profesor {
public:
    void ensenar(Estudiante& e) {
        cout << "El profesor está enseñando." << endl;
        e.estudiar();
    }
};

int main() {
    Estudiante e;
    Profesor p;
    p.ensenar(e);
    return 0;
}
```

---

### **2.2 Agregación**
- **Definición**: Una clase contiene otra clase, pero ambas pueden existir por separado.
- **Ejemplo**: Un equipo tiene jugadores.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Jugador {
public:
    string nombre;
    Jugador(string n) : nombre(n) {}
};

class Equipo {
private:
    vector<Jugador> jugadores;

public:
    void agregarJugador(Jugador j) {
        jugadores.push_back(j);
    }

    void mostrarJugadores() {
        for (auto& j : jugadores) {
            cout << "Jugador: " << j.nombre << endl;
        }
    }
};

int main() {
    Jugador j1("Carlos"), j2("Luis");
    Equipo equipo;
    equipo.agregarJugador(j1);
    equipo.agregarJugador(j2);
    equipo.mostrarJugadores();
    return 0;
}
```

---

### **2.3 Composición**
- **Definición**: Una clase contiene otra clase, pero si la clase contenedora se destruye, la contenida también.
- **Ejemplo**: Un coche tiene un motor.

```cpp
#include <iostream>
using namespace std;

class Motor {
public:
    void encender() {
        cout << "El motor está encendido." << endl;
    }
};

class Coche {
private:
    Motor motor; // Composición

public:
    void arrancar() {
        motor.encender();
        cout << "El coche está arrancando." << endl;
    }
};

int main() {
    Coche c;
    c.arrancar();
    return 0;
}
```

---

## **3. Tabla Comparativa: Asociación, Agregación y Composición**

| Relación       | Definición                                                                 | Ejemplo                  | Independencia |
|----------------|----------------------------------------------------------------------------|--------------------------|---------------|
| Asociación     | Una clase usa otra, pero no depende de ella.                              | Profesor y Estudiante    | Sí            |
| Agregación     | Una clase contiene otra, pero ambas pueden existir por separado.          | Equipo y Jugadores       | Sí            |
| Composición    | Una clase contiene otra, y si la contenedora se destruye, la contenida también. | Coche y Motor            | No            |

---

## **4. Consejos para Recordar**
1. **Encapsulamiento**: Piensa en una caja fuerte (datos privados, acceso controlado).
2. **Abstracción**: Muestra solo lo necesario, como un control remoto.
3. **Herencia**: Es como un hijo que hereda características de sus padres.
4. **Polimorfismo**: Un mismo botón puede hacer cosas diferentes según el contexto.

---
