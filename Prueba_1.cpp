// Prueba_1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>

class Arreglo {
public:
    int n;
    int max;
    char* v;

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
            while (i >= 0 && v[i] > c) {
                v[i + 1] = v[i];
                i--;
            }
            i++;
            v[i] = c;
        }
    }

    int Modificar(char c) {
		int R = Buscar(c);

        if (R == -1) {
            return R;
        }
		std::cout << "Ingrese el nuevo caracter: ";
        std::cin >> v[R];
		return R;
    }

	int Buscar(char c) {

        for (int i = 0; i <= n; i++)
        {
            if (v[i] == c) {
				return i; 			
                i++;
            }
			return -1;
        }
	}

	int Eliminar(char c) {
		int R = Buscar(c);
		if (R == -1) {
			return R;
		}
		for (int i = R; i < n-1;) {
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

	void Inicializar() {
		n = -1;
		std::cout << "Arreglo Inicializado\n";
	}

	int BusquedaBinaria(char c) {
		int inicio = 0;
		int fin = n;
		int ciclos = 0;
        int cv = BuscarValor(c);
		int medv;
		int medio;

		while (inicio <= fin) {
			ciclos++;
			medio = (inicio + fin) / 2;
			medv = BuscarValor(v[medio]);
			if (v[medio] == c) {
				return medio;
			}
			else if (medv < cv) {
				inicio = medio + 1;
			}
			else {
				fin = medio - 1;
			}
		}
		return -1;
	})

	int BuscarValor(char c) {
		switch (c) {
		case 'A':
			return 1;
			break;
		case 'a':
			return 2;
			break;
		case 'B':
			return 3;
			break;
		case 'b':
			return 4;
			break;
		case 'C':
			return 5;
			break;
		case 'c':
			return 6;
			break;
		case 'D':
			return 7;
			break;
		case 'd':
			return 8;
			break;
		case 'E':
			return 9;
			break;
		case 'e':
			return 10;
			break;
		case 'F':
			return 11;
			break;
		case 'f':
			return 12;
			break;
		case 'G':
			return 13;
			break;
		case 'g':
			return 14;
			break;
		case 'H':
			return 15;
			break;
		case 'h':
			return 16;
			break;
		case 'I':
			return 17;
			break;
		case 'i':
			return 18;
			break;
		case 'J':
			return 19;
			break;
		case 'j':
			return 20;
			break;
		case 'K':
			return 21;
			break;
		case 'k':
			return 22;
			break;
		case 'L':
			return 23;
			break;
		case 'l':
			return 24;
			break;
		case 'M':
			return 25;
			break;
		case 'm':
			return 26;
			break;
		case 'N':
			return 27;
			break;
		case 'n':
			return 28;
			break;
		case 'O':
			return 29;
			break;
		case 'o':
			return 30;
			break;
		case 'P':
			return 31;
			break;
		case 'p':
			return 32;
			break;
		case 'Q':
			return 33;
			break;
		case 'q':
			return 34;
			break;
		case 'R':
			return 35;
			break;
		case 'r':
			return 36;
			break;
		case 'S':
			return 37;
			break;
		case 's':
			return 38;
			break;
		case 'T':
			return 39;
			break;
		case 't':
			return 40;
			break;
		case 'U':
			return 41;
			break;
		case 'u':
			return 42;
			break;
		case 'V':
			return 43;
			break;
		case 'v':
			return 44;
			break;
		case 'W':
			return 45;
			break;
		case 'w':
			return 46;
			break;
		case 'X':
			return 47;
			break;
		case 'x':
			return 48;
			break;
		case 'Y':
			return 49;
			break;
		case 'y':
			return 50;
			break;
		case 'Z':
			return 51;
			break;
		case 'z':
			return 52;
			break;
		default:
			std::cout << "Caracter no valido, Pruebe con el abecedario (AaBbCc...XxYyZz)\n";
			return -1;
			break;
	}
};


int main()
{
	Arreglo arreglo(20);
	int opcion = 0;
	bool continuar = true;

	std::cout << "Bienvenido al programa de manejo de arreglos ordenados con Chars!!\n";
	do {
		std::cout << "Menu de opciones:\n";
		std::cout << "1) Borrar arreglo\n";
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
			arreglo.Inicializar();
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
				
			}
			
			break;
		case 7:
            std::cout << "Materia: Estructuras de Datos\n";
            std::cout << "Integrantes:\n";
            std::cout << "Nombre: Carlos Emmanuel Renteria Najera, Matrícula: idk\n";
            std::cout << "Nombre: Jorge Emilio Sanchez Sifuentes, Matrícula: 25420014\n";
			std::cout << "Nombre: Isabella, Matrícula: idk\n";
            break;
        case 8:
			std::cout << "Saliendo del programa... Gracias!!!\n";
            continuar = false;
            break;
        default:
            std::cout<<"Opción inválida. Intente de nuevo.\n";
        }
    } while (continuar);
}


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
