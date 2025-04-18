//
// Created by c0d3r on 17/04/2025.
//

/**
*Gráficos y Recorridos
Se requiere que realice un programa orientado a objetos donde podrá seleccionar: dibujar un
triángulo equilátero o un triángulo rectángulo en sentido horario.
Se debe poder seleccionar el carácter que dibujará el triángulo y el lado. Cada carácter aparecerá
con un retraso de 100 milisegundos. Deberá validar que al ingresar el lado del de cualquiera de los
triángulos deberá ser entre 5 y 100.

MENU
1. Triángulo Equilátero Horario
2. Triángulo Rectángulo Horario
Ingrese la opción:

El punto de inicio del recorrido del carácter si simboliza con un punto negro en los ejemplos.
Si ingresa la opción 1 aparecerá:
Ingrese el lado: 8
Ingrese el carácter: -

Si ingresa la opción 2 aparecerá:
Ingrese el lado1: 5
Ingrese el lado2: 9
Ingrese el carácter: -

Para ello creará una clase llamada triangulo_equilatero y otra llamada triangulo_rectangulo.
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
    cout << "1. Dibuja un triángulo equilátero" << endl;
    cout << "2. Dibuja un triángulo rectángulo" << endl;
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

        // Dibuja el lado izquierdo del triángulo
        for (int i = 0; i < lado; i++)
        {
            gotoxy(x + i, y - i);
            cout << caracter;
            Sleep(100);
        }

        // Dibuja el lado derecho del triángulo
        for (int i = 1; i < lado - 1; i++)
        {
            gotoxy(x + lado - 1 + i, y - y + i);
            cout << caracter;
            Sleep(100);
        }

        // Dibuja la base del triángulo
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

        // 1. Lado izquierdo (subida)
        for (int i = 0; i < lado1; i++)
        {
            gotoxy(x, y - i);
            cout << caracter;
            Sleep(100);
        }

        // 2. Hipotenusa (progresiva hacia la derecha, subiendo escalonado)
        // Calculamos cuántos pasos hacia la derecha para cada fila
        double pasoHorizontal = static_cast<double>(lado2 - 1) / (lado1 - 1);

        for (int i = 1; i < lado1 - 1; i++)
        {
            int xActual = round(pasoHorizontal * i); // redondear al entero más cercano
            int yActual = i;
            gotoxy(xActual, yActual);
            cout << caracter;
            Sleep(100);
        }

        // 3. Base (horizontal)
        for (int i = lado2 - 1; i >= 0; i--)
        {
            if (i % 2 == 0)
            {
                // muestra cada dos para formar línea recta
                gotoxy(i, lado1 - 1);
                cout << caracter;
                Sleep(100);
            }
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
        cout << "Elige una opción: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 2)
        {
            cout << "Opción no válida. Intenta de nuevo." << endl;
            Sleep(2000);
            continue;
        }

        switch (opcion)
        {
        case 1:
            {
                int lado;
                string caracter;

                cout << "Introduce el lado del triángulo (" << MIN_LADO << "-" << MAX_LADO << "): ";
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

                cout << "Introduce el lado1 (alto) del triángulo (" << MIN_LADO << "-" << MAX_LADO << "): ";
                cin >> lado1;

                if (lado1 < MIN_LADO || lado1 > MAX_LADO)
                {
                    cout << "El lado1 debe estar entre " << MIN_LADO << " y " << MAX_LADO << "." << endl;
                    Sleep(2000);
                    continue;
                }

                cout << "Introduce el lado2 (base) del triángulo (" << MIN_LADO << "-" << MAX_LADO << "): ";
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
        default:
            cout << "Opción no válida. Intenta de nuevo." << endl;
            Sleep(2000);
        }
    }
    while (opcion != 2);

    return 0;
}
