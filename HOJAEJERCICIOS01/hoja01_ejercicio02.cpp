//
// Created by c0d3r on 12/04/2025.
//
#include <iostream> // Para cout y cin
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <string> // Para string
using namespace std;

/**
 *Elaborar una clase llamada Persona que tenga lo siguiente
Atributos: nombre, edad, DNI, sexo (H hombre, M mujer), peso y altura. No se debe acceder
directamente a ellos. Piensa que metodo de acceso es el más adecuado, Se puede agregar algún
atributo si considera necesario.
Todos los atributos, excepto el DNI, serán valores por defecto según su tipo (0 números, cadena
vacía para String, etc.).
Sexo sera hombre por defecto, usa un valor constante para ello.
Constructores:
Un constructor por defecto.
Un constructor con con parámetros ( nombre, edad y sexo) y el resto por defecto.
Un constructor con todos los atributos como parámetro.
Las operacions o métodos que se implementaran son:
calcular el índice de masa corporal - IMC() : calcula si la persona esta en su peso ideal (peso en
kg/(altura^2 en m)), si esta fórmula devuelve un valor menor que 20, la función devuelve un -1, si
devuelve un número entre 20 y 25 (incluido), significa que esta por debajo de su peso ideal la
función devuelve un 0 y si devuelve un valor mayor que 25 significa que tiene sobrepeso, la
función devuelve un 1.
Métodos
esMayorDeEdad(): indica si es mayor de edad, devuelve un booleano.
comprobarSexo(char sexo): comprueba que el sexo introducido es correcto. Si no es correcto, sera
H. No sera visible al exterior.
toString(): devuelve toda la información del objeto.
generaDNI(): genera un número aleatorio de 8 cifras.
Métodos de acceso para cada atributo, excepto el DNI.
El programa debe hacer lo siguiente
• Ingreso de datos del nombre, la edad, sexo, peso y altura.
• Crea 3 objetos de la clase anterior, el primer objeto obtendrá las anteriores variables
pedidas por teclado.
• El segundo objeto obtendrá todos los anteriores menos el peso y la altura y el último
por defecto, para este último utiliza los métodos set para darle a los atributos un
valor.
• Para cada objeto, deberá comprobar si esta en su peso ideal, tiene sobrepeso o por
debajo de su peso ideal con un mensaje.
• Indicar para cada objeto si es mayor de edad.
Por último, mostrar la información de cada objeto.
*/

class PERSONA
{
private:
    string nombre;
    int edad;
    string dni;
    char sexo;
    float peso;
    float altura;
    const char SEXO_POR_DEFECTO = 'H'; // Valor constante para el sexo hombre

    // Metodo privado para comprobar el sexo
    void comprobarSexo(char s)
    {
        if (s != 'H' && s != 'M')
        {
            sexo = SEXO_POR_DEFECTO; // Asigna el valor por defecto si el sexo no es correcto
        }
        else
        {
            sexo = s; // Asigna el sexo proporcionado
        }
    }

public:
    // Constructor por defecto
    PERSONA()
    {
        nombre = "";
        edad = 0;
        dni = generarDNI();
        peso = 0;
        altura = 0;
    }

    // Constructor con parámetros (nombre, edad y sexo)
    PERSONA(string n, int e, char s)
    {
        nombre = n;
        edad = e;
        dni = generarDNI();
        comprobarSexo(s); // Llama al metodo privado para comprobar el sexo
        peso = 0;
        altura = 0;
    }

    // Constructor con todos los atributos como parámetro
    PERSONA(string n, int e, char s, float p, float a)
    {
        nombre = n;
        edad = e;
        dni = generarDNI();
        comprobarSexo(s); // Llama al metodo privado para comprobar el sexo
        peso = p;
        altura = a;
    }

    // Métodos de acceso
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    char getSexo() { return sexo; }
    float getPeso() { return peso; }
    float getAltura() { return altura; }
    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setSexo(char s) { comprobarSexo(s); } // Llama al metodo privado para comprobar el sexo
    void setPeso(float p) { peso = p; }
    void setAltura(float a) { altura = a; }

    // Metodo para calcular el índice de masa corporal (IMC)
    int IMC()
    {
        float imc = peso / (altura * altura);
        if (imc < 20)
            return -1; // Por debajo de su peso ideal
        else if (imc >= 20 && imc <= 25)
            return 0; // En su peso ideal
        else
            return 1; // Sobrepeso
    }

    // Metodo para comprobar si es mayor de edad
    bool esMayorDeEdad()
    {
        return edad >= 18;
    }

    // Metodo para generar un DNI aleatorio
    string generarDNI()
    {
        string dniGenerado = "";
        for (int i = 0; i < 8; i++)
        {
            dniGenerado += to_string(rand() % 10); // Genera un dígito aleatorio entre 0 y 9
        }
        return dniGenerado;
    }

    // Metodo toString para mostrar la información del objeto
    string toString()
    {
        return "Nombre: " + nombre +
            "\nEdad: " + to_string(edad) +
            "\nDNI: " + dni +
            "\nSexo: " + sexo +
            "\nPeso: " + to_string(peso) +
            "\nAltura: " + to_string(altura);
    }
};

int main()
{
    srand(time(0)); // Inicializa la semilla para generar números aleatorios

    // Ingreso de datos del primer objeto
    string nombre;
    int edad;
    char sexo;
    float peso, altura;

    cout << "Ingrese el nombre: ";
    getline(cin, nombre); // Permite ingresar nombres con espacios
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese el sexo (H/M): ";
    cin >> sexo;
    cout << "Ingrese el peso (en kg ej. 70.5): ";
    cin >> peso;
    cout << "Ingrese la altura (en metros ej. 1.75): ";
    cin >> altura;

    PERSONA persona1(nombre, edad, sexo, peso, altura);

    // Crea el segundo objeto con los datos ingresados menos peso y altura
    PERSONA persona2(nombre, edad, sexo);

    // Crea el tercer objeto por defecto
    PERSONA persona3;

    // Asigna valores a los atributos del tercer objeto usando los métodos set
    persona3.setNombre("Juan");
    persona3.setEdad(25);
    persona3.setSexo('H');
    persona3.setPeso(70.0);
    persona3.setAltura(1.75);

    // Comprobación del IMC y si es mayor de edad para cada objeto
    PERSONA personas[3] = {persona1, persona2, persona3};

    for (int i = 0; i < 3; i++)
    {
        cout << "*** Persona " << i + 1 << " ***" << endl;

        int resultadoIMC = personas[i].IMC();
        if (resultadoIMC == -1)
            cout << "Estado: Por debajo de su peso ideal" << endl;
        else if (resultadoIMC == 0)
            cout << "Estado: En su peso ideal" << endl;
        else
            cout << "Estado: Sobrepeso" << endl;

        if (personas[i].esMayorDeEdad())
            cout << "Es mayor de edad" << endl;
        else
            cout << "No es mayor de edad" << endl;

        // Muestra la información de cada objeto
        cout << personas[i].toString() << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}
