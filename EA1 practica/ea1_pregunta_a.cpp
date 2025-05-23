/**
 *TRACKER ROBOT
Las recientes variantes del virus COVID 19 se describen a continuación con sus respectivas
características:
ALEMANIA (B.1.1.7).
- Parece transmitirse más fácilmente
- Mayor riesgo de muerte.
ISRAEL (B.1.351).
- Parece transmitirse más fácilmente.
- Repercusión con medicamentos monoclonales
- Disminuye la eficacia de los anticuerpos generados por una infección previa o por la vacuna contra la COVID-19.
CHINA (P.1).
- Repercusión con medicamentos monoclonales.
- Disminuye la eficacia de los anticuerpos generados por una infección previa o por la vacuna contra la COVID-19.
RUSIA (KIEV) (B.1.427).
- Parece transmitirse más fácilmente.
- Disminuye la eficacia de los anticuerpos generados por una infección previa o por la vacuna contra la COVID-19.
BRASIL (C37).
- Parece transmitirse más fácilmente.
El Departamento de Infectología de la UPC tiene un robot denominado
TRACKER_ROBOT que identifica las variantes del COVID-19. Para ello, le solicita a
usted que elabore un programa bajo el paradigma de POO, que simule el
funcionamiento del robot.

Funcionamiento. El robot funciona las 24 horas del día a través de un menú de opciones
y atiende a “N” solicitudes que serán registradas en un arreglo o vector o generarlas de
manera automática. El robot hace preguntas de las características la enfermedad para
identificar la variante. También tiene la opción de mostrar dos reportes: el total de casos
identificados por cada variante y la variante más influyente.
De acuerdo a los principios de la POO debe identificar la información relevante para
definir las clases, atributos, métodos y relaciones de herencia necesarios para que el
robot pueda identificar y funcionar de acuerdo a lo descrito en los párrafos anteriores.
Resuelva teniendo en cuenta la rúbrica de calificación

Puede tomar como referencia la siguiente secuencia de pantallas o proponga la que usted
considere conveniente. Los datos que se muestran entre signos de “< >” son valores que varían
de acuerdo a la variante identificada. Los colores no son obligatorios:

TRACKER ROBOT
MENU
[1] INGRESAR DATOS MANUAL
[2] GENERAR DATOS AUTOMÁTICOS
[3] REPORTE TOTAL
[4] VARIANTE MENOS INFLUYENTE
[5] SALIR
Para Identificar
Elija una opción del MENU ->

Si se elige las opciones [1] se muestra la siguiente pantalla
TRACKER ROBOT
Responda las siguientes preguntas
¿Se transmite con facilidad? [S]sí [N]no:
¿Repercusión con medicamentos monoclonales? [S]sí [N]no:
¿Disminuye la eficacia de los anticuerpos? [S]sí [N]no:
¿Mayor riesgo de muerte? [S]sí [N]no:
RESULTADO
Se ha identificado la variante: <nombre_variante>
Presione una tecla para volver al menú

Si se elige las opciones [2] , se deben generar “N” (10..20) registros aleatorios para cada una de
las respuestas de las preguntas realizadas para el Ingreso Manual opción [1]. Una vez generado
este proceso saldrá el siguiente mensaje:

Registro Automático de <N> registros terminados.
Presione una tecla para volver al menú

Si se elige las opciones [3], se muestra el siguiente reporte:
TRACKER ROBOT
REPORTE
ALEMANIA <P> casos
ISRAEL <Q> casos
CHINA <X> casos
RUSIA <Y> casos
BRASIL <Z> casos
Presione una tecla para volver al menú

Si se elige las opciones [4], se muestra el siguiente reporte:
La variante menos influyente es la que tiene menor cantidad de coincidencias en cualquiera
de las dos formas de ingreso o generación.
Registro Variante menos influyente:
La variante menos influyente es: <Variante>
Presione una tecla para volver al menú
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para rand() y srand()
#include <ctime>

using namespace std;

// Clase que representa una variante de COVID-19
class Variante
{
public:
    string nombre;
    int casos;

    Variante(string nombre) : nombre(nombre), casos(0)
    {
    }
};

// Clase que representa el robot TRACKER_ROBOT
class TrackerRobot
{
private:
    vector<Variante> variantes;

public:
    // Constructor: inicializa las variantes
    TrackerRobot()
    {
        variantes.push_back(Variante("ALEMANIA"));
        variantes.push_back(Variante("ISRAEL"));
        variantes.push_back(Variante("CHINA"));
        variantes.push_back(Variante("RUSIA"));
        variantes.push_back(Variante("BRASIL"));
    }

    // Menú principal
    void mostrarMenu()
    {
        int opcion;
        do
        {
            cout << "TRACKER ROBOT\n";
            cout << "MENU\n";
            cout << "[1] INGRESAR DATOS MANUAL\n";
            cout << "[2] GENERAR DATOS AUTOMATICOS\n";
            cout << "[3] REPORTE TOTAL\n";
            cout << "[4] VARIANTE MENOS INFLUYENTE\n";
            cout << "[5] SALIR\n";
            cout << "Elija una opcion del MENU -> ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                ingresarDatosManual();
                break;
            case 2:
                generarDatosAutomaticos();
                break;
            case 3:
                mostrarReporteTotal();
                break;
            case 4:
                mostrarVarianteMenosInfluyente();
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
            }
        }
        while (opcion != 5);
    }

    // Opción 1: Ingresar datos manualmente
    void ingresarDatosManual()
    {
        char transmiteFacil, repercusionMedicamentos, disminuyeAnticuerpos, mayorRiesgoMuerte;
        cout << "TRACKER ROBOT\n";
        cout << "Responda las siguientes preguntas\n";
        cout << "Se transmite con facilidad? [S]si [N]no: ";
        cin >> transmiteFacil;
        cout << "Repercusion con medicamentos monoclonales? [S]si [N]no: ";
        cin >> repercusionMedicamentos;
        cout << "Disminuye la eficacia de los anticuerpos? [S]si [N]no: ";
        cin >> disminuyeAnticuerpos;
        cout << "Mayor riesgo de muerte? [S]si [N]no: ";
        cin >> mayorRiesgoMuerte;

        string varianteIdentificada = identificarVariante(transmiteFacil, repercusionMedicamentos, disminuyeAnticuerpos,
                                                          mayorRiesgoMuerte);
        cout << "RESULTADO\n";
        cout << "Se ha identificado la variante: " << varianteIdentificada << "\n";

        // Incrementar el contador de casos de la variante identificada
        for (auto& variante : variantes)
        {
            if (variante.nombre == varianteIdentificada)
            {
                variante.casos++;
                break;
            }
        }

        // Pausa para volver al menú
        cout << "Presione una tecla para volver al menu...\n";
        system("pause");
    }

    // Opción 2: Generar datos automáticamente
    void generarDatosAutomaticos()
    {
        srand(time(0));
        int n = rand() % 11 + 10; // Generar entre 10 y 20 registros
        for (int i = 0; i < n; i++)
        {
            char transmiteFacil = rand() % 2 == 0 ? 'S' : 'N';
            char repercusionMedicamentos = rand() % 2 == 0 ? 'S' : 'N';
            char disminuyeAnticuerpos = rand() % 2 == 0 ? 'S' : 'N';
            char mayorRiesgoMuerte = rand() % 2 == 0 ? 'S' : 'N';

            string varianteIdentificada = identificarVariante(transmiteFacil, repercusionMedicamentos,
                                                              disminuyeAnticuerpos, mayorRiesgoMuerte);

            // Incrementar el contador de casos de la variante identificada
            for (auto& variante : variantes)
            {
                if (variante.nombre == varianteIdentificada)
                {
                    variante.casos++;
                    break;
                }
            }
        }
        cout << "Registro Automatico de " << n << " registros terminados.\n";
    }

    // Opción 3: Mostrar reporte total
    void mostrarReporteTotal()
    {
        cout << "TRACKER ROBOT\n";
        cout << "REPORTE\n";
        for (const auto& variante : variantes)
        {
            cout << variante.nombre << ": " << variante.casos << " casos\n";
        }
    }

    // Opción 4: Mostrar variante menos influyente
    void mostrarVarianteMenosInfluyente()
    {
        const Variante* menosInfluyente = &variantes[0];
        for (const auto& variante : variantes)
        {
            if (variante.casos < menosInfluyente->casos)
            {
                menosInfluyente = &variante;
            }
        }
        cout << "La variante menos influyente es: " << menosInfluyente->nombre << "\n";
    }

    // Identificar variante según las respuestas
    string identificarVariante(char transmiteFacil, char repercusionMedicamentos, char disminuyeAnticuerpos,
                               char mayorRiesgoMuerte)
    {
        if (transmiteFacil == 'S' && mayorRiesgoMuerte == 'S') return "ALEMANIA";
        if (transmiteFacil == 'S' && repercusionMedicamentos == 'S' && disminuyeAnticuerpos == 'S') return "ISRAEL";
        if (repercusionMedicamentos == 'S' && disminuyeAnticuerpos == 'S') return "CHINA";
        if (transmiteFacil == 'S' && disminuyeAnticuerpos == 'S') return "RUSIA";
        if (transmiteFacil == 'S') return "BRASIL";
        return "DESCONOCIDA";
    }
};

// Función principal
int main()
{
    TrackerRobot robot;
    robot.mostrarMenu();
    return 0;
}
