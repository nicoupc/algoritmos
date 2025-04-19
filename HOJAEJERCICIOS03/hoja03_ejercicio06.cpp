//
// Created by c0d3r on 17/04/2025.
//

/**
*Graficos y Recorridos
Se requiere que realice un programa orientado a objetos donde podra seleccionar: dibujar un
triangulo equilatero o un triangulo rectangulo en sentido horario.
Se debe poder seleccionar el caracter que dibujara el triangulo y el lado. Cada caracter aparecera
con un retraso de 100 milisegundos. Debera validar que al ingresar el lado del de cualquiera de los
triangulos debera ser entre 5 y 100.

MENU
1. Triangulo Equilatero Horario
2. Triangulo Rectangulo Horario
Ingrese la opcion:

El punto de inicio del recorrido del caracter si simboliza con un punto negro en los ejemplos.
Si ingresa la opcion 1 aparecera:
Ingrese el lado: 8
Ingrese el caracter: -

Si ingresa la opcion 2 aparecera:
Ingrese el lado1: 5
Ingrese el lado2: 9
Ingrese el caracter: -

Para ello creara una clase llamada triangulo_equilatero y otra llamada triangulo_rectangulo.
Puede usar: Console::SetCursorPosition(coordX, coordY);
*/

#include <cmath>
#include <iostream>
#include <Windows.h> // for Sleep function
#include <conio.h> // for _getch function
#include <string>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false; // Set the cursor visibility to false
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void showCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true; // Set the cursor visibility to true
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void clearScreen()
{
    system("cls");
}

void menu()
{
    clearScreen();
    cout << "***** MENU *****" << endl;
    cout << "1. Dibuja un triangulo equilatero" << endl;
    cout << "2. Dibuja un triangulo rectangulo" << endl;
    cout << "3. Salir" << endl;
}

class TRIANGULOEQUILATERO
{
private:
    int lado;
    string caracter;

public:
    TRIANGULOEQUILATERO(int l, string c) : lado(l), caracter(c)
    {
    }

    void dibujar()
    {
        clearScreen();
        hideCursor();

        int x = 0, y = lado - 1;

        // Dibuja el lado izquierdo del triangulo
        for (int i = 0; i < lado; i++)
        {
            gotoxy(x + i, y - i);
            cout << caracter;
            Sleep(100);
        }

        // Dibuja el lado derecho del triangulo
        for (int i = 1; i < lado - 1; i++)
        {
            gotoxy(x + lado - 1 + i, y - y + i);
            cout << caracter;
            Sleep(100);
        }

        // Dibuja la base del triangulo
        for (int i = 1; i < lado * 2; i++)
        {
            int posX = x + lado * 2 - i;
            if (posX % 2 == 0 && posX >= 0)
            {
                gotoxy(posX, y);
                cout << caracter;
                Sleep(100);
            }
        }
    }
};

class TRIANGULORECTANGULO
{
private:
    int lado1; // alto
    int lado2; // base
    string caracter;

public:
    TRIANGULORECTANGULO(int l1, int l2, string c) : lado1(l1), lado2(l2), caracter(c)
    {
    }

    void dibujar()
    {
        clearScreen();
        hideCursor();

        int x = 0, y = lado1 - 1;

        // Dibuja el lado izquierdo del triangulo
        for (int i = 0; i < lado1; i++)
        {
            gotoxy(x, y - i);
            cout << caracter;
            Sleep(100);
        }

        // Dibuja la hipotenusa del triangulo
        // Calculamos cuantos pasos hacia la derecha para cada fila
        double pasoHorizontal = static_cast<double>(lado2 - 1) / (lado1 - 1);

        for (int i = 1; i < lado1 - 1; i++)
        {
            int xActual = round(pasoHorizontal * i); // redondear al entero mas cercano
            int yActual = i;
            gotoxy(xActual, yActual);
            cout << caracter;
            Sleep(100);
        }

        // Dibuja la base del triangulo
        for (int i = lado2 - 1; i >= 0; i--)
        {
            gotoxy(i, lado1 - 1);
            cout << caracter;
            Sleep(100);
        }
    }
};

int main()
{
    const int MIN_LADO = 5;
    const int MAX_LADO = 100;

    int opcion;
    do
    {
        menu();
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 3)
        {
            cout << "Opcion no valida. Intenta de nuevo." << endl;
            Sleep(2000);
            continue;
        }

        switch (opcion)
        {
        case 1:
            {
                int lado;
                string caracter;

                cout << "Introduce el lado del triangulo (" << MIN_LADO << "-" << MAX_LADO << "): ";
                cin >> lado;

                if (lado < MIN_LADO || lado > MAX_LADO)
                {
                    cout << "El lado debe estar entre " << MIN_LADO << " y " << MAX_LADO << "." << endl;
                    Sleep(2000);
                    continue;
                }

                cout << "Introduce el caracter: ";
                cin >> caracter;

                TRIANGULOEQUILATERO triangulo(lado, caracter);
                triangulo.dibujar();
                cout << endl << "Presiona cualquier tecla para continuar..." << endl;
                _getch();
                break;
            }
        case 2:
            {
                int lado1, lado2;
                string caracter;

                cout << "Introduce el lado1 (alto) del triangulo (" << MIN_LADO << "-" << MAX_LADO << "): ";
                cin >> lado1;

                if (lado1 < MIN_LADO || lado1 > MAX_LADO)
                {
                    cout << "El lado1 debe estar entre " << MIN_LADO << " y " << MAX_LADO << "." << endl;
                    Sleep(2000);
                    continue;
                }

                cout << "Introduce el lado2 (base) del triangulo (" << MIN_LADO << "-" << MAX_LADO << "): ";
                cin >> lado2;

                if (lado2 < MIN_LADO || lado2 > MAX_LADO)
                {
                    cout << "El lado2 debe estar entre " << MIN_LADO << " y " << MAX_LADO << "." << endl;
                    Sleep(2000);
                    continue;
                }

                cout << "Introduce el caracter: ";
                cin >> caracter;

                TRIANGULORECTANGULO triangulo(lado1, lado2, caracter);
                triangulo.dibujar();
                cout << endl << "Presiona cualquier tecla para continuar..." << endl;
                _getch();
                break;
            }
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intenta de nuevo." << endl;
            Sleep(2000);
        }
    }
    while (opcion != 3);

    return 0;
}
