#include <stdio.h>
#include "funcion.h"

int main(int argc, char *argv[]) {
    Libro libros[MAX_LIBROS];
    int contador = 0;
    int opcion;

    do {
        mostrarMenu();
        opcion = leerOpcionMenu(); // Leer y validar la opción del menú

        switch (opcion) {
            case 1:
                registrarLibro(libros, &contador);
                break;
            case 2:
                mostrarLibros(libros, contador);
                break;
            case 3:
                buscarLibro(libros, contador);
                break;
            case 4:
                actualizarEstado(libros, contador);
                break;
            case 5:
                eliminarLibro(libros, &contador);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione una opcion del 1 al 6.\n");
        }
    } while (opcion != 6);

    return 0;
}