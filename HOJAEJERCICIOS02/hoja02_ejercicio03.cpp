//
// Created by c0d3r on 12/04/2025.
//

/**
*Paco y Papo
Una tarde de verano Paco y Papo, dos estudiantes famosos de la universidad deciden crear
un programa para administrar sus contactos. La informacion que necesitan es el Nombre del
contacto, Telefono, Sexo, Facultad, Fechas de nacimiento y email, Red social(Facebook,
Google+, Twitter, WhatsApp)
Con esta informacion van a desarrollar una aplicacion y utilizara la tecnica de programacion
orientada a objetos (POO). El programa requiere tener lo siguiente:
a) Implementacion de una Clase para manejar la informacion de cada contacto
a. La clase debe tener atributos como:
b) Nombre de contacto
c) Telefono
d) Sexo
e) Facultad
f) Fecha de nacimiento
g) Email
h) Red Social
a. Los metodos que debe tener la clase quedaran bajo su criterio, dependiendo de la
necesidad del problema
i) Registro de Contactos
j)
Haciendo uso de arreglo dinamicos realice las implementaciones necesarias para almacenar
la informacion de “N” elementos
k) Modificar datos de un Contacto
l)
Uso de componente y validacion del objeto a modificar
m) Eliminar un contacto
n) Uso de componente y validacion del objeto a eliminar
o) Reporte de contactos que cumplen años en mayo
p) Reporte de contactos que son varones
q) Reporte de contactos que tienen red social Facebook y WhatsApp
*/

#include <iostream> // Para cout y cin
#include <string> // Para string
#include <vector> // Para vector
using namespace std;

class CONTACTO
{
private:
    string nombre; // Nombre del contacto
    string telefono; // Telefono del contacto
    char sexo; // Sexo del contacto (H/M)
    string facultad; // Facultad del contacto
    string fechaNacimiento; // Fecha de nacimiento del contacto
    string email; // Email del contacto
    string redSocial; // Red social del contacto

public:
    // Constructor por defecto
    CONTACTO()
    {
        nombre = "";
        telefono = "";
        sexo = ' ';
        facultad = "";
        fechaNacimiento = "";
        email = "";
        redSocial = "";
    }

    // Constructor con parametros
    CONTACTO(string n, string t, char s, string f, string fn, string e, string rs)
    {
        nombre = n;
        telefono = t;
        sexo = s;
        facultad = f;
        fechaNacimiento = fn;
        email = e;
        redSocial = rs;
    }

    // Metodos de acceso (getters y setters)
    string getNombre() { return nombre; }
    void setNombre(string n) { nombre = n; }

    string getTelefono() { return telefono; }
    void setTelefono(string t) { telefono = t; }

    char getSexo() { return sexo; }
    void setSexo(char s) { sexo = s; }

    string getFacultad() { return facultad; }
    void setFacultad(string f) { facultad = f; }

    string getFechaNacimiento() { return fechaNacimiento; }
    void setFechaNacimiento(string fn) { fechaNacimiento = fn; }

    string getEmail() { return email; }
    void setEmail(string e) { email = e; }

    string getRedSocial() { return redSocial; }
    void setRedSocial(string rs) { redSocial = rs; }

    // Metodo para mostrar informacion del contacto
    string toString()
    {
        return "Nombre: " + nombre +
            "\nTelefono: " + telefono +
            "\nSexo: " + sexo +
            "\nFacultad: " + facultad +
            "\nFecha de Nacimiento: " + fechaNacimiento +
            "\nEmail: " + email +
            "\nRed Social: " + redSocial;
    }

    // Metodo para validar el contacto
    bool validarContacto()
    {
        if (nombre.empty() || telefono.empty() || sexo == ' ' || facultad.empty() ||
            fechaNacimiento.empty() || email.empty() || redSocial.empty())
        {
            cout << "Datos invalidos para el contacto." << endl;
            return false; // Datos invalidos
        }
        return true; // Datos validos
    }
};

void mostrarMenu()
{
    cout << "\n****** MENU ******\n";
    cout << "1. Registrar contacto\n";
    cout << "2. Mostrar contactos\n";
    cout << "3. Modificar contacto\n";
    cout << "4. Eliminar contacto\n";
    cout << "5. Reporte de contactos que cumplen años en mayo\n";
    cout << "6. Reporte de contactos que son varones\n";
    cout << "7. Reporte de contactos con Facebook y WhatsApp\n";
    cout << "8. Salir\n";
}

void mostrarIndices(vector<CONTACTO>& contactos)
{
    // Mostrar indices y nombres de cada contacto
    cout << "\nIndices y contactos registrados:\n";
    for (int i = 0; i < contactos.size(); i++)
    {
        cout << i << " -> " << contactos[i].getNombre() << endl;
    }
}

void registrarContacto(vector<CONTACTO>& contactos)
{
    string nombre, telefono, facultad, fechaNacimiento, email, redSocial;
    char sexo;

    cout << "\nIngrese el nombre: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombre); // Permite ingresar nombres con espacios

    cout << "Ingrese el telefono: ";
    cin >> telefono;

    cout << "Ingrese el sexo (H/M): ";
    cin >> sexo;

    cout << "Ingrese la facultad: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, facultad); // Permite ingresar facultades con espacios

    cout << "Ingrese la fecha de nacimiento (DD/MM/AAAA): ";
    cin >> fechaNacimiento;

    cout << "Ingrese el email: ";
    cin >> email;

    cout << "Ingrese la red social (Facebook, Google+, Twitter, WhatsApp): ";
    cin >> redSocial;

    CONTACTO nuevoContacto(nombre, telefono, sexo, facultad, fechaNacimiento, email, redSocial);
    contactos.push_back(nuevoContacto); // Agregar el contacto al vector
}

void mostrarContactos(vector<CONTACTO>& contactos)
{
    cout << "\n****** CONTACTOS REGISTRADOS ******\n";
    for (auto& contacto : contactos)
    {
        cout << contacto.toString() << endl;
        cout << endl;
    }
}

void modificarContacto(vector<CONTACTO>& contactos)
{
    mostrarIndices(contactos); // Mostrar indices y nombres de cada contacto

    int index;
    cout << "Ingrese el indice del contacto a modificar (0 a " << contactos.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < contactos.size())
    {
        string nombre, telefono, facultad, fechaNacimiento, email, redSocial;
        char sexo;

        cout << "\nIngrese el nuevo nombre: ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, nombre); // Permite ingresar nombres con espacios

        cout << "Ingrese el nuevo telefono: ";
        cin >> telefono;

        cout << "Ingrese el nuevo sexo (H/M): ";
        cin >> sexo;

        cout << "Ingrese la nueva facultad: ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, facultad); // Permite ingresar facultades con espacios

        cout << "Ingrese la nueva fecha de nacimiento (DD/MM/AAAA): ";
        cin >> fechaNacimiento;

        cout << "Ingrese el nuevo email: ";
        cin >> email;

        cout << "Ingrese la nueva red social: ";
        cin >> redSocial;

        CONTACTO& contacto = contactos[index]; // Referencia al contacto a modificar
        contacto.setNombre(nombre);
        contacto.setTelefono(telefono);
        contacto.setSexo(sexo);
        contacto.setFacultad(facultad);
        contacto.setFechaNacimiento(fechaNacimiento);
        contacto.setEmail(email);
        contacto.setRedSocial(redSocial);

        if (contacto.validarContacto()) // Validar el contacto despues de modificarlo
        {
            cout << "\nContacto modificado:\n";
            cout << contacto.toString() << endl;
        }
        else
        {
            cout << "No se pudo modificar el contacto debido a datos invalidos." << endl;
        }
    }
    else
    {
        cout << "indice invalido." << endl;
    }
}

void eliminarContacto(vector<CONTACTO>& contactos)
{
    mostrarIndices(contactos); // Mostrar indices y nombres de cada contacto

    int index;
    cout << "Ingrese el indice del contacto a eliminar (0 a " << contactos.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < contactos.size())
    {
        contactos.erase(contactos.begin() + index); // Eliminar el contacto del vector
        cout << "Contacto eliminado correctamente.\n";
    }
    else
    {
        cout << "indice invalido." << endl;
    }
}

void reporteCumpleanosMayo(vector<CONTACTO>& contactos)
{
    cout << "\n****** CONTACTOS QUE CUMPLEN AÑOS EN MAYO ******\n";
    for (auto& contacto : contactos)
    {
        if (contacto.getFechaNacimiento().substr(3, 2) == "05") // Verificar si el mes es mayo
        {
            cout << contacto.toString() << endl;
            cout << endl;
        }
    }
}

void reporteVarones(vector<CONTACTO>& contactos)
{
    cout << "\n****** CONTACTOS VARONES ******\n";
    for (auto& contacto : contactos)
    {
        if (contacto.getSexo() == 'H') // Verificar si el sexo es masculino
        {
            cout << contacto.toString() << endl;
            cout << endl;
        }
    }
}

void reporteRedesSociales(vector<CONTACTO>& contactos)
{
    cout << "\n****** CONTACTOS CON FACEBOOK Y WHATSAPP ******\n";
    for (auto& contacto : contactos)
    {
        // Verificar si tiene Facebook o WhatsApp
        if (contacto.getRedSocial() == "Facebook" || contacto.getRedSocial() == "WhatsApp")
        {
            cout << contacto.toString() << endl;
            cout << endl;
        }
    }
}

int main()
{
    int opcion;
    vector<CONTACTO> contactos; // Vector para almacenar los contactos

    do
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarContacto(contactos);
            break;
        case 2:
            mostrarContactos(contactos);
            break;
        case 3:
            modificarContacto(contactos);
            break;
        case 4:
            eliminarContacto(contactos);
            break;
        case 5:
            reporteCumpleanosMayo(contactos);
            break;
        case 6:
            reporteVarones(contactos);
            break;
        case 7:
            reporteRedesSociales(contactos);
            break;
        case 8:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
    }
    while (opcion != 8);

    return 0;
}
