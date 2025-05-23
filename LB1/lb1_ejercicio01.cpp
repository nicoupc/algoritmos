#include <iostream>
#include <string>
using namespace std;

class Estudiante
{
private:
	int codigo;
	string nombre;
	double nota;

public:
	Estudiante() : codigo(0), nombre(""), nota(0.0) {} // Constructor por defecto
	Estudiante(int c, string n, double nt) : codigo(c), nombre(n), nota(nt) {}

	int getCodigo() const { return codigo; }
	string getNombre() const { return nombre; }
	double getNota() const { return nota; }

	void mostrarInformacion() const
	{
		cout << "Codigo: " << codigo << ", Nombre: " << nombre << ", Nota: " << nota << endl;
	}

	bool estaAprobado(double notaMinima) const
	{
		return nota >= notaMinima;
	}
};

class ListaEstudiantes
{
private:
	Estudiante lista[10]; // Arreglo de estudiantes
	int cantidadEstudiantes; // Cantidad de estudiantes registrados

public:
	ListaEstudiantes() : cantidadEstudiantes(0) {} // Constructor por defecto

	void agregarEstudiante(const Estudiante& estudiante)
	{
		if (cantidadEstudiantes < 10)
		{
			lista[cantidadEstudiantes] = estudiante;
			cantidadEstudiantes++;
		}
		else
		{
			cout << "No hay espacio para mas estudiantes" << endl;
		}
	}

	void listarEstudiantes() const
	{
		for (int i = 0; i < cantidadEstudiantes; i++)
		{
			lista[i].mostrarInformacion();
		}
	}

	void eliminarEstudiantePorCodigo(int codigo)
	{
		for (int i = 0; i < cantidadEstudiantes; i++)
		{
			if (lista[i].getCodigo() == codigo)
			{
				for (int j = i; j < cantidadEstudiantes - 1; j++)
				{
					lista[j] = lista[j + 1];
				}
				cantidadEstudiantes--;
				cout << "Estudiante con codigo " << codigo << " eliminado." << endl;
				return;
			}
		}
		cout << "Estudiante con codigo " << codigo << " no encontrado." << endl;
	}

	void reporteEstudiantesAprobados(double notaMinima) const
	{
		cout << "Reporte de estudiantes aprobados:" << endl;
		for (int i = 0; i < cantidadEstudiantes; i++)
		{
			if (lista[i].estaAprobado(notaMinima))
			{
				lista[i].mostrarInformacion();
			}
		}
	}
};

void mostrarMenu()
{
	cout << "Menu:" << endl;
	cout << "1. Agregar estudiante" << endl;
	cout << "2. Listar estudiantes" << endl;
	cout << "3. Eliminar estudiante por codigo" << endl;
	cout << "4. Reporte de estudiantes aprobados" << endl;
	cout << "5. Salir" << endl;
}

int main()
{
	ListaEstudiantes lista;
	int codigo;
	string nombre;
	double nota, notaMinima;
	int opcion;

	do
	{
		mostrarMenu();
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		cin.ignore(); // Limpiar el buffer de entrada
		switch (opcion)
		{
		case 1:
			cout << "Ingrese codigo: ";
			cin >> codigo;
			cout << "Ingrese nombre: ";
			cin.ignore();
			getline(cin, nombre);
			cout << "Ingrese nota: ";
			cin >> nota;
			lista.agregarEstudiante(Estudiante(codigo, nombre, nota));
			break;
		case 2:
			lista.listarEstudiantes();
			break;
		case 3:
			cout << "Ingrese codigo del estudiante a eliminar: ";
			cin >> codigo;
			lista.eliminarEstudiantePorCodigo(codigo);
			break;
		case 4:
			cout << "Ingrese nota minima para aprobar: ";
			cin >> notaMinima;
			lista.reporteEstudiantesAprobados(notaMinima);
			break;
		case 5:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	}
	while (opcion != 5);

	return 0;
}
