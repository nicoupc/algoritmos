//
// Created by c0d3r on 17/04/2025.
//

/**
*CARLITOS Y CAROLINA
Carlitos y Carolina son los socios de una empresa importante que se dedica a la venta de
productos de belleza; un amigo les comentó que podrías ayudarle a implementar un sistema
de registro de ventas bajo el paradigma de programación orientado a objetos.
En una reunión le comenta las reglas del negocio.
- De los productos se deben registrar: CodProducto, Nombre, Tipo, Marca, Cantidad y
Precio,
- De los clientes se deben registrar: DNI, Nombres.
- De las compras se registran: IdCompra, Fecha, cliente que compra, productos que
compra.
- Se asume que un cliente puede comprar varios productos, pero una compra pertenece
solamente a un cliente único.
- Los productos van registrándose cada vez que llega de los mayoristas.
- Los clientes se van registrando cuando intenta comprar o aun no compran pero pueden
ser registrados.
- Un producto puede ser comprado varias veces porque hay una cantidad del mismo
producto.
- Las compras se van registrando conforme de cada cliente que compra uno o varios
productos.
Se le pide que: Diseñe el diagrama de clases, sus relaciones (asociación, agregación,
composición)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PRODUCTO
{
private:
    int CodProducto;
    string Nombre;
    string Tipo;
    string Marca;
    int Cantidad;
    float Precio;

public:
    PRODUCTO(int cod, string nom, string tip, string mar, int cant, float pre)
        : CodProducto(cod), Nombre(nom), Tipo(tip), Marca(mar), Cantidad(cant), Precio(pre)
    {
    }

    void mostrar()
    {
        cout << "Codigo: " << CodProducto << ", Nombre: " << Nombre << ", Tipo: " << Tipo
            << ", Marca: " << Marca << ", Cantidad: " << Cantidad << ", Precio: " << Precio
            << endl;
    }
};

class CLIENTE
{
private:
    string DNI;
    string Nombres;

public:
    CLIENTE(string dni, string nom)
        : DNI(dni), Nombres(nom)
    {
    }

    void mostrar()
    {
        cout << "DNI: " << DNI << ", Nombres: " << Nombres << endl;
    }
};

class COMPRA
{
private:
    int IdCompra;
    string Fecha;
    CLIENTE cliente;
    vector<PRODUCTO> productos;

public:
    COMPRA(int id, string fecha, CLIENTE cli)
        : IdCompra(id), Fecha(fecha), cliente(cli)
    {
    }

    void agregarProducto(PRODUCTO prod)
    {
        productos.push_back(prod);
    }

    void mostrar()
    {
        cout << "IdCompra: " << IdCompra << ", Fecha: " << Fecha << endl;
        cliente.mostrar();
        cout << "Productos comprados:" << endl;
        for (auto& prod : productos)
        {
            prod.mostrar();
        }
    }
};

int main()
{
    // Crear productos
    PRODUCTO producto1(11111, "Shampoo", "Higiene", "MarcaA", 10, 15.50);
    PRODUCTO producto2(22222, "Jabon", "Higiene", "MarcaB", 20, 5.75);
    PRODUCTO producto3(33333, "Crema", "Cuidado", "MarcaC", 15, 25.00);

    // Crear cliente
    CLIENTE cliente1("12345678", "Juan Perez");
    CLIENTE cliente2("87654321", "Maria Lopez");

    // Crear compra
    COMPRA compra1(1, "2025-04-17", cliente1);
    compra1.agregarProducto(producto1);
    compra1.agregarProducto(producto2);
    compra1.agregarProducto(producto3);
    compra1.mostrar();

    COMPRA compra2(2, "2025-04-18", cliente2);
    compra2.agregarProducto(producto1);
    compra2.agregarProducto(producto3);
    compra2.mostrar();

    return 0;
}
