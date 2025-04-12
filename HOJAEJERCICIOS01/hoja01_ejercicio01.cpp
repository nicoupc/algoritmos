#include <iostream> // Para cout y cin
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()
#include <string> // Para string
#include <cctype> // Para isupper(), islower() y isdigit()
using namespace std;

/**
* Elabora una clase CONTRASEÑA con las siguientes condiciones:
Atributos longitud y contraseña . Por defecto, longitud será de 8.
Los constructores serán los siguientes:
Un constructor por defecto.
Un constructor con la longitud que se pasará como parámetro. Generará una contraseña aleatoria
con esa longitud.
Los métodos son:
función esSeguro(): devuelve un booleano si es fuerte o no, para que sea fuerte debe tener mas de
2 mayúsculas, mas de 1 minúscula y mas de 5 números.
función generarContrasena(): genera la contrasena del objeto con la longitud que tenga.
Metodo get para contraseña y longitud.
Metodo set para longitud.
El programa debe hacer lo siguiente
Crea un arreglo dinámico de Contraseñas con un tamaño aleatorio entre 5 y 10
En otro arreglo booleano guardar la información de si la contraseñas del arreglo deContraseñas es
o no fuerte
Muestra en pantalla la contraseña y al costado mostrar V si es fuerte, de lo contrario F
Ejemplo
contrasena1 : Fuerte: V o F (V de verdad o F de falso)
contrasena2 : Fuerte: V o F (V de verdad o F de falso)
contrasena1 : Fuerte: V o F (V de verdad o F de falso)
contrasena2 : Fuerte: V o F (V de verdad o F de falso)
 */

class CONTRASENA
{
private:
    int longitud;
    string contrasena;

public:
    // Constructor por defecto
    CONTRASENA()
    {
        longitud = 8;
    }

    // Constructor con parámetro
    CONTRASENA(int l)
    {
        longitud = l;
        generarContrasena(); // Generamos la contraseña al crear el objeto
    }

    // Métodos get
    int getLongitud()
    {
        return longitud;
    }

    string getContrasena()
    {
        return contrasena;
    }

    // Metodo set para longitud
    void setLongitud(int l)
    {
        longitud = l;
    }

    void generarContrasena()
    {
        string posibles = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        contrasena = "";

        for (int i = 0; i < longitud; i++)
        {
            int index = rand() % posibles.length();
            contrasena += posibles[index];
        }
    }

    bool esSeguro()
    {
        int mayus = 0;
        int minus = 0;
        int numeros = 0;

        for (int i = 0; i < contrasena.length(); i++)
        {
            char c = contrasena[i];

            if (isupper(c)) { mayus++; }
            else if (islower(c)) { minus++; }
            else if (isdigit(c)) { numeros++; }
        }

        // Verificamos si tiene al menos 2 mayúsculas, 1 minúscula y 5 números
        if (mayus > 2 && minus > 1 && numeros > 5)
        {
            return true; // La contraseña es segura
        }
        else
        {
            return false; // La contraseña no es segura
        }
    }
};

int main()
{
    srand(time(0)); // Inicializamos los números aleatorios

    int tamanio = rand() % (10 - 5 + 1) + 5; // Generamos un tamaño aleatorio entre 5 y 10

    CONTRASENA contrasenas[tamanio]; // Creamos un arreglo de contraseñas

    bool seguridad[tamanio]; // Creamos un arreglo para saber si son seguras

    // Generamos las contraseñas
    for (int i = 0; i < tamanio; i++)
    {
        int longitudAleatoria = rand() % (20 - 8 + 1) + 8; // Generamos una longitud aleatoria entre 8 y 20
        contrasenas[i].setLongitud(longitudAleatoria); // Establecemos la longitud
        contrasenas[i].generarContrasena(); // Generamos la contraseña
        seguridad[i] = contrasenas[i].esSeguro(); // Verificamos si es segura
    }

    // Mostramos las contraseñas y su seguridad
    cout << "Contrasenas generadas:\n";
    for (int i = 0; i < tamanio; i++)
    {
        cout << "Contrasena " << i + 1 << ": " << contrasenas[i].getContrasena() << " - Fuerte: " << (
            seguridad[i] ? "V" : "F") << endl;
    }

    return 0;
}
