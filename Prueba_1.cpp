// Prueba_1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
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
};