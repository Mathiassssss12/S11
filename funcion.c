#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 10

typedef struct {
    char id[20]; // Cambiado de int a char[]
    char titulo[100];
    char autor[50];
    int anio;
    char estado[15];
} Libro;

void mostrarMenu() {
    printf("\n--- Menu Biblioteca ---\n");
    printf("1. Registrar libro\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro\n");
    printf("4. Actualizar estado de un libro\n");
    printf("5. Eliminar libro\n");
    printf("6. Salir\n");
}

int leerOpcionMenu() {
    int opcion;
    printf("Seleccione una opcion: ");
    while (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6) {
        printf("Opcion no valida. Por favor, ingrese un numero entre 1 y 6: ");
        fflush(stdin); // Limpiar el buffer de entrada
    }
    return opcion;
}

// Función para eliminar el salto de línea de una cadena
void eliminarSaltoLinea(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '\n') {
            cadena[i] = '\0'; // Reemplaza el salto de línea con el carácter nulo
            break;
        }
    }
}

void registrarLibro(Libro *libros, int *contador) {
    if (*contador >= MAX_LIBROS) {
        printf("No se pueden registrar mas libros.\n");
        return;
    }

    Libro nuevoLibro;
    printf("Ingrese ID del libro: ");
    fflush(stdin);
    fgets(nuevoLibro.id, 20, stdin);
    eliminarSaltoLinea(nuevoLibro.id);

    // Validar ID unico
    for (int i = 0; i < *contador; i++) {
        if (strcmp(libros[i].id, nuevoLibro.id) == 0) {
            printf("El ID ya existe. Intente nuevamente.\n");
            return;
        }
    }

    printf("Ingrese titulo del libro: ");
    fflush(stdin);
    fgets(nuevoLibro.titulo, 100, stdin);
    eliminarSaltoLinea(nuevoLibro.titulo);

    printf("Ingrese autor del libro: ");
    fflush(stdin);
    fgets(nuevoLibro.autor, 50, stdin);
    eliminarSaltoLinea(nuevoLibro.autor);

    printf("Ingrese anio de publicacion: ");
    scanf("%d", &nuevoLibro.anio);

    strcpy(nuevoLibro.estado, "Disponible");

    libros[*contador] = nuevoLibro;
    (*contador)++;
    printf("Libro registrado con exito.\n");
}

void mostrarLibros(Libro *libros, int contador) {
    if (contador == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n%-20s %-30s %-20s %-10s %-15s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    for (int i = 0; i < contador; i++) {
        printf("%-20s %-30s %-20s %-10d %-15s\n", libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
    }
}

void buscarLibro(Libro *libros, int contador) {
    if (contador == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    int opcion;
    printf("Buscar por:\n1. ID\n2. Titulo\nSeleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        char id[20];
        printf("Ingrese ID del libro: ");
        fflush(stdin);
        fgets(id, 20, stdin);
        eliminarSaltoLinea(id);

        for (int i = 0; i < contador; i++) {
            if (strcmp(libros[i].id, id) == 0) {
                printf("ID: %s\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
    } else if (opcion == 2) {
        char titulo[100];
        printf("Ingrese titulo del libro: ");
        fflush(stdin);
        fgets(titulo, 100, stdin);
        eliminarSaltoLinea(titulo);

        for (int i = 0; i < contador; i++) {
            if (strcmp(libros[i].titulo, titulo) == 0) {
                printf("ID: %s\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
                return;
            }
        }
        printf("Libro no encontrado.\n");
    } else {
        printf("Opcion no valida.\n");
    }
}

void actualizarEstado(Libro *libros, int contador) {
    if (contador == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    char id[20];
    printf("Ingrese ID del libro: ");
    fflush(stdin);
    fgets(id, 20, stdin);
    eliminarSaltoLinea(id);

    for (int i = 0; i < contador; i++) {
        if (strcmp(libros[i].id, id) == 0) {
            printf("El estado actual del libro es: %s\n", libros[i].estado);
            printf("Desea cambiar el estado? (1 para si, 0 para no): ");
            int opcion;
            while (scanf("%d", &opcion) != 1 || (opcion != 0 && opcion != 1)) {
                printf("Opcion no valida. Ingrese 1 para si o 0 para no: ");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
            }

            if (opcion == 1) {
                if (strcmp(libros[i].estado, "Disponible") == 0) {
                    strcpy(libros[i].estado, "Prestado");
                } else {
                    strcpy(libros[i].estado, "Disponible");
                }
                printf("Estado actualizado con exito. Nuevo estado: %s\n", libros[i].estado);
            } else {
                printf("El estado no ha sido cambiado.\n");
            }
            return;
        }
    }
    printf("Libro no encontrado.\n");
}
void eliminarLibro(Libro *libros, int *contador) {
    if (*contador == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    char id[20];
    printf("Ingrese ID del libro a eliminar: ");
    fflush(stdin);
    fgets(id, 20, stdin);
    eliminarSaltoLinea(id);

    for (int i = 0; i < *contador; i++) {
        if (strcmp(libros[i].id, id) == 0) {
            for (int j = i; j < *contador - 1; j++) {
                libros[j] = libros[j + 1];
            }
            (*contador)--;
            printf("Libro eliminado con exito.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}