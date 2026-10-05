// Prueba_1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <cctype>
using namespace std;

class Arreglo {
public:
	int n;
	int max;
	char* v;

	Arreglo() {
	}

	Arreglo(int mx) {
		this->max = mx;
		v = new char[max];
		n = -1;
	}

	void Insertar(char c) {

		if (n == max - 1) {
			std::cout << "El arreglo esta lleno\n";
		}
		else {
			int i = n;
			while (i >= 0 && tolower(v[i]) > tolower(c) || (tolower(v[i]) == tolower(c) &&	v[i] > c)) { 
				v[i + 1] = v[i];
				i--;
			}
			i++;
			v[i] = c;
			n++;
		}
	}

	int Modificar(char c, char newChar) { //isa
		int R = Eliminar(c);
		if (R != -1) {
			Insertar(newChar);
		}
		return R;
	}

	int Buscar(char c) { //isa

		for (int i = 0; i <= n; i++)
		{
			if (v[i] == c) {
				return i;
			}
			if (tolower(v[i]) > tolower(c) || (tolower(v[i]) == tolower(c) && v[i] > c))
			{
				return - 1;
			}
		}
		return -1;
	}

	int Eliminar(char c) {
		int R = Buscar(c);
		if (R == -1) {
			return R;
		}
		for (int i = R; i <= n - 1;) {
			v[i] = v[i + 1];
			i++;
		}
		n--;
		return R;
	}

	void Mostrar() {
		for (int i = 0; i <= n; i++) {
			std::cout << v[i] << " ";
		}
		std::cout << "\n";
	}

	int BusquedaBinaria(char c) {
		int inicio = 0;
		int fin = n;
		int medio;

		while (inicio <= fin) {
			medio = (inicio + fin) / 2;
			if (v[medio] == c) {
				return medio;
			}
			else if (tolower(v[medio]) < tolower(c) || (tolower(v[medio]) == tolower(c) && v[medio] < c)) {
				inicio = medio + 1;
			}
			else {
				fin = medio - 1;
			} 
		}
		return -1;
	}

};


int main()
{
	Arreglo arreglo;
	int opcion = 0;
	bool continuar = true;

	std::cout << "Bienvenido al programa de manejo de arreglos ordenados con Chars!!\n";
	do {
		std::cout << "Menu de opciones:\n";
		std::cout << "1) Inicializar/Borrar arreglo\n";
		std::cout << "2) Mostrar arreglo\n";
		std::cout << "3) Buscar\n";
		std::cout << "4) Insertar\n";
		std::cout << "5) Eliminar\n";
		std::cout << "6) Modificar\n";
		std::cout << "7) Créditos\n";
		std::cout << "8) Salir\n";
		std::cout << "Seleccione una opción: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "quieres inicializar o borrar el arreglo? \n";
			cout << "1) Inicializar\n";
			cout << "2) Borrar\n";
			cout << "Seleccione una opción: ";
			int opcionBorrar;
			cin >> opcionBorrar;
			if (opcionBorrar == 1)
			{
				cout << "Ingrese el tamaño del arreglo: ";
				int tamano;
				cin >> tamano;
				arreglo = Arreglo(tamano);
			}
			else
			{
				if (opcionBorrar == 2)
				{
					arreglo.n = -1;
					break;
				}
				cout << "Opción inválida. Intente de nuevo.\n";
			}

			break;
		case 2:
			arreglo.Mostrar();
			break;
		case 3:
			int opcionBusqueda;
			char c;
			int pos;

			std::cout << "Ingrese la letra a buscar: ";
			std::cin >> c;
			std::cout << "Seleccione el tipo de búsqueda:\n";
			std::cout << "1) Búsqueda lineal\n";
			std::cout << "2) Búsqueda binaria\n";
			std::cin >> opcionBusqueda;
			switch (opcionBusqueda) {
			case 1:
				std::cout << "Búsqueda lineal seleccionada.\n";
				pos = arreglo.Buscar(c);
				break;
			case 2:
				std::cout << "Búsqueda binaria seleccionada.\n";
				pos = arreglo.BusquedaBinaria(c);
				break;
			}
			if (pos != -1) {
				std::cout << "La letra '" << c << "' se encuentra en la posición " << pos << "\n";
			}
			else {
				std::cout << "La letra '" << c << "' no se encuentra en el arreglo.\n";
			}
			break;
		case 4:
			char newChar;
			std::cout << "Ingrese la letra a insertar: ";
			std::cin >> newChar;
			arreglo.Insertar(newChar);
			break;
		case 5:
			if (arreglo.n == -1) {
				std::cout << "El arreglo está vacío. No se puede eliminar ningún elemento.\n";
				break;
			}
			else {
				char charToDelete;
				std::cout << "Ingrese la letra a eliminar: ";
				std::cin >> charToDelete;
				int deletedPos = arreglo.Eliminar(charToDelete);
				if (deletedPos != -1) {
					std::cout << "La letra '" << charToDelete << "' ha sido eliminada de la posición " << deletedPos << "\n";
				}
				else {
					std::cout << "La letra '" << charToDelete << "' no se encuentra en el arreglo.\n";
				}
			}

			break;
		case 6:
			if (arreglo.n == -1) {
				std::cout << "El arreglo está vacío. No se puede modificar ningún elemento.\n";
				break;
			}
			else {
				std::cout << "Ingrese la letra a modificar: ";
				char oldChar;
				std::cin >> oldChar;
				std::cout << "Ingrese la nueva letra: ";
				char letra_modified;
				std::cin >> letra_modified;
				int modifiedPos = arreglo.Modificar(oldChar, letra_modified);
				if (modifiedPos != -1) {
					std::cout << "La letra '" << oldChar << "' ha sido modificada por '" << letra_modified << "' en la posición " << modifiedPos << "\n";
				}
				else {
					std::cout << "La letra '" << oldChar << "' no se encuentra en el arreglo.\n";
				}
			}
			break;
		case 7:
			std::cout << "Materia: Estructuras de Datos\n";
			std::cout << "Integrantes:\n";
			std::cout << "Nombre: Carlos Emmanuel Renteria Najera, Matrícula: 25420033\n";
			std::cout << "Nombre: Jorge Emilio Sanchez Sifuentes, Matrícula: 25420014\n";
			std::cout << "Nombre: Isabella Guadalupe Salas Ramirez, Matrícula: 24170045\n";
			break;
		case 8:
			std::cout << "Saliendo del programa... Gracias!!!\n";
			continuar = false;
			break;
		default:
			std::cout << "Opción inválida. Intente de nuevo.\n";
		}
	} while (continuar);
};

//REGLASSSS -> Siempre que el programa acabe de mostrar los resultados de una operación deberá volver al menú de inicio segun si es visual o consola. y esta prohibido utilizar funciones de ordenamiento,
/*
    Inicializar / Borrar arreglo : Esta corre una rutina para dejar el arreglo sin caracteres.Aquí
    aplica un borrado lógico, pueden simplemente recorrer el apuntador de elementos “N”.
*/

/*
    Mostrar Arreglo: Muestra en pantalla todos los elementos que el arreglo tiene guardados, 
    no las 20 localidades forzosamente, solo las letras que el arreglo tiene guardadas.
*/

/*
    Buscar: Debe pedir una letra en especifico y la debe de buscar, si la encuentra debe decir 
    en que localidad la encontró y mostrarla, en caso de no encontrarla debe notificar que no 
    existe dicha letra en el arreglo. Al entrar en esta opción deberá dar a escoger si aplicar
    búsqueda lineal optimizada o la búsqueda binaria. Sin importar que búsqueda se eligió se 
    deberá mostrar al final además de la posición, el número de ciclos que tomo encontrarla.
*/


/*
    Insertar: Debe agregar el nuevo carácter al arreglo manteniendo el orden siempre y cuando 
    haya espacio, si no hay deberá decir que el arreglo está lleno y si pudo insertar deberá 
    indicar en qué localidad quedo insertada
*/

/*
    Eliminar: Deberá de pedir la letra a eliminar y si la encuentra deberá eliminarla, siempre 
    conservando el orden, al final deberá decir de que localidad se eliminó; si no la encuentra 
    deberá decir que no se pudo localizar y por lo tanto no procede la operación. Para la 
    implementación de este método deben llamar a algún método de búsqueda ya hecho.
*/

/*
    • Modificar: Deberá de pedir la letra a modificar y si la encuentra deberá hacer el reemplazo 
    por un nuevo carácter que el usuario indique, aquí es muy importante siempre conservar
    el orden, al final deberá decir en que localidad quedó guardada; si no la encuentra deberá 
    decir que no se pudo localizar y por lo tanto no procede la operación.
*/

/*
    • Créditos: Esta opción solo mostrará el nombre de la materia y el nombre y matrícula de 
    los integrantes del equipo.
*/

/*
    • Salir: Servirá para dar por concluido el programa
    eso mismo
*/
