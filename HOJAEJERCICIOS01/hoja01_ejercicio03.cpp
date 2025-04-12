//
// Created by c0d3r on 12/04/2025.
//
#include <iostream>
#include <string>
using namespace std;

/**
*Crea una clase llamada Cuenta que tendrá los siguientes atributos: titular y cantidad (puede tener
decimales).
El titular será obligatorio y la cantidad es opcional.
Considerara dos constructores que cumpla lo anterior.
Crear sus métodos get, set
Tendrá dos comportamientos especiales:
• ingresar(double cantidad): se ingresa una cantidad a la cuenta, si la cantidad introducida es
negativa, no se hará nada.
retirar(double cantidad): se retira una cantidad a la cuenta, si restando la cantidad actual a la
que nos pasan es negativa, la cantidad de la cuenta será cero.
*/

class CUENTA
{
private:
    string titular;
    double cantidad;

public:
    // Constructor por defecto
    CUENTA(string t)
    {
        titular = t;
        cantidad = 0.0; // Cantidad por defecto
    }

    // Constructor con parámetros
    CUENTA(string t, double c)
    {
        titular = t;
        cantidad = c; // Cantidad inicial
    }

    // Métodos get
    string getTitular()
    {
        return titular;
    }

    double getCantidad()
    {
        return cantidad;
    }

    // Métodos set
    void setTitular(string t)
    {
        titular = t;
    }

    void setCantidad(double c)
    {
        cantidad = c;
    }

    // Metodo para ingresar cantidad
    void ingresar(double c)
    {
        if (c > 0)
        {
            cantidad += c; // Solo se suma si la cantidad es positiva
            cout << "Se ha ingresado: " << c << endl;
        }
        else
        {
            cout << "No se puede ingresar una cantidad negativa." << endl;
        }
    }

    // Metodo para retirar cantidad
    void retirar(double c)
    {
        if (cantidad - c < 0)
        {
            cantidad = 0; // Si la cantidad es negativa, se establece a cero
            cout << "La cantidad se ha establecido a cero." << endl;
        }
        else
        {
            cantidad -= c; // Resta la cantidad
            cout << "Se ha retirado: " << c << endl;
        }
    }

    // Metodo para mostrar información de la cuenta
    string toString()
    {
        return "Titular: " + titular + "\nCantidad: " + to_string(cantidad);
    }
};

int main()
{
    // Crear un objeto de la clase CUENTA
    CUENTA cuenta1("Nico", 1000.0);

    // Mostrar información inicial
    cout << cuenta1.toString() << endl;

    // Ingresar una cantidad
    cuenta1.ingresar(500.0);
    cout << cuenta1.toString() << endl;

    // Intentar ingresar una cantidad negativa
    cuenta1.ingresar(-200.0);
    cout << cuenta1.toString() << endl;

    // Retirar una cantidad
    cuenta1.retirar(300.0);
    cout << cuenta1.toString() << endl;

    // Intentar retirar una cantidad que excede el saldo
    cuenta1.retirar(1500.0);
    cout << cuenta1.toString() << endl;

    return 0;
}
