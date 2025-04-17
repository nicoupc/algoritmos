//
// Created by c0d3r on 15/04/2025.
//

/**
*CASO SISTEMA ALMACEN DE LA EMPRESA FLOWER FUL
La empresa FlowerFull S.A.C, es una empresa nueva dedicada la venta de productos 100% naturales, esta
empresa ha tenido un incremento de ventas de manera exponencial en estos últimos meses a raiz
del Covid-19, ya que las personas compran estos productos para tener mejores defensas en su
organismo, por esta razon la empresa necesita tener un control de inventario  de los productos y
necesitan un sistema de almacen para administrar productos y sus proveedores.
El gerente de la empresa confia en la habilidad que tiene usted para desarrollar programas orientada a
objetos (POO), por lo cual le solicita que desarrolle un sistema de almacen.
Reglas del negocio:
• De los proveedores se debe registrar: Ruc, Razon social, Categoria, direccion y telefono.
• De los productos se deben registrar: IdProducto, Nombre, Tipo (polvo o liquido), Cantidad,
categoria (A,B y C), año, Precio y proveedor
• Los metodos que debe tener la clase quedaran bajo su criterio, dependiendo de la necesidad
del problema.
El programa debe realizar lo siguiente:
1) Los productos van registrandose cada vez que llega de los proveedores.
2) Diseñe el diagrama de clases indicando la cardinalidad y sus relaciones
3) Implemente las clases acorde al diseño, use .hpp y CPP
4) Haciendo uso de recolector de objetos realice las implementaciones necesarias para
almacenar la informacion de “N” productos.
5) Modificar datos de un determinado producto.
6) Mostrar todos los productos de la categoria A cuyo proveedor sea Natura.
7) Eliminar todos los productos del proveedor Herbalife.
8) Eliminar todos los productos que esten vencidos (los productos inferiores a este año 2020)
9) Integracion y funcionamiento de pruebas mediante reportes
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Para usar remove_if
using namespace std;

class PROVEEDOR
{
private:
    string ruc;
    string razonSocial;
    string categoria;
    string direccion;
    string telefono;

public:
    // Constructor por defecto
    PROVEEDOR()
    {
        ruc = "";
        razonSocial = "";
        categoria = "";
        direccion = "";
        telefono = "";
    }

    // Constructor con parametros
    PROVEEDOR(string ruc, string razonSocial, string categoria, string direccion, string telefono)
    {
        this->ruc = ruc;
        this->razonSocial = razonSocial;
        this->categoria = categoria;
        this->direccion = direccion;
        this->telefono = telefono;
    }

    // Metodos de acceso (getters y setters)
    string getRuc() { return ruc; }
    void setRuc(string r) { ruc = r; }

    string getRazonSocial() { return razonSocial; }
    void setRazonSocial(string rs) { razonSocial = rs; }

    string getCategoria() { return categoria; }
    void setCategoria(string c) { categoria = c; }

    string getDireccion() { return direccion; }
    void setDireccion(string d) { direccion = d; }

    string getTelefono() { return telefono; }
    void setTelefono(string t) { telefono = t; }

    // Metodo para mostrar informacion del proveedor
    string toString()
    {
        return "RUC: " + ruc + "\nRazon Social: " + razonSocial + "\nCategoria: " + categoria +
            "\nDireccion: " + direccion + "\nTelefono: " + telefono;
    }
};

class PRODUCTO
{
private:
    string idProducto;
    string nombre;
    string tipo; // "polvo" o "liquido"
    int cantidad;
    char categoria; // 'A', 'B' o 'C'
    int anio;
    float precio;
    PROVEEDOR proveedor;

public:
    // Constructor por defecto
    PRODUCTO()
    {
        idProducto = "";
        nombre = "";
        tipo = "";
        cantidad = 0;
        categoria = ' ';
        anio = 0;
        precio = 0.0;
    }

    // Constructor con parametros
    PRODUCTO(string idProducto, string nombre, string tipo, int cantidad, char categoria, int anio, float precio,
             PROVEEDOR proveedor)
    {
        this->idProducto = idProducto;
        this->nombre = nombre;
        this->tipo = tipo;
        this->cantidad = cantidad;
        this->categoria = categoria;
        this->anio = anio;
        this->precio = precio;
        this->proveedor = proveedor;
    }

    // Metodos de acceso (getters y setters)
    string getIdProducto() { return idProducto; }
    void setIdProducto(string id) { idProducto = id; }

    string getNombre() { return nombre; }
    void setNombre(string nom) { nombre = nom; }

    string getTipo() { return tipo; }
    void setTipo(string t) { tipo = t; }

    int getCantidad() { return cantidad; }
    void setCantidad(int cant) { cantidad = cant; }

    char getCategoria() { return categoria; }
    void setCategoria(char cat) { categoria = cat; }

    int getAnio() { return anio; }
    void setAnio(int a) { anio = a; }

    float getPrecio() { return precio; }
    void setPrecio(float pre) { precio = pre; }

    PROVEEDOR getProveedor() { return proveedor; }
    void setProveedor(PROVEEDOR prov) { proveedor = prov; }

    // Metodo para mostrar informacion del producto
    string toString()
    {
        return "ID Producto: " + idProducto + "\nNombre: " + nombre + "\nTipo: " + tipo +
            "\nCantidad: " + to_string(cantidad) + "\nCategoria: " + categoria +
            "\nAnio: " + to_string(anio) + "\nPrecio: " + to_string(precio) +
            "\nProveedor: " + proveedor.toString();
    }
};

void mostrarMenu()
{
    cout << "\n****** MENU ******\n";
    cout << "1. Insertar producto\n";
    cout << "2. Insertar proveedor\n";
    cout << "3. Modificar producto\n";
    cout << "4. Eliminar productos vencidos\n";
    cout << "5. Reportes (mostrar todos los productos en stock con sus respectivos proveedores)\n";
    cout << "6. Salir\n";
}

void insertarProducto(vector<PRODUCTO>& productos)
{
    string idProducto, nombre, tipo;
    int cantidad, anio;
    char categoriaProducto;
    float precio;
    PROVEEDOR proveedor;

    cout << "\nIngrese el ID del producto: ";
    cin >> idProducto;

    cout << "Ingrese el nombre del producto (e.g. Proteina, Creatina, etc.): ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombre); // Permite ingresar nombres con espacios

    cout << "Ingrese el tipo (polvo/liquido): ";
    cin >> tipo;

    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    cout << "Ingrese la categoria (A/B/C): ";
    cin >> categoriaProducto;

    cout << "Ingrese el anio: ";
    cin >> anio;

    cout << "Ingrese el precio: ";
    cin >> precio;

    // Ingresar datos del proveedor
    string ruc, razonSocial, categoriaProveedor, direccion, telefono;
    cout << "Ingrese el RUC del proveedor: ";
    cin >> ruc;

    cout << "Ingrese la razon social del proveedor (e.g. Natura, Herbalife, etc.): ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, razonSocial); // Permite ingresar nombres con espacios

    cout << "Ingrese la categoria del proveedor (e.g. Suplementos, Vitaminas, etc.): ";
    cin >> categoriaProveedor;

    cout << "Ingrese la direccion del proveedor (e.g. Av. Los Olivos 123): ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, direccion); // Permite ingresar nombres con espacios

    cout << "Ingrese el telefono del proveedor: ";
    cin >> telefono;

    proveedor = PROVEEDOR(ruc, razonSocial, categoriaProveedor, direccion, telefono);

    PRODUCTO nuevoProducto(idProducto, nombre, tipo, cantidad, categoriaProducto, anio, precio, proveedor);

    productos.push_back(nuevoProducto);
}

void mostrarProveedores(vector<PROVEEDOR>& proveedores)
{
    cout << "\n****** PROVEEDORES REGISTRADOS ******\n";
    for (auto& proveedor : proveedores)
    {
        cout << proveedor.toString() << endl;
        cout << endl;
    }
}

void mostrarProductos(vector<PRODUCTO>& productos)
{
    cout << "\n****** PRODUCTOS REGISTRADOS ******\n";
    for (auto& producto : productos)
    {
        cout << producto.toString() << endl;
        cout << endl;
    }
}

void modificarProducto(vector<PRODUCTO>& productos)
{
    mostrarProductos(productos); // Mostrar productos registrados

    string idProducto;
    cout << "Ingrese el ID del producto a modificar: ";
    cin >> idProducto;

    for (auto& producto : productos)
    {
        if (producto.getIdProducto() == idProducto)
        {
            string nombre, tipo;
            int cantidad, anio;
            char categoriaProducto;
            float precio;
            PROVEEDOR proveedor;

            cout << "\nIngrese el nuevo nombre: ";
            cin.ignore(); // Limpiar el buffer de entrada
            getline(cin, nombre); // Permite ingresar nombres con espacios

            cout << "Ingrese el nuevo tipo (polvo/liquido): ";
            cin >> tipo;

            cout << "Ingrese la nueva cantidad: ";
            cin >> cantidad;

            cout << "Ingrese la nueva categoria (A/B/C): ";
            cin >> categoriaProducto;

            cout << "Ingrese el nuevo anio: ";
            cin >> anio;

            cout << "Ingrese el nuevo precio: ";
            cin >> precio;

            // Ingresar datos del proveedor
            string ruc, razonSocial, categoriaProveedor, direccion, telefono;
            cout << "Ingrese el RUC del proveedor: ";
            cin >> ruc;

            cout << "Ingrese la razon social del proveedor: ";
            cin.ignore(); // Limpiar el buffer de entrada
            getline(cin, razonSocial); // Permite ingresar nombres con espacios

            cout << "Ingrese la categoria del proveedor: ";
            cin >> categoriaProveedor;

            cout << "Ingrese la direccion del proveedor: ";
            cin.ignore(); // Limpiar el buffer de entrada
            getline(cin, direccion); // Permite ingresar nombres con espacios

            cout << "Ingrese el telefono del proveedor: ";
            cin >> telefono;
            proveedor = PROVEEDOR(ruc, razonSocial, categoriaProveedor, direccion, telefono);

            // Modificar el producto
            producto.setNombre(nombre);
            producto.setTipo(tipo);
            producto.setCantidad(cantidad);
            producto.setCategoria(categoriaProducto);
            producto.setAnio(anio);
            producto.setPrecio(precio);
            producto.setProveedor(proveedor);
            cout << "Producto modificado correctamente.\n";
            cout << producto.toString() << endl;
        }
        else
        {
            cout << "Producto no encontrado.\n";
        }
    }
}

void eliminarProductosVencidos(vector<PRODUCTO>& productos)
{
    int anioActual = 2020; // Cambiar al anio actual
    productos.erase(remove_if(productos.begin(), productos.end(),
                              [anioActual](PRODUCTO& producto)
                              {
                                  return producto.getAnio() < anioActual;
                              }),
                    productos.end());
    cout << "Productos vencidos eliminados correctamente.\n";
}

void eliminarProductosPorProveedor(vector<PRODUCTO>& productos, string proveedorRuc)
{
    productos.erase(remove_if(productos.begin(), productos.end(),
                              [proveedorRuc](PRODUCTO& producto)
                              {
                                  return producto.getProveedor().getRuc() == proveedorRuc;
                              }),
                    productos.end());
    cout << "Productos del proveedor " << proveedorRuc << " eliminados correctamente.\n";
}

void mostrarProductosPorProveedor(vector<PRODUCTO>& productos, string proveedorRazonSocial)
{
    cout << "\n****** PRODUCTOS DEL PROVEEDOR " << proveedorRazonSocial << " ******\n";
    for (auto& producto : productos)
    {
        if (producto.getProveedor().getRazonSocial() == proveedorRazonSocial)
        {
            cout << producto.toString() << endl;
            cout << endl;
        }
    }
}

void mostrarProductosPorCategoria(vector<PRODUCTO>& productos, char categoria)
{
    cout << "\n****** PRODUCTOS DE CATEGORIA " << categoria << " ******\n";
    for (auto& producto : productos)
    {
        if (producto.getCategoria() == categoria)
        {
            cout << producto.toString() << endl;
            cout << endl;
        }
    }
}

int main()
{
    vector<PRODUCTO> productos;
    vector<PROVEEDOR> proveedores;

    int opcion;
    do
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            insertarProducto(productos);
            break;
        case 2:
            mostrarProveedores(proveedores);
            break;
        case 3:
            modificarProducto(productos);
            break;
        case 4:
            eliminarProductosVencidos(productos);
            break;
        case 5:
            mostrarProductos(productos);
            break;
        case 6:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
            break;
        }
    }
    while (opcion != 6);

    return 0;
}
