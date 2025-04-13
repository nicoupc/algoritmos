//
// Created by c0d3r on 12/04/2025.
//

/**
*Gaston y BitMan
Una tarde de fin de semana, Gaston, un estudiante de “Le Ciordon Bleu” se encuentra con su
gran amigo a quien llaman de cariño “BitMan” porque le gusta programacion de
computadoras. Juntos van a una cafeteria tradicional y se toman la tarde platicando de la
“Universidad de la Vida”.  Gaston le comenta a Bitman todo lo que ha aprendido y la
diversidad de comidas que ha logrado preparar. Bitman lo escucha atentamente y le promete
hacer un programa para que tenga registrado todos los platos que ha aprendido.
Bitman le dice que es un experto en desarrollar aplicaciones y aplicara la tecnica de
programacion orientada a objetos (POO). Entonces Bitman requiere que usted lo ayude a
desarrollar la aplicacion. Para ello se requiere lo siguiente:
a) Implementacion de una Clase para manejar la informacion de cada plato
a. La clase puede tener atributos como:
b) Nombre del plato ( se refiere al nombre del plato por ejemplo: crepe a la parisienne, tacu
tacu apocalipis, pollo con salsa maracuya, arepas rellenas, etc )
c) Plato frio o caliente ( por ejemplo 1: frio 2:Caliente)
d) Plato picante o no picante
e) Cantidad de calorias
f) Precio promedio
a. Los metodos que debe tener la clase quedaran bajo su criterio, dependiendo de la
necesidad del problema
g) Registro de Platos
h) Haciendo uso de arreglo dinamicos realice las implementaciones necesarias para
almacenar la informacion de “N” elementos
i) Modificar datos de un plato
j)
Uso de componente y validacion del objeto a modificar
k) Eliminar un plato
l)
Uso de componente y validacion del objeto a eliminar
m) Reporte de Platos Picantes
n) Mostrar los platos que son picantes
o) Reporte de Platos mas caros
p) Mostrar los platos que tengan un precio mayor a 100 soles
*/

#include <iostream> // Para cout y cin
#include <string> // Para string
#include <vector> // Para vector
using namespace std;

class PLATO
{
private:
    string nombre; // Nombre del plato
    bool frio; // Si es plato frio (true) o caliente (false)
    bool picante; // Si es picante (true) o no picante (false)
    int calorias; // Cantidad de calorias
    float precio; // Precio promedio

public:
    // Constructor por defecto
    PLATO()
    {
        nombre = "";
        frio = false;
        picante = false;
        calorias = 0;
        precio = 0.0;
    }

    // Constructor con parametros
    PLATO(string n, bool f, bool p, int c, float pr)
    {
        nombre = n;
        frio = f;
        picante = p;
        calorias = c;
        precio = pr;
    }

    // Metodos de acceso (getters y setters)
    string getNombre() { return nombre; }
    void setNombre(string n) { nombre = n; }

    bool esFrio() { return frio; }
    void setFrio(bool f) { frio = f; }

    bool esPicante() { return picante; }
    void setPicante(bool p) { picante = p; }

    int getCalorias() { return calorias; }
    void setCalorias(int c) { calorias = c; }

    float getPrecio() { return precio; }
    void setPrecio(float pr) { precio = pr; }

    // Metodo para mostrar informacion del plato
    string toString()
    {
        return "Nombre: " + nombre +
            "\nTipo: " + (frio ? "Frio" : "Caliente") +
            "\nPicante: " + (picante ? "Si" : "No") +
            "\nCalorias: " + to_string(calorias) +
            "\nPrecio: S/ " + to_string(precio);
    }

    bool validarPlato()
    {
        if (nombre.empty() || calorias <= 0 || precio <= 0.0)
        {
            cout << "Datos invalidos para el plato." << endl;
            return false; // Datos invalidos
        }
        return true; // Datos validos
    }
};

void mostrarMenu()
{
    cout << "\n****** MENU ******\n";
    cout << "1. Registrar Platos\n";
    cout << "2. Mostrar Platos\n";
    cout << "3. Modificar Platos\n";
    cout << "4. Eliminar Platos\n";
    cout << "5. Reporte de Platos Picantes\n";
    cout << "6. Reporte de Platos Caros\n";
    cout << "7. Salir\n";
}

void mostrarIndices(vector<PLATO>& platos)
{
    // Mostrar índices y nombres de cada plato
    cout << "\nIndices y platos registrados:\n";
    for (int i = 0; i < platos.size(); i++)
    {
        cout << i << " -> " << platos[i].getNombre() << endl;
    }
}

void registrarPlato(vector<PLATO>& platos)
{
    string nombre;
    bool frio, picante;
    int calorias;
    float precio;

    cout << "\nIngrese el nombre del plato: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombre); // Permite ingresar nombres con espacios

    cout << "Es plato frio? (1 para si, 0 para no): ";
    cin >> frio;

    cout << "Es picante? (1 para si, 0 para no): ";
    cin >> picante;

    cout << "Ingrese la cantidad de calorias: ";
    cin >> calorias;

    cout << "Ingrese el precio promedio: ";
    cin >> precio;

    PLATO nuevoPlato(nombre, frio, picante, calorias, precio); // Crear un nuevo objeto PLATO
    if (nuevoPlato.validarPlato()) // Validar el plato antes de agregarlo
    {
        platos.push_back(nuevoPlato); // Agregar el plato al vector
        cout << "\nPlato registrado:\n";
        cout << nuevoPlato.toString() << endl;
    }
    else
    {
        cout << "No se pudo registrar el plato debido a datos invalidos." << endl;
    }
}

void mostrarPlatos(vector<PLATO>& platos)
{
    cout << "\n****** PLATOS REGISTRADOS ******\n";
    for (auto& plato : platos) // Usar referencia para evitar copias innecesarias
    {
        cout << plato.toString() << endl;
        cout << endl;
    }
}

void modificarPlato(vector<PLATO>& platos)
{
    mostrarIndices(platos);

    int index;
    cout << "Ingrese el indice del plato a modificar (0 a " << platos.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < platos.size())
    {
        string nombre;
        bool frio, picante;
        int calorias;
        float precio;

        cout << "\nIngrese el nuevo nombre del plato: ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, nombre); // Permite ingresar nombres con espacios

        cout << "Es plato frio? (1 para si, 0 para no): ";
        cin >> frio;

        cout << "Es picante? (1 para si, 0 para no): ";
        cin >> picante;

        cout << "Ingrese la nueva cantidad de calorias: ";
        cin >> calorias;

        cout << "Ingrese el nuevo precio promedio: ";
        cin >> precio;

        PLATO& plato = platos[index]; // Referencia al plato a modificar
        plato.setNombre(nombre);
        plato.setFrio(frio);
        plato.setPicante(picante);
        plato.setCalorias(calorias);
        plato.setPrecio(precio);

        if (plato.validarPlato()) // Validar el plato despues de modificarlo
        {
            cout << "\nPlato modificado:\n";
            cout << plato.toString() << endl;
        }
        else
        {
            cout << "No se pudo modificar el plato debido a datos invalidos." << endl;
        }
    }
    else
    {
        cout << "indice invalido." << endl;
    }
}

void eliminarPlato(vector<PLATO>& platos)
{
    mostrarIndices(platos);

    int index;
    cout << "Ingrese el indice del plato a eliminar (0 a " << platos.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < platos.size())
    {
        platos.erase(platos.begin() + index); // Eliminar el plato del vector
        cout << "Plato eliminado correctamente.\n";
    }
    else
    {
        cout << "indice invalido." << endl;
    }
}

void reportePlatosPicantes(vector<PLATO>& platos)
{
    cout << "\n****** PLATOS PICANTES ******\n";
    for (auto& plato : platos)
    {
        if (plato.esPicante())
        {
            cout << plato.toString() << endl;
            cout << endl;
        }
    }
}

void reportePlatosCaros(vector<PLATO>& platos)
{
    cout << "\n****** PLATOS CAROS ******\n";
    for (auto& plato : platos)
    {
        if (plato.getPrecio() > 100.0)
        {
            cout << plato.toString() << endl;
            cout << endl;
        }
    }
}

int main()
{
    int opcion;

    vector<PLATO> platos; // Vector para almacenar los platos

    do
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarPlato(platos);
            break;
        case 2:
            mostrarPlatos(platos);
            break;
        case 3:
            modificarPlato(platos);
            break;
        case 4:
            eliminarPlato(platos);
            break;
        case 5:
            reportePlatosPicantes(platos);
            break;
        case 6:
            reportePlatosCaros(platos);
            break;
        case 7:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente.\n";
        }
    }
    while (opcion != 7); // Salir del programa si la opcion es 7
}
