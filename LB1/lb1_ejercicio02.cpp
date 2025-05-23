#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Autor
{
private:
	int idAutor;
	string nombre;
	string nacionalidad;

public:
	Autor(int id, const string& nombre, const string& nacionalidad)
		: idAutor(id), nombre(nombre), nacionalidad(nacionalidad)
	{
	}

	int getIdAutor() const { return idAutor; }
	string getNombre() const { return nombre; }
	string getNacionalidad() const { return nacionalidad; }

	void mostrarInfoAutor() const
	{
		cout << "ID Autor: " << idAutor << ", Nombre: " << nombre << ", Nacionalidad: " << nacionalidad << endl;
	}
};

class Publicacion
{
private:
	string editorial;
	int anio;
	string isbn;

public:
	Publicacion(const string& editorial, int anio, const string& isbn)
		: editorial(editorial), anio(anio), isbn(isbn)
	{
	}

	string getEditorial() const { return editorial; }
	int getanio() const { return anio; }
	string getIsbn() const { return isbn; }

	void setEditorial(const string& editorial) { this->editorial = editorial; }
	void setanio(int anio) { this->anio = anio; }
	void setIsbn(const string& isbn) { this->isbn = isbn; }

	void mostrarInfoPublicacion() const
	{
		cout << "Editorial: " << editorial << ", anio: " << anio << ", ISBN: " << isbn << endl;
	}
};

class Libro
{
private:
	int idLibro;
	string titulo;
	Autor* autor; // Asociacin
	Publicacion publicacion; // Composicion

public:
	Libro(int id, const string& titulo, const string& editorial, int anio, const string& isbn)
		: idLibro(id), titulo(titulo), publicacion(editorial, anio, isbn), autor(nullptr)
	{
	}

	int getIdLibro() const { return idLibro; }
	string getTitulo() const { return titulo; }

	void asignarAutor(Autor* nuevoAutor) { autor = nuevoAutor; }
	Publicacion& obtenerPublicacion() { return publicacion; }

	void mostrarInfoLibro() const
	{
		cout << "ID Libro: " << idLibro << ", Titulo: " << titulo << endl;
		if (autor)
		{
			cout << "Autor: ";
			autor->mostrarInfoAutor();
		}
		else
		{
			cout << "Autor: No asignado" << endl;
		}
	}
};

class CatalogoLibros
{
private:
	vector<Libro> libros;

public:
	void agregarLibro(const Libro& libro)
	{
		libros.push_back(libro);
	}

	void eliminarLibroPorId(int id)
	{
		for (auto it = libros.begin(); it != libros.end(); ++it)
		{
			if (it->getIdLibro() == id)
			{
				libros.erase(it);
				return;
			}
		}
		// Si no se encuentra el libro mostramos un mensaje
		cout << "Libro con ID " << id << " no encontrado." << endl;
	}
	void listarLibros() const
	{
		cout << "Lista de libros:" << endl;
		for (const auto& libro : libros)
		{
			libro.mostrarInfoLibro();
			cout << "------------------------" << endl;
		}
	}
	Libro* buscarLibroPorId(int id)
	{
		for (auto& libro : libros)
		{
			if (libro.getIdLibro() == id)
			{
				return &libro;
			}
		}
		return nullptr;
	}
};

void mostrarMenu()
{
	cout << "Menu de opciones:" << endl;
	cout << "1. Agregar libro" << endl;
	cout << "2. Eliminar libro por ID" << endl;
	cout << "3. Listar libros" << endl;
	cout << "4. Buscar libro por ID" << endl;
	cout << "5. Salir" << endl;
}

int main()
{
	CatalogoLibros catalogo;
	int opcion;

	do
	{
		mostrarMenu();
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
			int idLibro, anio;
			string titulo, editorial, isbn, nombreAutor, nacionalidadAutor;
			int idAutor;

			cout << "Ingrese ID del libro: ";
			cin >> idLibro;
			cin.ignore(); // Limpiar el buffer de entrada
			cout << "Ingrese titulo del libro: ";
			getline(cin, titulo);
			cout << "Ingrese editorial: ";
			getline(cin, editorial);
			cout << "Ingrese anio de publicacion: ";
			cin >> anio;
			cout << "Ingrese ISBN: ";
			cin.ignore();
			getline(cin, isbn);

			cout << "Ingrese ID del autor: ";
			cin >> idAutor;
			cin.ignore();
			cout << "Ingrese nombre del autor: ";
			getline(cin, nombreAutor);
			cout << "Ingrese nacionalidad del autor: ";
			getline(cin, nacionalidadAutor);

			// Crear autor y libro
			Autor* nuevoAutor = new Autor(idAutor, nombreAutor, nacionalidadAutor);

			Libro nuevoLibro(idLibro, titulo, editorial, anio, isbn);

			nuevoLibro.asignarAutor(nuevoAutor);
			catalogo.agregarLibro(nuevoLibro);
			break;
		}
		case 2:
		{
			int idEliminar;
			cout << "Ingrese ID del libro a eliminar: ";
			cin >> idEliminar;
			catalogo.eliminarLibroPorId(idEliminar);
			break;
		}
		case 3:
		{
			catalogo.listarLibros();
			break;
		}
		case 4:
		{
			int idBuscar;
			cout << "Ingrese ID del libro a buscar: ";
			cin >> idBuscar;
			Libro* libroEncontrado = catalogo.buscarLibroPorId(idBuscar);
			if (libroEncontrado)
				libroEncontrado->mostrarInfoLibro();
			else
				cout << "Libro con ID " << idBuscar << " no encontrado." << endl;
			break;
		}
		case 5:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
			break;
		}
	} while (opcion != 5);

	return 0;
}
