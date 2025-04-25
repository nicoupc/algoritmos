# Relaciones en Programación Orientada a Objetos en C++

Este documento muestra cómo implementar diferentes tipos de relaciones en programación orientada a objetos (POO)
utilizando archivos separados `.h`, `.cpp` y `main.cpp`.

---

## 1. Asociación

**Descripción:** Un estudiante pertenece a un aula.

**Estructura de Archivos:**

- `Aula.h`
- `Estudiante.h`
- `main.cpp`

### Aula.h

```cpp
#ifndef AULA_H
#define AULA_H

#include <string>

class Aula {
private:
    std::string nombre;
public:
    Aula(std::string n);
    std::string getNombre() const;
};

#endif
```

### Estudiante.h

```cpp
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Aula.h"
#include <string>

class Estudiante {
private:
    std::string nombre;
    Aula* aula;
public:
    Estudiante(std::string n, Aula* a);
    void mostrarAula();
};

#endif
```

### main.cpp

```cpp
#include "Estudiante.h"

#include <iostream>
using namespace std;

Aula::Aula(string n) : nombre(n) {}
string Aula::getNombre() const { return nombre; }

Estudiante::Estudiante(string n, Aula* a) : nombre(n), aula(a) {}
void Estudiante::mostrarAula() {
    cout << nombre << " pertenece al aula: " << aula->getNombre() << endl;
}

int main() {
    Aula aula("Matemáticas");
    Estudiante est("Carlos", &aula);
    est.mostrarAula();
    return 0;
}
```

---

## 2. Agregación

**Descripción:** Una jaula puede contener varios animales, pero los animales pueden existir independientemente.

**Archivos:**

- `Animal.h`
- `Jaula.h`
- `main.cpp`

### Animal.h

```cpp
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
private:
    std::string nombre;
public:
    Animal(std::string n);
    std::string getNombre() const;
};

#endif
```

### Jaula.h

```cpp
#ifndef JAULA_H
#define JAULA_H

#include "Animal.h"
#include <vector>

class Jaula {
private:
    std::vector<Animal*> animales;
public:
    void agregarAnimal(Animal* a);
    void mostrarAnimales() const;
};

#endif
```

### main.cpp

```cpp
#include "Animal.h"
#include "Jaula.h"

#include <iostream>
using namespace std;

Animal::Animal(string n) : nombre(n) {}
string Animal::getNombre() const { return nombre; }

void Jaula::agregarAnimal(Animal* a) {
    animales.push_back(a);
}

void Jaula::mostrarAnimales() const {
    for (const auto& a : animales) {
        cout << "Animal: " << a->getNombre() << endl;
    }
}

int main() {
    Animal a1("León"), a2("Tigre");
    Jaula j;
    j.agregarAnimal(&a1);
    j.agregarAnimal(&a2);
    j.mostrarAnimales();
    return 0;
}
```

---

## 3. Composición

**Descripción:** Un automóvil tiene un motor que no puede existir por separado.

**Archivos:**

- `Motor.h`
- `Automovil.h`
- `main.cpp`

### Motor.h

```cpp
#ifndef MOTOR_H
#define MOTOR_H

#include <string>

class Motor {
private:
    std::string tipo;
public:
    Motor(std::string t);
    std::string getTipo() const;
};

#endif
```

### Automovil.h

```cpp
#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "Motor.h"

class Automovil {
private:
    std::string marca;
    Motor motor;
public:
    Automovil(std::string m, std::string tipoMotor);
    void mostrar() const;
};

#endif
```

### main.cpp

```cpp
#include "Motor.h"
#include "Automovil.h"

#include <iostream>
using namespace std;

Motor::Motor(string t) : tipo(t) {}
string Motor::getTipo() const { return tipo; }

Automovil::Automovil(string m, string tipoMotor) : marca(m), motor(tipoMotor) {}
void Automovil::mostrar() const {
    cout << "Automóvil marca: " << marca << ", Motor: " << motor.getTipo() << endl;
}

int main() {
    Automovil auto1("Toyota", "V8");
    auto1.mostrar();
    return 0;
}
```

---

## 4. Herencia

**Descripción:** Clase base Animal, con Perro y Gato como clases derivadas.

**Archivos:**

- `Animal.h`
- `Perro.h`
- `Gato.h`
- `main.cpp`

### Animal.h

```cpp
#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string nombre;
public:
    Animal(std::string n);
    virtual void emitirSonido() const = 0;
};

#endif
```

### Perro.h

```cpp
#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal {
public:
    Perro(std::string n);
    void emitirSonido() const override;
};

#endif
```

### Gato.h

```cpp
#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal {
public:
    Gato(std::string n);
    void emitirSonido() const override;
};

#endif
```

### main.cpp

```cpp
#include "Perro.h"
#include "Gato.h"

#include <iostream>
using namespace std;

Animal::Animal(string n) : nombre(n) {}

Perro::Perro(string n) : Animal(n) {}
void Perro::emitirSonido() const { cout << nombre << " dice: Guau!" << endl; }

Gato::Gato(string n) : Animal(n) {}
void Gato::emitirSonido() const { cout << nombre << " dice: Miau!" << endl; }

int main() {
    Animal* a1 = new Perro("Fido");
    Animal* a2 = new Gato("Michi");
    a1->emitirSonido();
    a2->emitirSonido();
    delete a1;
    delete a2;
    return 0;
}
```

---

## 5. Dependencia

**Descripción:** Un pasajero depende de un taxi para viajar.

**Archivos:**

- `Taxi.h`
- `Pasajero.h`
- `main.cpp`

### Taxi.h

```cpp
#ifndef TAXI_H
#define TAXI_H

#include <string>

class Taxi {
private:
    std::string placa;
public:
    Taxi(std::string p);
    std::string getPlaca() const;
};

#endif
```

### Pasajero.h

```cpp
#ifndef PASAJERO_H
#define PASAJERO_H

#include "Taxi.h"
#include <string>

class Pasajero {
private:
    std::string nombre;
public:
    Pasajero(std::string n);
    void viajarEnTaxi(const Taxi& t);
};

#endif
```

### main.cpp

```cpp
#include "Taxi.h"
#include "Pasajero.h"

#include <iostream>
using namespace std;

Taxi::Taxi(string p) : placa(p) {}
string Taxi::getPlaca() const { return placa; }

Pasajero::Pasajero(string n) : nombre(n) {}
void Pasajero::viajarEnTaxi(const Taxi& t) {
    cout << nombre << " viaja en el taxi con placa: " << t.getPlaca() << endl;
}

int main() {
    Taxi t("ABC-123");
    Pasajero p("Juan");
    p.viajarEnTaxi(t);
    return 0;
}
```